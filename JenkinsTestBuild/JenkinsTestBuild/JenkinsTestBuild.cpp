// JenkinsTestBuild.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include "Placeholder.h"
//#include "cJSON.h"
#include "TestLogger.h"

int main(int argc, char* argv[])
{
	TestLogger Logger;
	//Logger.BaseNodeFeature = new Feature("", "", "", "", 1, "");
	Logger.BaseNodeFeature = new Feature();

	Scenario scen = Scenario();
	Step step = Step();

	Logger.BaseNodeFeature->Scenarios.push_back(scen);
	Logger.BaseNodeFeature->Scenarios[0].Steps.push_back(step);
	Logger.UpdateJSON();
	/*
	cJSON* json = cJSON_Parse(output);
	std::ofstream myfile;
	myfile.open("example.json");
	myfile << output;
	myfile.close();
	*/

		
	

#if false
	char *output;

	cJSON *rootnode;
	rootnode = cJSON_CreateObject();

	
	//
	cJSON *urivalue;
	urivalue = cJSON_CreateString("somevalue");
	cJSON_AddItemToObject(rootnode, "uri", urivalue);
	//

	//
	cJSON *idvalue;
	idvalue = cJSON_CreateString("GameTest");
	cJSON_AddItemToObject(rootnode, "id", idvalue);
	//

	//
	cJSON *keywordvalue;
	keywordvalue = cJSON_CreateString("Tests");
	cJSON_AddItemToObject(rootnode, "keyword", keywordvalue);
	//

	//
	cJSON *namevalue;
	namevalue = cJSON_CreateString("ATestSuite");
	cJSON_AddItemToObject(rootnode, "name", namevalue);
	//

	//
	cJSON *linevalue;
	linevalue = cJSON_CreateNumber(1);
	cJSON_AddItemToObject(rootnode, "line", linevalue);
	//

	//
	cJSON *descriptionvalue;
	descriptionvalue = cJSON_CreateString("");
	cJSON_AddItemToObject(rootnode, "description", descriptionvalue);
	//

	//
	cJSON *elementsvalue;
	elementsvalue = cJSON_CreateArray();
	cJSON_AddItemToObject(rootnode, "elements", elementsvalue);
	//


	//
	cJSON *element1;
	element1 = cJSON_CreateObject();
	cJSON_AddItemToArray(elementsvalue, element1);
	
	//
	cJSON *subidvalue;
	subidvalue = cJSON_CreateString("BootTest1");
	cJSON_AddItemToObject(element1, "id", subidvalue);
	//

	output = cJSON_Print(rootnode);
	printf("%s\n", output);

	cJSON* json = cJSON_Parse(output);
	std::ofstream myfile;
	myfile.open("example.json");
	myfile << output;
	myfile.close();
	
	char *out;
	cJSON *root, *cars, *car;

	/* create root node and array */
	root = cJSON_CreateObject();
	cars = cJSON_CreateArray();

	/* add cars array to root */
	cJSON_AddItemToObject(root, "cars", cars);

	/* add 1st car to cars array */
	cJSON_AddItemToArray(cars, car = cJSON_CreateObject());
	cJSON_AddItemToObject(car, "CarType", cJSON_CreateString("BMW"));
	cJSON_AddItemToObject(car, "carID", cJSON_CreateString("bmw123"));

	/* add 2nd car to cars array */
	cJSON_AddItemToArray(cars, car = cJSON_CreateObject());
	cJSON_AddItemToObject(car, "CarType", cJSON_CreateString("mercedes"));
	cJSON_AddItemToObject(car, "carID", cJSON_CreateString("mercedes123"));

	

	/* print everything */
	out = cJSON_Print(root);
	printf("%s\n", out);

	/* Parse */
	cJSON* json = cJSON_Parse(out);
	std::ofstream myfile;
	myfile.open("example.json");
	myfile << out;
	myfile.close();

	/* free all objects under root and root itself */
	cJSON_Delete(root);

#endif
	
    std::cout << "Hello World!\n";
	
	

	
	system("Pause");
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

