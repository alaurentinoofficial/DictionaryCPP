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

	dict.add("PT", "Ola mundo!");
	dict.add("EN", "Hello world!");
	dict.add("ES", "Holla mundo!");

	char* r1 = dict.get("PT");
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	char* r2 = dict.get("EN");
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	char* r3 = dict.get("ES");
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;

	//========================================
	//    Second exemple remove a sample
	//========================================
	dict.pop("EN");
	std::cout << std::endl << "After delete \"EN\" pair:" << std::endl;

	r1 = dict.get("PT");
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	r2 = dict.get("EN");
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	r3 = dict.get("ES");
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;

	//========================================
	//    Third exemple clearing the dict
	//========================================
	dict.clear();
	std::cout << std::endl << "After realocate the dictionary in memory:" << std::endl;

	r1 = dict.get("PT");
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	r2 = dict.get("EN");
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	r3 = dict.get("ES");
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "PT: " << r1 << std::endl;
	std::cout << "EN: " << r2 << std::endl;
	std::cout << "ES: " << r3 << std::endl;

	//========================================
	//    Forth exemple calling functions
	//========================================
	std::cout << std::endl << "New dict calling functions:" << std::endl;

	Dictionary<void(*)()> dict2;

	dict2.add("call1", call1);
	dict2.add("call2", call2);

	dict2.get("call1")();
	dict2.get("call2")();

	return 0;
}
