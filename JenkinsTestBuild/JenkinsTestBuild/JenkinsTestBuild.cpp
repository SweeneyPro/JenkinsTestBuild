// JenkinsTestBuild.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include "Placeholder.h"
#include "TestLogger.h"

int main(int argc, char* argv[])
{

	//Setup Test Suite
	TestLogger Logger;
	Logger.BaseNodeFeature = new Feature();
	Scenario scen = Scenario();
	Step step = Step();
	step.status = "failed";
	Logger.BaseNodeFeature->Scenarios.push_back(scen);

	// Arbitrary number of tests = 5
	for (int i = 0; i < 5; i++)
	{
		Logger.BaseNodeFeature->Scenarios[0].Steps.push_back(step);

	}

	//Step1 - Random Code - Pretend Boot-Test Step-1
	int test1 = 252;
	std::cout << test1 << std::endl;
	Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
	Logger.UpdateJSON();

	//Step2 - Random Code - Pretend Boot-Test Step-2
	const char* test2 = "a";
	std::cout << test2 << std::endl;
	Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
	Logger.UpdateJSON();

	//Step3 - Random Code - Pretend Boot-Test Step-3
	float test3 = 5.3;
	std::cout << test3 << std::endl;
	Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
	Logger.UpdateJSON();

	//Step4 - Random Code - Pretend Boot-Test Step-4
	int *test4 = NULL;
	//*test4 = 42; //Intentional Crash
	Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "failed";
	Logger.UpdateJSON();

	//Step5 - Random Code - Pretend Boot-Test Step-5
	bool test5 = 5.3;
	std::cout << test5 << std::endl;
	Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
	Logger.UpdateJSON();
	
	

	


	
	
	
	


		
	


	
    std::cout << "Test Over\n";
	
	

	
	//system("Pause");
	return 0;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

