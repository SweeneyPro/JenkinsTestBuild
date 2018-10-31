#include "TestLogger.h"
#include <fstream>
Step::Step(const char* _keyword,
	const char* _name,
	int _line,
	const char* _status,
	int _duration)
{
	keyword = _keyword;
	name = _name;
	line = _line;
	status = _status;
	duration = _duration;
}

Scenario::Scenario(const char* _id,
	const char* _keyword,
	const char* _name,
	int _line,
	const char* _description,
	const char* _type)
{
	id = _id;
	keyword = _keyword;
	name = _name;
	line = _line;
	description = _description;
	type = _type;

}

Feature::Feature(const char* _uri,
	const char* _id,
	const char* _keyword,
	const char* _name,
	const int _line,
	const char* _description)
{
	uri = _uri;
	id = _id;
	keyword = _keyword;
	name = _name;
	line = _line;
	description = _description;
}

TestLogger::TestLogger()
{
	//CreateFeature(title);
	
}


TestLogger::~TestLogger()
{
}

void TestLogger::UpdateJSON()
{
	cJSON* root = CreateFeature();
	char *output;

	output = cJSON_Print(root);
	//printf("%s\n", output);

	cJSON* json = cJSON_Parse(output);
	std::ofstream myfile;
	myfile.open("Jsontest.json");
	myfile << output;
	myfile.close();

}

cJSON* TestLogger::CreateFeature()
{

	//Feature

	cJSON* root = cJSON_CreateObject();

	cJSON_AddItemToObject(root, "uri", cJSON_CreateString(BaseNodeFeature->uri));
	cJSON_AddItemToObject(root, "id", cJSON_CreateString(BaseNodeFeature->id));
	cJSON_AddItemToObject(root, "keyword", cJSON_CreateString(BaseNodeFeature->keyword));
	cJSON_AddItemToObject(root, "name", cJSON_CreateString(BaseNodeFeature->name));
	cJSON_AddItemToObject(root, "line", cJSON_CreateNumber(BaseNodeFeature->line));
	cJSON_AddItemToObject(root, "description", cJSON_CreateString(BaseNodeFeature->description));

	cJSON* scenarioarrayvalue = cJSON_CreateArray();
	cJSON_AddItemToObject(root, "elements", scenarioarrayvalue);
	cJSON* test = cJSON_CreateObject();
	cJSON_AddItemToArray(scenarioarrayvalue, test);
	
	CreateScenario(test);

	return root;
}

void TestLogger::CreateScenario(cJSON* _parentFeature)
{
	cJSON_AddItemToObject(_parentFeature, "id", cJSON_CreateString(BaseNodeFeature->Scenarios[0].id));
	cJSON_AddItemToObject(_parentFeature, "keyword", cJSON_CreateString(BaseNodeFeature->Scenarios[0].keyword));
	cJSON_AddItemToObject(_parentFeature, "name", cJSON_CreateString(BaseNodeFeature->Scenarios[0].name));
	cJSON_AddItemToObject(_parentFeature, "line", cJSON_CreateNumber(BaseNodeFeature->Scenarios[0].line));
	cJSON_AddItemToObject(_parentFeature, "description", cJSON_CreateString(BaseNodeFeature->Scenarios[0].description));
	cJSON_AddItemToObject(_parentFeature, "type", cJSON_CreateString(BaseNodeFeature->Scenarios[0].type));
	
	cJSON* steparrayvalue = cJSON_CreateArray();
	cJSON_AddItemToObject(_parentFeature, "steps", steparrayvalue);
	cJSON* test = cJSON_CreateObject();
	cJSON_AddItemToArray(steparrayvalue, test);

	CreateStep(test);

}

void TestLogger::CreateStep(cJSON* _parentScenario)
{

	cJSON_AddItemToObject(_parentScenario, "keyword", cJSON_CreateString(BaseNodeFeature->Scenarios[0].Steps[0].keyword));
	cJSON_AddItemToObject(_parentScenario, "name", cJSON_CreateString(BaseNodeFeature->Scenarios[0].Steps[0].name));
	cJSON_AddItemToObject(_parentScenario, "line", cJSON_CreateNumber(BaseNodeFeature->Scenarios[0].Steps[0].line));

	
	
	cJSON* test = cJSON_CreateObject();
	cJSON_AddItemToObject(_parentScenario, "result", test);

	cJSON_AddItemToObject(test, "status", cJSON_CreateString(BaseNodeFeature->Scenarios[0].Steps[0].status));
	cJSON_AddItemToObject(test, "duration", cJSON_CreateNumber(BaseNodeFeature->Scenarios[0].Steps[0].duration));
}


/*
[
	{
		"uri": "features/embed.feature",
		"id": "Game Tests",
		"keyword": "Tests",
		"name": "ATestSuite",
		"line": 1,
		"description": "",
		"elements": [
			{
				"id": "BootTest1",
				"keyword": "BootTestStage1",
				"name": "",
				"line": 3,
				"description": "",
				"type": "scenario",
				"steps": [
					{
						"keyword": "Info ",
						"name": "Carried out step 1 of boot test",
						"line": 4,
						"result": {
							"status": "passed",
							"duration": 1
						}
					},
					{
						"keyword": "Info ",
						"name": "Carried out step 2 boot test",
						"line": 4,
						"result": {
							"status": "skipped",
							"duration": 1
						}
					},
					{
						"keyword": "Info ",
						"name": "Carried out step 3 boot test",
						"line": 4,
						"result": {
							"status": "undefined",
							"duration": 1
						}
					}
				]
			}
		]
	}


]
*/