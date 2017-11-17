#include <iostream>
using namespace std;
struct Date {
	int year;
	int month;
	int day;
};
bool isLeap(int year) {
	return year % 4 == 0;
	// The code you've inserted already
}
int monthLength(int year, int month) {
	// The code you've inserted already
	int dayCount;
	if (month == 2 && isLeap(year)) { dayCount = 29; }
	else if (month == 2 && !isLeap(year)) { dayCount = 28; }
	else if (month == 4 || month == 6 || month == 9 || month == 11) { dayCount = 30; }
	else { dayCount = 31; }
	return dayCount;
}
int dayOfYear(Date date) {
	int dayNumber = 0;
	for (int i = 1; i <= date.month - 1; i++) {

		dayNumber += monthLength(date.year, i);
	}
	dayNumber += date.day;
	return dayNumber;
	// Insert your code here

}
int daysBetween(Date d1, Date d2)
{
	int daysCount = 0;
	Date fullYear = { d1.year, 12, 31 };

	if (d1.year > d2.year || d1.year == d2.year && dayOfYear(d1) - dayOfYear(d2) > 0)
		return -1;

	for (int i = d1.year + 1; i < d2.year; i++) {
		fullYear.year = i;
		daysCount += dayOfYear(fullYear);
	}
	if (d1.year != d2.year)
		daysCount += dayOfYear(d2) + dayOfYear(fullYear) - dayOfYear(d1);
	else
		daysCount += dayOfYear(d2) - dayOfYear(d1);

	return daysCount;
}
int main(void) {
	Date since, till;

	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;

	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;

	cout << daysBetween(since, till) << endl;
	return 0;
}
