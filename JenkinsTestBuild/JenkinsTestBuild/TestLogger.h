#pragma once
#include "cJSON.h"

class TestLogger
{
	

public:
	TestLogger();
	~TestLogger();

	void CreateFeature();

private:
	cJSON* featureRootNode;

};

struct Feature
{
	int x;
};

/*
"uri": "features/embed.feature",
		"id": "Game Tests",
		"keyword": "Tests",
		"name": "ATestSuite",
		"line": 1,
		"description": "",

*/