#include <iostream>
using namespace std;
bool isLeap(int year) {
        return year % 4 == 0;
        // The code you've inserted already
}
    int monthLength(int year, int month) {
        int dayCount;
        if (month == 2 && isLeap(year)) { dayCount = 29; }
        else if (month == 2 && !isLeap(year)) { dayCount = 28; }
        else if (month == 4 || month == 6 || month == 9 || month == 11) { dayCount = 30; }
        else  { dayCount = 31; }
        return dayCount;
        // Insert a new code here
}
int main(void) {
        for (int yr = 2000; yr < 2002; yr++) {
                for (int mo = 1; mo <= 12; mo++)
                        cout << monthLength(yr, mo) << " ";
                cout << endl;
        }
return 0;
}

