// JenkinsTestBuild.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Placeholder.h"
#include "TestLogger.h"
//#define BOOTTEST

int main(int argc, char* argv[])
{
#ifdef BOOTTEST
	if (argc > 1)
	std::cout << argv[1] << std::endl; // Just to check argv parameters are being passed from msbuild
	std::cout << "BOOT TEST MODE ACTIVATED"; // Just to check the BOOTTEST define is being set from cmd
	//Setup Test Suite
	TestLogger Logger;
	
	Logger.BaseNodeFeature = new Feature();
	Scenario scen = Scenario();
	Step step = Step();
	step.status = "failed";
	Logger.BaseNodeFeature->Scenarios.push_back(scen);

	// Arbitrary number of tests = 1
	for (int i = 0; i < 1; i++)
	{
		Logger.BaseNodeFeature->Scenarios[0].Steps.push_back(step);

	}
#endif 


	for (int i = 0; i < 1000000; i++)
	{
		// Just to hold up the run stage
	}
	
	
	



#ifdef BOOTTEST
	if (strcmp(argv[1], "BootStage1") ==0)
	{
		Logger.FileName = "BootStage1";
		Logger.BaseNodeFeature->name = "Level 1";
		Logger.UpdateJSON();
#endif

		//Step1 - Random Code - Pretend Boot-Test Step-1
		int test1 = 252;
		std::cout << test1 << std::endl;
#ifdef BOOTTEST
		Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
		Logger.UpdateJSON();
		std::exit(0);
	}
#endif 

#ifdef BOOTTEST
	if (strcmp(argv[1], "BootStage2") ==0)
	{
		Logger.FileName = "BootStage2";
		Logger.BaseNodeFeature->name = "Level 2";
		Logger.UpdateJSON();
#endif
		//Step2 - Random Code - Pretend Boot-Test Step-2
		const char* test2 = "a";
		std::cout << test2 << std::endl;
#ifdef BOOTTEST
		Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
		Logger.UpdateJSON();
		std::exit(0);
	}
#endif 

#ifdef BOOTTEST
	if (strcmp(argv[1], "BootStage3") ==0)
	{
		Logger.FileName = "BootStage3";
		Logger.BaseNodeFeature->name = "Level 3";
		Logger.UpdateJSON();
#endif
		//Step3 - Random Code - Pretend Boot-Test Step-3
		float test3 = 5.3;
		std::cout << test3 << std::endl;
#ifdef BOOTTEST
		Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
		Logger.UpdateJSON();
		std::exit(0);
	}
#endif 

#ifdef BOOTTEST
	if (strcmp(argv[1], "BootStage4") ==0)
	{
		Logger.FileName = "BootStage4";
		Logger.BaseNodeFeature->name = "Level 4";
		Logger.UpdateJSON();
#endif
		//Step4 - Random Code - Pretend Boot-Test Step-4
		int *test4 = NULL;
		*test4 = 42; //Intentional Crash
#ifdef BOOTTEST
		Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
		Logger.UpdateJSON();
		std::exit(0);
	}
#endif 

#ifdef BOOTTEST
	if (strcmp(argv[1], "BootStage5") ==0)
	{
		Logger.FileName = "BootStage5";
		Logger.BaseNodeFeature->name = "Level 5";
		Logger.UpdateJSON();
#endif
		//Step5 - Random Code - Pretend Boot-Test Step-5
		bool test5 = true;
		std::cout << test5 << std::endl;
#ifdef BOOTTEST
		Logger.BaseNodeFeature->Scenarios[0].Steps[0].status = "passed";
		Logger.UpdateJSON();
		std::exit(0);
	}
#endif 
	
	

	


	
	
	
	


		
	

	
	
    std::cout << "Test Over!" << std::endl;
	
	

	
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

