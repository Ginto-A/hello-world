#include <iostream>

using namespace std;
typedef struct _datetime DateTime;
typedef/*简化声明*/ struct _datetime
{
	int year, month, day;
	int hour, minute, second;
	void showtime();
	void initTime();
} DateTime;

int main() {

	DateTime Today, Today1;
	Today.initTime();
	Today.showtime();
	Today1.initTime();
	Today1.showtime();

	return 0;
}
// 
void DateTime::showtime() {
	cout << "当前时间为	" << year << "/" << month << "/" << day
		<< "	" << hour << ":" << minute << ":" << second << endl;
}
void DateTime::initTime() {
	day = 13; month = 3; year = 2020;
	second = 55; hour = 10; minute = 34;
}
