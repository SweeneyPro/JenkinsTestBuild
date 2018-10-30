#pragma once
#include "cJSON.h"
#include <vector>

class Step
{
public:
	Step(const char* _keyword = "Info",
		const char* _name = "Carried out step",
		int _line = 4,
		const char* _status = "passed",
		int _duration = 1);

	const char* keyword;
	const char* name;
	int line;
	const char* status;
	int duration;
};

class Scenario
{
public: 
	Scenario(const char* _id = "Boot Test 1",
		const char* _keyword = "Boot Test Stage 1",
		const char* _name = "",
		int _line = 3,
		const char* _description = "",
		const char* _type = "scenario");


	const char* id;
	const char* keyword;
	const char* name;
	int line;
	const char* description;
	const char* type;

	std::vector<Step> Steps;
};

class Feature
{


public: 
	
	
	Feature(const char* _uri = "features/embed.features",
		const char* _id = "Game Tests",
		const char* _keyword = "Tests",
		const char* _name = "A Test Suite",
		const int _line = 1,
		const char* _description = "");

		const char* uri;
		const char* id;
		const char* keyword;
		const char* name;
		int line;
		const char* description;
	
		std::vector<Scenario> Scenarios;
};




class TestLogger
{
	

public:

	// title is the feature title on jenkins
	TestLogger();
	~TestLogger();
	
	

	
	Feature* BaseNodeFeature;
	

private:
	
	void CreateFeature(const char* title);
	void CreateScenario(const char* title);
	void CreateStep();
};



/*
"uri": "features/embed.feature",
		"id": "Game Tests",
		"keyword": "Tests",
		"name": "ATestSuite",
		"line": 1,
		"description": "",

*/