#include "TestLogger.h"

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

void TestLogger::CreateFeature(const char* title)
{
/*
	featureRootNode = cJSON_CreateObject();

	cJSON *urivalue;
	urivalue = cJSON_CreateString("somevalue");
	cJSON_AddItemToObject(featureRootNode, "uri", urivalue);

	//
	cJSON *idvalue;
	idvalue = cJSON_CreateString("GameTest");
	cJSON_AddItemToObject(featureRootNode, "id", idvalue);
	//

	//
	cJSON *keywordvalue;
	keywordvalue = cJSON_CreateString("Tests");
	cJSON_AddItemToObject(featureRootNode, "keyword", keywordvalue);
	//

	//
	cJSON *namevalue;
	namevalue = cJSON_CreateString(title);
	cJSON_AddItemToObject(featureRootNode, "name", namevalue);
	//

	//
	cJSON *linevalue;
	linevalue = cJSON_CreateNumber(1);
	cJSON_AddItemToObject(featureRootNode, "line", linevalue);
	//

	//
	cJSON *descriptionvalue;
	descriptionvalue = cJSON_CreateString("");
	cJSON_AddItemToObject(featureRootNode, "description", descriptionvalue);

	cJSON *elementsvalue;
	elementsvalue = cJSON_CreateArray();
	cJSON_AddItemToObject(featureRootNode, "elements", elementsvalue);
*/
}

void TestLogger::CreateScenario(const char * title)
{
	
	//
	//cJSON *subidvalue;
	//subidvalue = cJSON_CreateString("BootTest1");
	//cJSON_AddItemToObject(element1, "id", subidvalue);
}
