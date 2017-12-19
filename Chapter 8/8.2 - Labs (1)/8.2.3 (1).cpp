#include "string"
#include "iostream"
using namespace std;
class date {
	
	
public:
	int day, month, year;
	enum weekday { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
	enum month { january, february, march, april, may, june, july, august, september, oktober,november, december };
	string DayWeek (int da) {
		
		switch (da) {
		case SUNDAY:   return "SUNDAY";
		case MONDAY:   return"MONDAY";
		case TUESDAY: return "TUESDAY"; 
		case WEDNESDAY: return "WEDNESDAY"; 
		case THURSDAY:  return "THURSDAY";
		case FRIDAY:    return "FRIDAY";
		case SATURDAY:  return"SATURDAY";
		default:        return "Somewhere inside the depths of time...";
		}
		return "";
	}
	string Month(int da) {

		switch (da) {
		case january:   return "january";
		case february:   return"february";
		case march: return "march";
		case april: return "april";
		case may:  return "may";
		case june:    return "june";
		case july:  return"july";
		case august:  return"august";
		case september:  return"september";
		case oktober:  return"oktober";
		case november:  return"november";
		case december:  return"december";
		default:        return "Somewhere inside the depths of time...";
		}
		return "";
	}
	date(int d = 1, int m = 1, int y = 1970) {
		if (y < 1970)
			throw string("data must be more 1.1.1970");
		if(m<1||m>12)
			throw string("month in range [1....12]");
		if (d<1 || d>31)
			throw string("day in range [1....31]");
		day = d;
		month = m;
		year = y;
		
	}
	bool isLeap(int year) {
		if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
			return true;
		return false;
	}
	int monthLength(int year, int month) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: return 31;
		case 2:
			if (isLeap(year))
				return 29;
			return 28;
		case 4:
		case 6:
		case 9:
		case 11: return 30;
		}
	}
	int dayOfYear(date q) {
		// Insert your code here
		int d = 0;
		for (int i = 1; i<q.month; ++i) {
			d += monthLength(q.year, i);
		}
		return d + q.day;
	}
	int daysBetween(date date1, date date2) {
		int dif = dayOfYear(date2) - dayOfYear(date1);
		if (dif<0)
			return -1;
		return dif + 365 * (date2.year - date1.year) + (date2.year - date1.year) / 4;
	}
	int operator-(date w) {
		
		int dif = dayOfYear(*this) - dayOfYear(w);
		if (dif<0)
			return -1;
		for (int i = 0; i < (this->year - w.year); ++i) {
			if (isLeap(w.year + i))
				dif += 366;
			else
				dif += 365;
		}
		return dif;
	}
};
int main()
{
	date q(13, 3, 2016);
	date w(1, 1, 1970);
	//date w(13, 3, 2010);
	int qq= q - w;
	cout <<q.day<< " " << q.Month(q.month)<<" "<<q.year << " - " << q.DayWeek(qq%7 +3)<<" - "<< qq <<" days since 1st January 1970"<<endl;
    return 0;
}