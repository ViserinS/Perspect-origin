#include<iostream>
#include"Date.h"
#include<math.h>
#include<string>
#include<vector>
using namespace std;
bool isLeap(int testYear) {
	if (testYear % 4 == 0 && testYear % 100 != 0)
		return true;
	if (testYear % 400 == 0)
		return true;
	return false;
}
void push_str_int(string& str, int num) {
	int temp = num;
	if (num == 0)
	{
		str.push_back('0');
	}
	vector<int> v;
	while (temp != 0) {
		int doc = temp % 10;
		v.push_back(doc);
		temp /= 10;
	}
	int len = v.size();
	for (int index = 0; index < len; index++)
	{
		str.push_back('0' + v[len - 1 - index]);
	}
}
void initial(string& str, int num, int s) {
	if (s == 4) {
		int count = 3;
		while (pow(10, count--) > num)
			str.push_back('0');
		push_str_int(str, num);
	}
	if (s == 2) {
		if (num < 10)
			str.push_back('0');
		push_str_int(str, num);
	}
}
int str_int(string& str) {
	int len = str.size();
	int count = 0;
	for (int index = 0; index < len; index++)
	{
		count += (str[index] - '0');
		if (index != len - 1)
			count *= 10;
	}
	return count;
}

bool valid(int y, int m, int d)
{
	if (y < 1000 || y > 9999)
	{  //cout<<y<<" "<<m<<" "<<d<<endl;
  //  cout<<"wrong"<<endl;
		return false;
	}
	bool flag = isLeap(y);
	int array1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int array2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (flag == false) {
		if (m > 0 && m < 13 && d <= array1[m - 1] && d > 0)
			return true;
		else
		{
			//    cout<<"wrong"<<endl;
			return false;
		}
	}
	else {
		if (m > 0 && m < 13 && d <= array2[m - 1] && d > 0)
			return true;
		else
			return false;

	}
}
Date::Date() {
	m_year = 0;
	m_month = 0;
	m_day = 0;
	m_hour = 0;
	m_minute = 0;
}
Date::Date(int t_y, int t_mo, int t_d, int t_h, int t_mi)
{
	m_year = t_y;
	m_month = t_mo;
	m_day = t_d;
	m_hour = t_h;
	m_minute = t_mi;
}
bool valid_str(const string& str)
{
	int len = str.size();
	if (len != 16)
		return false;
	if (str[4] != '-')
		return false;
	if (str[7] != '-')
		return false;
	if (str[10] != '/')
		return false;
	if (str[13] != ':')
		return false;
	//    cout<<"no"<<str<<endl;
	for (int index = 0; index < 4; index++)
	{
		if (str[index] < '0' || str[index] > '9')
			return false;
	}
	// cout<<"1no "<<str<<endl;
	for (int index = 5; index < 7; index++)
	{
		if (str[index] < '0' || str[index] > '9')
			return false;
	}
	//cout<<"2no "<<str<<endl;
	for (int index = 8; index < 10; index++)
	{
		if (str[index] < '0' || str[index] > '9')
			return false;
	}
	//cout<<"3no "<<str<<endl;
	for (int index = 11; index < 13; index++)
	{
		if (str[index] < '0' || str[index] > '9')
			return false;
	}
	//cout<<"4no "<<str<<endl;
	for (int index = 14; index < 16; index++)
	{
		if (str[index] < '0' || str[index] > '9')
			return false;
	}
	//  cout<<"5no "<<str<<endl;
	return true;
}
Date::Date(const string& data) {
	string str;
	if (valid_str(data) == false)
	{
		this->m_year = 0;
		this->m_month = 0;
		this->m_day = 0;
		this->m_hour = 0;
		this->m_minute = 0;

	}
	else {
		for (int index = 0; index < 4; index++)
			str.push_back(data[index]);
		m_year = str_int(str);
		str.clear();

		for (int index = 5; index <= 6; index++)
			str.push_back(data[index]);
		m_month = str_int(str);
		str.clear();

		for (int index = 8; index <= 9; index++)
			str.push_back(data[index]);
		m_day = str_int(str);
		str.clear();

		for (int index = 11; index <= 12; index++)
			str.push_back(data[index]);
		m_hour = str_int(str);
		str.clear();

		for (int index = 14; index <= 15; index++)
			str.push_back(data[index]);
		m_minute = str_int(str);
		str.clear();
	}
}

int Date::getYear(void) const
{
	return m_year;
}

void Date::setYear(const int t_y) {
	m_year = t_y;
}

int Date::getMonth(void) const
{
	return m_month;
}

void Date::setMonth(const int t_m)
{
	m_month = t_m;
}

int Date::getDay(void) const
{
	return m_day;
}

void Date::setDay(const int t_d)
{
	m_day = t_d;
}

int Date::getHour(void) const
{
	return m_hour;
}

void Date::setHour(const int t_h)
{
	m_hour = t_h;
}

int Date::getMinute(void) const
{
	return m_minute;
}

void Date::setMinute(const int t_m)
{
	m_minute = t_m;
}


bool Date::isValid(const Date& test)
{
	bool flag1 = valid(test.m_year, test.m_month, test.m_day);
	if (flag1 == false)
	{
		//    cout<<"year wronf"<<endl;
		return false;
	}
	if (test.m_hour < 0 || test.m_hour >= 24)
		return false;
	if (test.m_minute < 0 || test.m_minute >= 60)
		return false;
	return true;
}

Date Date::stringToDate(const string& str)
{
	bool flag = valid_str(str);
	if (flag == false)
	{
		//    string ptr = "0000-00-00/00:00";
		Date temp(0, 0, 0, 0, 0);
		return temp;
	}
	Date temp(str);
	return temp;
}

string Date::dateToString(const Date& data)
{
	if (data.isValid(data) == false)
	{
		string str = "0000-00-00/00:00";
		return str;
	}
	string str;
	initial(str, data.m_year, 4);
	str.push_back('-');
	initial(str, data.m_month, 2);
	str.push_back('-');
	initial(str, data.m_day, 2);
	str.push_back('/');
	initial(str, data.m_hour, 2);
	str.push_back(':');
	initial(str, data.m_minute, 2);
	return str;
}

Date& Date::operator=(const Date& other)
{
	m_year = other.m_year;
	m_month = other.m_month;
	m_day = other.m_day;
	m_hour = other.m_hour;
	m_minute = other.m_minute;
	return *this;
}

bool Date::operator==(const Date& other) const
{
	if (m_year != other.m_year || m_month != other.m_month)
		return false;
	if (m_day != other.m_day || m_hour != other.m_hour)
		return false;
	if (m_minute != other.m_minute)
		return false;
	return true;
}
bool Date::operator<(const Date& other) const
{
	if (m_year < other.m_year)
		return true;
	if (m_year > other.m_year)
		return false;

	if (m_month < other.m_month)
		return true;
	if (m_month > other.m_month)
		return false;

	if (m_day < other.m_day)
		return true;
	if (m_day > other.m_day)
		return false;

	if (m_hour < other.m_hour)
		return true;
	if (m_hour > other.m_hour)
		return false;

	if (m_minute < other.m_minute)
		return true;
	return false;
}

bool Date::operator>(const Date& other) const
{
	bool flag1 = (*this == other);
	bool flag2 = (*this < other);
	if (flag1 == false && flag2 == false)
		return true;
	return false;
}

bool Date::operator>=(const Date& other) const
{
	bool flag1 = (*this < other);
	if (flag1 == false)
		return true;
	return false;
}

bool Date::operator<=(const Date& other) const
{
	bool flag1 = (*this > other);
	if (flag1 == false)
		return true;
	return false;
}
