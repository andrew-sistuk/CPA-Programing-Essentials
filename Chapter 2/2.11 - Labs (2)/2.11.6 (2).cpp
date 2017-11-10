#include <iostream>

using namespace std;

struct Time
{
	int hours;
	int minutes;
};

int main(void) {

	Time startTime, endTime, betweenTime;

	cout << "start time: " << endl;
	cin >> startTime.hours >> startTime.minutes;
	if (startTime.hours >= 24 || startTime.minutes > 60) {
		cout << "Start time is wrong" << endl;
		system("pause");
		return 0;
	}

	cout << "end time: " << endl;
	cin >> endTime.hours >> endTime.minutes;
	if (endTime.hours >= 24 || endTime.minutes > 60 || endTime.hours < startTime.hours) {
		cout << "End time is wrong" << endl;
		system("pause");
		return 0;
	}

	betweenTime.hours = endTime.hours - startTime.hours;
	if (endTime.minutes >= startTime.minutes) 
		betweenTime.minutes = endTime.minutes - startTime.minutes;
	else {
		betweenTime.hours--;
		betweenTime.minutes = endTime.minutes + 60 - startTime.minutes;
	}

	cout << endl << betweenTime.hours << ":" << betweenTime.minutes << endl; 

	return 0;
}