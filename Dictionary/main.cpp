#include "Dictionary.h"

void call1()
{
	std::cout << "Fn call1()" << std::endl;
}

void call2()
{
	std::cout << "Fn call2()" << std::endl;
}

int main()
{
	std::cout << "Dictionary in C++" << std::endl << std::endl;


	//========================================
	//  First exemple using a simple value
	//========================================
	Dictionary<char*> dict;

	dict.set("PT", "Ola mundo!");
	dict.set("EN", "Hello world!");
	dict.set("ES", "Holla mundo!");

	char* r1 = dict["PT"];
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	char* r2 = dict["EN"];
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	char* r3 = dict["ES"];
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;

	//========================================
	//  Second exemple change value using []
	//========================================
	dict["EN"] = "Has a new value here";
	std::cout << std::endl << "After change the value of \"EN\" using [] operator:" << std::endl;

	r1 = dict["PT"];
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	r2 = dict["EN"];
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	r3 = dict["ES"];
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;


	//========================================
	//     Third exemple remove a sample
	//========================================
	dict.pop("EN");
	std::cout << std::endl << "After delete \"EN\" pair:" << std::endl;

	r1 = dict["PT"];
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	r2 = dict["EN"];
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	r3 = dict["ES"];
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;

	//========================================
	//    Fourth exemple clearing the dict
	//========================================
	dict.clear();
	std::cout << std::endl << "After realocate the dictionary in memory:" << std::endl;

	r1 = dict["PT"];
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	r2 = dict["EN"];
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	r3 = dict["ES"];
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;

	//========================================
	//    Fifth exemple calling functions
	//========================================
	std::cout << std::endl << "New dict calling functions:" << std::endl;

	Dictionary<void(*)()> dict2;

	dict2.set("call1", call1);
	dict2.set("call2", call2);

	dict2["call1"]();
	dict2["call2"]();

	return 0;
}
