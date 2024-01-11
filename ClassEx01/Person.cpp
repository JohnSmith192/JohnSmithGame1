#include <iostream>
#include "Person.h"
#include "GameConst.h"

Person::Person(const string& Name, int Age, bool bMale)
{
	m_Name = Name;
	m_Age = Age;
	m_bMale = bMale;
}
Person::~Person()
{
	//Wait for Add
}
void Person::SetName(const string& Name)
{
	m_Name = Name;
}
void Person::SetAge(int Age)
{
	m_Age = Age;
}
void Person::SetMale(bool Male)
{
	m_bMale = Male;
}
void Person::InitSetStrength(bool bMale)
{
	if (bMale)
	{
		m_Strength = MALE_MAX_STRENGTH;
	}
	else
	{
		m_Strength = FEMALE_MAX_STRENGTH;
	}
}
void Person::InitSetMaxStrength(bool bMale)
{
	if (bMale)
	{
		m_MaxStrength = MALE_MAX_STRENGTH;
	}
	else
	{
		m_MaxStrength = FEMALE_MAX_STRENGTH;
	}
}
void Person::SetStrength(int strength)
{
	m_Strength = strength;
}
void Person::SetMaxStrength(int MaxStrength)
{
	m_MaxStrength = MaxStrength;
}

string Person::GetName()
{
	return m_Name;
}
int Person::GetAge()
{
	return m_Age;
}
bool Person::GetMale()
{
	return m_bMale;
}
int Person::GetStrength()
{
	return m_Strength;
}
int Person::GetMaxStrength()
{
	return m_MaxStrength;
}
void Person::CommandRun(int Speed)
{
	if (Speed < 0)
	{
		cout << "You can't run at a speed lower than 0 meters per second." << endl;
		return;
	}
	if (Speed == 0)
	{
		cout << "You are standing now." << endl;
		return;
	}
	if (Speed > 0)
	{
		if (Speed > 10)
		{
			cout << "Do you think you can run at that speed?" << endl;
			return;
		}
		if (Speed == 1)
		{
			cout << m_Name << " is running at a speed of " << Speed << " meter per second." << endl;
			m_Strength -= 2 * Speed;
			return;
		}
		cout << m_Name << " is running at a speed of " << Speed << " meters per second." << endl;
		m_Strength -= 2 * Speed;
		return;
	}
}
void Person::CommandJump(int Height)
{
	if (Height < 0)
	{
		cout << "You can't jump lower than 0 meters." << endl;
		return;
	}
	if (Height == 0)
	{
		cout << "Nothing happened." << endl;
		return;
	}
	if (Height > 0)
	{
		if (Height > 3)
		{
			cout << "Do you think you can jump that high?" << endl;
			return;
		}
		if (Height == 1)
		{
			cout << m_Name << " jumped " << Height << " meter high." << endl;
			m_Strength -= Height;
			return;
		}
		cout << m_Name << " jumped " << Height << " meters high." << endl;
		m_Strength -= Height;
		return;
	}
}
void Person::CommandEat(const string& Food)
{
	if (Food == "ygy")
	{
		cout << "Sharks are not tasted good..." << endl;
	}
	else
	{
		cout << "You are eating " << Food << "." << endl;
	}
}
void Person::CommandSleep(int Time)
{
	if (Time < 0)
	{
		cout << "You can't sleep for that time." << endl;
	}
	if (Time == 1)
	{
		cout << "You are sleeping for " << Time << " minute." << endl;
		m_Strength += Time / 5;
		return;
	}
	if (Time > 720 && Time <= 1440)
	{
		cout << "Don't sleep as the same time as Hong Muyang." << endl;
		return;
	}
	if (Time > 1440)
	{
		cout << "There are only 24 hours a day!" << endl;
		return;
	}
	m_Strength += Time / 5;
	cout << "You are sleeping for " << Time <<" minutes." << endl;
}
void Person::CommandRide(const string& Transportation)
{
	cout << "You are riding " << Transportation << "." << endl;
	m_Strength -= 10;
}