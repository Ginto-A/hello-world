//#include <cstdio>
#include <iostream>

using namespace std;

typedef struct _DateTime
{
	int year, month, day;
	int hour, minute, second;
};
static void showtime(_DateTime today) {
	cout << "当前时间为	" << today.year << "/" << today.month << "/" << today.day
		<< "	" << today.hour << ":" << today.minute << ":" << today.second << endl;
}
static void initTime(_DateTime* today) {
	today->day = 13; today->month = 3; today->year = 2020;
	today->second = 55; today->hour = 10; today->minute = 34;
}

int main() {
	
	_DateTime today;
	initTime(&today);
	showtime(today);

	return 0;
}