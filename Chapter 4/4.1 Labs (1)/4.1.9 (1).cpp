#include "stdafx.h"
#include <iostream>

using namespace std;

int GetSubjectsCount() {

	int subjectsCount;

	do {
		cout << "Enter subjects count: ";
		cin >> subjectsCount;
	} while (subjectsCount <= 0);

	return subjectsCount;
}

int **GetGrades(int subjectCount) {

	int** grades = new int*[subjectCount];
	int gradesCountInCourse;

	for (int i = 0; i < subjectCount; i++) {
		do {
			cout << "Enter count of grades and grades: ";
			cin >> gradesCountInCourse;
		} while (gradesCountInCourse > 5 || gradesCountInCourse < 1);

		grades[i] = new int[gradesCountInCourse + 1];

		for (int j = 0; j < gradesCountInCourse; j++) {
			do {
				cin >> grades[i][j];
			} while (grades[i][j] <= 0 || grades[i][j] >= 6);
			// to identify row length by last element
			grades[i][gradesCountInCourse] = -1;
		}
	}

	return grades;
}

double CalculateSubjectFinal(int *grades) {

	double gradesSum = 0;
	int gradesCount = 0;

	for (int j = 0; ; j++) {

		if (grades[j] == -1)
			break;

		gradesCount++;
		gradesSum += grades[j];
	}

	return gradesSum / gradesCount;
}

void ShowFinal(int **grades, int subjectsCount) {

	double currentSubjectFinal, subjectsFinalSum = 0;

	for (int i = 0; i < subjectsCount; i++) {

		currentSubjectFinal = CalculateSubjectFinal(grades[i]);
		subjectsFinalSum += currentSubjectFinal;

		cout.precision(2);
		cout << fixed << "Course " << i + 1 << ": final " << currentSubjectFinal << ", grades: ";

		for (int j = 0; ; j++) {
			// last element of row is -1
			if (grades[i][j] == -1)
				break;
			cout << grades[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "Overall final: " << subjectsFinalSum / subjectsCount << endl;
}

int main()
{
	int subjectsCount = GetSubjectsCount();
	int **grades = GetGrades(subjectsCount);
	ShowFinal(grades, subjectsCount);

	return 0;
}