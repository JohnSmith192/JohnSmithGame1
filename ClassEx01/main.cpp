#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Person.h"
#include "GameConst.h"
#include "Student.h"
using namespace std;

int main()
{
	//Enter personal info.
	Student t1;
	string name;
	string sage;
	int age = 0;
	string smale;
	int imale;
	bool male;
	cout << "Please enter your name:";
	cin >> name;
	do
	{
		cout << "Please enter your age:";
		cin >> sage;
		if (sage.size() > 3)
		{
			cout << "Do you think you can live for " << sage << " years?" << endl;
		}
		else
		{
			bool tf = false;
			for (int i = 0; i < sage.size(); i++)
			{
				if (sage[i] >= '0' && sage[i] <= '9')
				{
					tf = true;
				}
			}
			if (!tf)
			{
				cout << "you can only enter a number." << endl;
			}
			else
			{
				for (int i = 0; i < sage.size(); i++)
				{
					age += pow(10, i) * (int)(sage[sage.size() - i - 1] - '0');
				}
				break;
			}
		}
	} while (1);
	do
	{
		cout << "Please enter your gender(\"1\" is male, \"0\" is female):";
		cin >> smale;
		if (smale.size() != 1)
		{
			cout << "you can only enter a number with 1 or 0." << endl;
			continue;
		}
		if (smale[0] != '0' && smale[0] != '1')
		{
			cout << "you can only enter a number with 1 or 0." << endl;
			continue;
		}
		imale = (int)(smale[0] - '0');
		if (imale != 0 && imale != 1)
		{
			cout << "you can only enter a number with 1 or 0." << endl;
		}
		else
		{
			male = (bool)imale;
			break;
		}
	} while (1);

	Person p1(name, age, male);
	cout << "Your name is " << p1.GetName() << "." << endl;
	cout << "Your age is " << p1.GetAge() << "." << endl;
	if (p1.GetMale())
	{
		cout << "You are a boy." << endl;
		p1.InitSetMaxStrength(p1.GetMale());
		p1.InitSetStrength(p1.GetMale());
	}
	else
	{
		cout << "You are a girl." << endl;
		p1.InitSetMaxStrength(p1.GetMale());
		p1.InitSetStrength(p1.GetMale());
	}
	cout << "You have " << p1.GetStrength() << " points strength now." << endl;

	//Start game
	cout << "The game is starting. Pleas wait..." << endl;
	//Init
	vector<string> CommandList;
	vector<string> CommandUsage;
	CommandList.push_back("exit"); //0
	CommandList.push_back("help"); //1
	CommandList.push_back("run"); //2
	CommandList.push_back("jump"); //3
	CommandList.push_back("eat"); //4
	CommandList.push_back("sleep"); //5
	CommandList.push_back("ride"); //6
	CommandList.push_back("str"); //7
	CommandUsage.push_back("Quit the game."); //0
	CommandUsage.push_back("Show help."); //1
	CommandUsage.push_back("Let you run."); //2
	CommandUsage.push_back("Let you jump."); //3
	CommandUsage.push_back("Let you eat."); //4
	CommandUsage.push_back("Let you sleep."); //5
	CommandUsage.push_back("Let you ride."); //6
	CommandUsage.push_back("Show your strength. If you don't have enough strength points, you can't do anything."); //7
	//Finished Init
	cout << "The game start successfully!" << endl;
	cout << endl;
	cout << "You can enter \"exit\" to quit the game." << endl;
	cout << "Type \"help\" for help!" << endl;
	cout << "Happy Gaming!" << endl;
	//main logic
	while (1)
	{
		bool is_valid = false;
		string action;
		cin >> action;
		if (action == "cpp" || action == "c++")
		{
			is_valid = true;
			cout << "No one can be proficient in C Plus Plus!!!" << endl;
		}
		if (action == "exit")
		{
			is_valid = true;
			cout << "Closing game..." << endl;
			break;
		}
		if (action == "help")
		{
			is_valid = true;
			for (int i = 0; i < COMMAND_AMOUNT; i++)
			{
				cout << CommandList[i] << ": " << CommandUsage[i] << endl;
			}
		}
		if (action == "str")
		{
			is_valid = true;
			if (p1.GetStrength() == 1)
			{
				cout << "You have " << p1.GetStrength() << " point strength now." << endl;
			}
			else
			{
				cout << "You have " << p1.GetStrength() << " points strength now." << endl;
			}
			continue;
		}
		if (action == "sleep")
		{
			is_valid = true;
			int time;
			cout << "Please enter how long would you want to sleep:";
			cin >> time;
			p1.CommandSleep(time);
		}
		if (p1.GetStrength() == 0)
		{
			cout << "You are so tired that you don't have power to do anything. Maybe you can get some sleep?" << endl;
			continue;
		}
		if (action == "run")
		{
			is_valid = true;
			int speed;
			cout << "Please enter how fast would you want to run:";
			cin >> speed;
			p1.CommandRun(speed);
		}
		if (action == "jump")
		{
			is_valid = true;
			int height;
			cout << "Please enter how high would you want to jump:";
			cin >> height;
			p1.CommandJump(height);
		}
		if (action == "eat")
		{
			is_valid = true;
			string food;
			cout << "Please enter what food would you want to eat:";
			cin >> food;
			p1.CommandEat(food);
		}
		if (action == "ride")
		{
			is_valid = true;
			string transportation;
			cout << "Please enter what transportation would you want to ride:";
			cin >> transportation;
			p1.CommandRide(transportation);
		}

		if (p1.GetStrength() > p1.GetMaxStrength())
		{
			p1.SetStrength(p1.GetMaxStrength());
		}
		if(p1.GetStrength() < 0)
		{
			p1.SetStrength(0);
		}
		if (!is_valid)
		{
			cout << "Unknown command, type \"help\" for help!" << endl;
		}
	}
	cout << "See you next time!" << endl;
	system("pause");
	return 0;
}