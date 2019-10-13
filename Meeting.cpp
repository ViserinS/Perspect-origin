#include"Meeting.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
Meeting::Meeting(const string& t_sp, const vector<string>& t_p, const Date& t_st, const Date& t_e, const string& t_t)
{
	m_sponsor = t_sp;
	int len = t_p.size();
	for (int index = 0; index < len; index++)
		m_participators.push_back(t_p[index]);
	m_startDate = t_st;
	m_endDate = t_e;
	m_title = t_t;
}

Meeting::Meeting(const Meeting& t_m)
{
	m_sponsor = t_m.m_sponsor;
	int len = t_m.m_participators.size();
	for (int index = 0; index < len; index++)
		m_participators.push_back(t_m.m_participators[index]);
	m_startDate = t_m.m_startDate;
	m_endDate = t_m.m_endDate;
	m_title = t_m.m_title;
}

string Meeting::getSponsor(void) const
{
	return m_sponsor;
}
void Meeting::setSponsor(const string& str)
{
	m_sponsor = str;
}
vector<string> Meeting::getParticipator(void) const
{
	//  vector<string> str;
	  //int len = m_participators.size();
	  //for(int index = 0 ; index < len ; index++)
		// str.push_back(m_participators[index]);
	  //return str;
	return m_participators;
}
void Meeting::setParticipator(const std::vector<std::string>& t_pa)
{
	m_participators.clear();
	int len = t_pa.size();
	for (int index = 0; index < len; index++)
		m_participators.push_back(t_pa[index]);
}
void Meeting::addParticipator(const string& str)
{
	m_participators.push_back(str);
}

void Meeting::removeParticipator(const string& str)
{
	vector<string>::iterator it, itor;
	for (it = m_participators.begin(); it != m_participators.end();)
	{
		if (*it == str)
		{
			itor = it;
			it = m_participators.erase(itor);
		}
		else
			it++;
	}
}

Date Meeting::getStartDate(void) const
{
	return m_startDate;
}

void Meeting::setStartDate(const Date& str)
{
	m_startDate = str;
}

Date Meeting::getEndDate(void) const
{
	return m_endDate;
}

void Meeting::setEndDate(const Date& str)
{
	m_endDate = str;
}


string Meeting::getTitle(void) const
{
	return m_title;
}

void Meeting::setTitle(const string& str)
{
	m_title = str;
}

bool Meeting::isParticipator(const string& str) const
{
	int len = m_participators.size();
	for (int index = 0; index < len; index++)
	{
		if (m_participators[index] == str)
			return true;
	}
	return false;
}

