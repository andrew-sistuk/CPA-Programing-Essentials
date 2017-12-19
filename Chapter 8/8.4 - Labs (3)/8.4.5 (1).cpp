#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class FSM {
public:
	enum State { Start = 1, Second, Third, Fourth, Fifth, Stop };
	FSM() {
		currentState = Start;
		visitedStates.push_back(Start);
	}
	State CurrentState();
	friend istream& operator >> (istream& is, FSM& fsm);
	friend ostream& operator<< (ostream& os, FSM& fsm);
private:
	State currentState;
	vector<State> visitedStates;
};

FSM::State FSM::CurrentState() {
	return this->currentState;
}

istream& operator >> (istream& is, FSM& fsm) {
	int value;
	is >> value;

	switch (fsm.currentState) {
	case FSM::Start:
		if (value < 5)
			fsm.currentState = FSM::Third;
		else fsm.currentState = FSM::Second;
		break;
	case FSM::Second:
		if (value < 5)
			fsm.currentState = FSM::Third;
		else fsm.currentState = FSM::Fifth;
		break;
	case FSM::Third:
		if (value < 5)
			fsm.currentState = FSM::Second;
		else fsm.currentState = FSM::Fourth;
		break;
	case FSM::Fourth:
		if (value < 5)
			fsm.currentState = FSM::Stop;
		else fsm.currentState = FSM::Fifth;
		break;
	case FSM::Fifth:
		if (value < 5)
			fsm.currentState = FSM::Stop;
		else fsm.currentState = FSM::Fourth;
		break;
	case FSM::Stop:
		throw runtime_error("FSM is on stop state!");
		break;
	}
	fsm.visitedStates.push_back(fsm.currentState);

	return is;
}

ostream& operator<< (ostream& os, FSM& fsm) {
	os << "States visited:" << endl;

	for (int i = 0; i < fsm.visitedStates.size() - 1; ++i)
		os << fsm.visitedStates[i] << (fsm.visitedStates[i] == FSM::Start ? "(Start)" : "") << ", ";

	os << fsm.visitedStates.back() << (fsm.visitedStates.back() == FSM::Stop ? "(Stop)" : "") << endl;

	return os;
}

int main()
{
	FSM fsm = FSM();
	while (fsm.CurrentState() != FSM::Stop)
	{
		cout << "Current state of fsm is: " << fsm.CurrentState() << endl << "Enter number for change state: ";
		cin >> fsm;
		cout << endl;
	}

	cout << "Stop state reached" << endl << fsm;
	return 0;
}