#include"User.h"
//#include"Date.hpp"
#include<iostream>
#include<string>
using namespace std;

User::User(const string& t_name, const string& t_pass, const string& t_e, const string& t_p)
{
	m_name = t_name;
	m_password = t_pass;
	m_email = t_e;
	m_phone = t_p;
}

User::User(const User& other)
{
	m_name = other.m_name;
	m_password = other.m_password;
	m_email = other.m_email;
	m_phone = other.m_phone;
}

string User::getName() const
{
	return m_name;
}
void User::setName(const string& str)
{
	m_name = str;
}

string User::getPassword() const
{
	return m_password;
}

void User::setPassword(const string& str)
{
	m_password = str;
}

string User::getEmail() const
{
	return m_email;
}

void User::setEmail(const string& str)
{
	m_email = str;
}

string User::getPhone() const
{
	return m_phone;
}

void User::setPhone(const string& str)
{
	m_phone = str;
}
