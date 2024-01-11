#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person()
	{

	}
	Person(const string& Name, int Age, bool bMale);
	~Person();
	void SetName(const string& Name);
	void SetAge(int Age);
	void SetMale(bool Male);
	void InitSetStrength(bool bMale);
	void InitSetMaxStrength(bool bMale);
	void SetStrength(int strength);
	void SetMaxStrength(int MaxStrength);

	string GetName();
	int GetAge();
	bool GetMale();
	int GetStrength();
	int GetMaxStrength();

	void CommandRun(int Speed); //Speed is <Speed>m/s
	void CommandJump(int Height); //Height is <Height>cm
	void CommandEat(const string& Food); //Type of food
	void CommandSleep(int Time); //Time means this person will sleep <Time>minutes
	void CommandRide(const string& Transportation); //Type of Transportation
private:
	string m_Name;
	int m_Age;
	bool m_bMale;
	int m_Strength;
	int m_MaxStrength;
};

