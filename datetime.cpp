<<<<<<< HEAD
#include<iostream>

int LocationOfSY(int year, int month, int day);

using namespace std;

class Datetime
{
public:
	Datetime();
	~Datetime();
	void setTime();
	void showTime();
	void showMoon();//ת��������

private:
	int year, month, day;
	int hour, minute, second;
    bool LunarLeap;//����ũ�������ж�
};

int main() {
	
	Datetime dt;
	dt.setTime();
	dt.showTime();
    dt.showMoon();

	return 0;
=======
#include <iostream>
class DateTime {
private:
  static int sth;
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  static void showTime();
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};

int DateTime::sth = 0;

int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt1.showTime();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  return 0;
>>>>>>> upstream/master
}

Datetime::Datetime()
{
<<<<<<< HEAD
	year = 0; month = 0; day = 0;
	hour = 0; minute = 0; second = 0;
    LunarLeap = false;
=======
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  sth = 11;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
  year = y; month = m; day = d;
  this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::DateTime(const DateTime &dt)
{
  year = dt.year; month = dt.month; day = dt.day;
  hour = dt.hour; minute = dt.minute; second = dt.second;
>>>>>>> upstream/master
}

Datetime::~Datetime()
{
<<<<<<< HEAD
}
void Datetime::showTime() {
	cout << year << "/" << month << "/" << day << " " 
		<< hour << ":" << minute << ":" << second << endl;
}
void Datetime::setTime() {
    cout << "�밴�������������ڣ��Կո�����" << endl;
    cin >> year >> month >> day;
    cout << "�밴ʱ��������ʱ�䣨�Կո������" << endl;
	cin >> hour >> minute >> second;
}

void Datetime::showMoon() {
	/**
	 * ǰ�᣺�����ũ����
	 * 1. ���ũ������(ũ�����е�λ���ݵõ�)�ڹ������λ�úͽ����ڹ������λ��
     *  =>����������ǰ��ũ����-1���ں���ũ����=������  
     *  =>�õ�������ũ�����λ��
	 * 2. �ȶ�ũ����Ĵ�С��λ���ݵõ�ũ���·ݺ����ڣ�ע��ũ������
	 */
     
    //ʹ�ñ���λ��¼ÿ������
    //0~4 ��5bit �����շ�
    //5~6 ��2bit �����·�
    //7~19 ��13bit 13���µĴ�С�����(��������£����λ��Ч)������Ϊ1,С��Ϊ0
    //20~23 ��4bit ��¼���µ��·ݣ����û������Ϊ0
    /***************************
     *  λ�������Ǻܶ������հ��� *
     ***************************/
    static const int BEGIN_YEAR = 1901;
    static const int NUMBER_YEAR = 199;
    static const unsigned int LUNAR_YEARS[199] = {
         0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,
         0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A, //1901-1910
         0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,
         0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754, //1911-1920
         0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,
         0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E, //1921-1930
         0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,
         0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48, //1931-1940 
         0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,
         0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51, //1941-1950
         0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,
         0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x7AD53C, //1951-1960
         0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,
         0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46, //1961-1970
         0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,
         0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50, //1971-1980
         0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,
         0x06D449,0x6ADA3D,0x0AB651,0x093746,0x5497BB, //1981-1990
         0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,
         0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645, //1991-2000
         0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,
         0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E, //2001-2010
         0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,
         0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x4A9739, //2011-2020
         0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,
         0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43, //2021-2030
         0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,
         0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C, //2031-2040
         0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,
         0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37, //2041-2050
         0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,
         0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42, //2051-2060
         0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,
         0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B, //2061-2070
         0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,
         0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6, //2071-2080
         0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,
         0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E, //2081-2090
         0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,
         0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5 //2091-2099 
    };//������Դ������

    Datetime Lunardt;
    Lunardt.year = year;
    Lunardt.month = 1;
    int year_index = year - BEGIN_YEAR;//�±꣬���ڶ���ũ����

    if (year <= BEGIN_YEAR || year > BEGIN_YEAR + NUMBER_YEAR) {
        cout << "����ת����Χ" << endl;
    }else{
        
        Datetime SpringFestival;
        SpringFestival.year = year;
        SpringFestival.month = (LUNAR_YEARS[year_index] & 0x60) >> 5;//��λ����������ũ����ĵ�5~6λ�õ������·�
        SpringFestival.day = (LUNAR_YEARS[year_index] & 0x1f);//����0~4λ�ó�����
        
        int Locationdt = LocationOfSY(year, month, day);//�����ڹ������λ��
        int LocationSF = LocationOfSY(SpringFestival.year, SpringFestival.month, SpringFestival.day);//�����ڹ������λ��
        int LocationLunardt = Locationdt - LocationSF + 1;//������ũ�����λ��
        
        if (Locationdt < LocationSF) {
            year_index--;
            Lunardt.year--;
            if (year_index < 0) cout << "����ת����Χ" << endl;
            SpringFestival.year--;
            SpringFestival.month = (LUNAR_YEARS[year_index] & 0x60) >> 5;
            SpringFestival.day = (LUNAR_YEARS[year_index] & 0x1f);
            LocationSF = LocationOfSY(SpringFestival.year, SpringFestival.month, SpringFestival.day);
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) LocationLunardt = 366 - LocationSF + Locationdt + 1;
            LocationLunardt = 365 - LocationSF + Locationdt + 1;
        }        
        
        for (; Lunardt.month <= 13; Lunardt.month++) {
            int dayOfmonth = 29;//ũ��С������
            if ((LUNAR_YEARS[year_index] >> (6 + Lunardt.month)) & 0x1/*ͨ����7~19λ�����жϴ�С��*/) dayOfmonth = 30; //ũ����������
            if (LocationLunardt <= dayOfmonth) {//��λ�ñ�����С�˳�ѭ��
                break;
            }
            else {
                LocationLunardt -= dayOfmonth;
            }
        }
        Lunardt.day = LocationLunardt;
    }

    int leapOfLunaryear = (LUNAR_YEARS[year_index] >> 20) & 0xf;//ͨ����20~23λ���ݵó������������£�������
    if (leapOfLunaryear > 0 && leapOfLunaryear < Lunardt.month) {
        Lunardt.month--;
        if (leapOfLunaryear == Lunardt.month) Lunardt.LunarLeap = true;
    }

    //������
    int TianGan = 0, DiZhi = 0;
    TianGan = (Lunardt.year - 1864) % 10;
    DiZhi = (Lunardt.year - 1864) % 12;
    switch (TianGan) {
        case 0: cout << "��"; break;
        case 1: cout << "��"; break;
        case 2: cout << "��"; break;
        case 3: cout << "��"; break;
        case 4: cout << "��"; break;
        case 5: cout << "��"; break;
        case 6: cout << "��"; break;
        case 7: cout << "��"; break;
        case 8: cout << "��"; break;
        case 9: cout << "��"; break;
    }
    switch (DiZhi) {
        case 0: cout << "��"; break;
        case 1: cout << "��"; break;
        case 2: cout << "��"; break;
        case 3: cout << "î"; break;
        case 4: cout << "��"; break;
        case 5: cout << "��"; break;
        case 6: cout << "��"; break;
        case 7: cout << "δ"; break;
        case 8: cout << "��"; break;
        case 9: cout << "��"; break;
        case 10: cout << "��"; break;
        case 11: cout << "��"; break;
    }
    cout << "��";
    
    if (Lunardt.LunarLeap) cout << "��";
    switch (Lunardt.month) {
        case 1: cout << "��"; break;
        case 2: cout << "��"; break;
        case 3: cout << "��"; break;
        case 4: cout << "��"; break;
        case 5: cout << "��"; break;
        case 6: cout << "��"; break;
        case 7: cout << "��"; break;
        case 8: cout << "��"; break;
        case 9: cout << "��"; break;
        case 10: cout << "ʮ"; break;
        case 11: cout << "��"; break;
        case 12: cout << "��"; break;
    }
    cout << "��";
    
    switch (Lunardt.day) {
        case 1: cout << "��һ" << endl; break;
        case 2: cout << "����" << endl; break;
        case 3: cout << "����" << endl; break;
        case 4: cout << "����" << endl; break;
        case 5: cout << "����" << endl; break;
        case 6: cout << "����" << endl; break;
        case 7: cout << "����" << endl; break;
        case 8: cout << "����" << endl; break;
        case 9: cout << "����" << endl; break;
        case 10: cout << "��ʮ" << endl; break;
        case 11: cout << "ʮһ" << endl; break;
        case 12: cout << "ʮ��" << endl; break;
        case 13: cout << "ʮ��" << endl; break;
        case 14: cout << "ʮ��" << endl; break;
        case 15: cout << "ʮ��" << endl; break;
        case 16: cout << "ʮ��" << endl; break;
        case 17: cout << "ʮ��" << endl; break;
        case 18: cout << "ʮ��" << endl; break;
        case 19: cout << "ʮ��" << endl; break;
        case 20: cout << "��ʮ" << endl; break;
        case 21: cout << "إһ" << endl; break;
        case 22: cout << "إ��" << endl; break;
        case 23: cout << "إ��" << endl; break;
        case 24: cout << "إ��" << endl; break;
        case 25: cout << "إ��" << endl; break;
        case 26: cout << "إ��" << endl; break;
        case 27: cout << "إ��" << endl; break;
        case 28: cout << "إ��" << endl; break;
        case 29: cout << "إ��" << endl; break;
        case 30: cout << "��ʮ" << endl; break;
    }//��ʮ�Ľ������ض������������д��
    
}

int LocationOfSY(int year, int month, int day) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        switch (month) {
            case 1: return day; break;
            case 2: return 31 + day; break;
            case 3: return 60 + day; break;
            case 4: return 91 + day; break;
            case 5: return 121 + day; break;
            case 6: return 152 + day; break;
            case 7: return 182 + day; break;
            case 8: return 213 + day; break;
            case 9: return 244 + day; break;
            case 10: return 274 + day; break;
            case 11: return 305 + day; break;
            case 12: return 335 + day; break;
        }
    }
    switch (month) {
        case 1: return day; break;
        case 2: return 31 + day; break;
        case 3: return 59 + day; break;
        case 4: return 90 + day; break;
        case 5: return 120 + day; break;
        case 6: return 151 + day; break;
        case 7: return 181 + day; break;
        case 8: return 212 + day; break;
        case 9: return 243 + day; break;
        case 10: return 273 + day; break;
        case 11: return 304 + day; break;
        case 12: return 334 + day; break;
    }
=======
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  std::cout << sth << std::endl;
>>>>>>> upstream/master
}
