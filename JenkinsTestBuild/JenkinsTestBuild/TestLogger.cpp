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
	
	
}


TestLogger::~TestLogger()
{
}

void TestLogger::UpdateJSON()
{
	cJSON* root = CreateFeature();
	char *output;

	output = cJSON_Print(root);
	cJSON* json = cJSON_Parse(output);
	std::ofstream myfile;
	myfile.open("Jsontest.json");
	myfile << output;
	myfile.close();

	
	cJSON_Delete(json);
	cJSON_Delete(root);
	
}

//Creates a feature - A Feature is the top hierarchical
//parent on the Cucumber plugin test and contains Scenario sub-objects
cJSON* TestLogger::CreateFeature()
{

	//Feature
	cJSON* logRoot = cJSON_CreateArray();
	
	cJSON* subRoot = cJSON_CreateObject();

	cJSON_AddItemToArray(logRoot, subRoot);

	cJSON_AddItemToObject(subRoot, "uri", cJSON_CreateString(BaseNodeFeature->uri));
	cJSON_AddItemToObject(subRoot, "id", cJSON_CreateString(BaseNodeFeature->id));
	cJSON_AddItemToObject(subRoot, "keyword", cJSON_CreateString(BaseNodeFeature->keyword));
	cJSON_AddItemToObject(subRoot, "name", cJSON_CreateString(BaseNodeFeature->name));
	cJSON_AddItemToObject(subRoot, "line", cJSON_CreateNumber(BaseNodeFeature->line));
	cJSON_AddItemToObject(subRoot, "description", cJSON_CreateString(BaseNodeFeature->description));

	cJSON* scenarioArrayValue = cJSON_CreateArray();
	cJSON_AddItemToObject(subRoot, "elements", scenarioArrayValue);
	cJSON* subObject = cJSON_CreateObject();
	cJSON_AddItemToArray(scenarioArrayValue, subObject);
	
	CreateScenario(subObject);

	return logRoot;
}

//Creates a Scenario - A Scenario is the middle-tier hierarchical
//object on the Cucumber plugin test and contains Step sub-objects
void TestLogger::CreateScenario(cJSON* _parentFeature)
{
	cJSON_AddItemToObject(_parentFeature, "id", cJSON_CreateString(BaseNodeFeature->Scenarios[0].id));
	cJSON_AddItemToObject(_parentFeature, "keyword", cJSON_CreateString(BaseNodeFeature->Scenarios[0].keyword));
	cJSON_AddItemToObject(_parentFeature, "name", cJSON_CreateString(BaseNodeFeature->Scenarios[0].name));
	cJSON_AddItemToObject(_parentFeature, "line", cJSON_CreateNumber(BaseNodeFeature->Scenarios[0].line));
	cJSON_AddItemToObject(_parentFeature, "description", cJSON_CreateString(BaseNodeFeature->Scenarios[0].description));
	cJSON_AddItemToObject(_parentFeature, "type", cJSON_CreateString(BaseNodeFeature->Scenarios[0].type));
	
	cJSON* stepArrayValue = cJSON_CreateArray();
	cJSON_AddItemToObject(_parentFeature, "steps", stepArrayValue);
	cJSON* subObject = cJSON_CreateObject();
	cJSON_AddItemToArray(stepArrayValue, subObject);

	CreateStep(subObject);

}

//Creates a Step - A Step is the lowest-tier hierarchical
//object on the Cucumber plugin test and contains the individual results from tests
void TestLogger::CreateStep(cJSON* _parentScenario)
{

	cJSON_AddItemToObject(_parentScenario, "keyword", cJSON_CreateString(BaseNodeFeature->Scenarios[0].Steps[0].keyword));
	cJSON_AddItemToObject(_parentScenario, "name", cJSON_CreateString(BaseNodeFeature->Scenarios[0].Steps[0].name));
	cJSON_AddItemToObject(_parentScenario, "line", cJSON_CreateNumber(BaseNodeFeature->Scenarios[0].Steps[0].line));

	
	
	cJSON* testResult = cJSON_CreateObject();
	cJSON_AddItemToObject(_parentScenario, "result", testResult);

	cJSON_AddItemToObject(testResult, "status", cJSON_CreateString(BaseNodeFeature->Scenarios[0].Steps[0].status));
	cJSON_AddItemToObject(testResult, "duration", cJSON_CreateNumber(BaseNodeFeature->Scenarios[0].Steps[0].duration));
}


// Below is a working example of a json file laid out correctly for Cucumber
// refer to this if you need help getting the format correct

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