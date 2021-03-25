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
	std::cout << "Simple Dictionary in C++" << std::endl << std::endl;


	//========================================
	//  First exemple using a simple value
	//========================================
	Dictionary<char*> dict;

	dict.add("Ola", "mundo");
	dict.add("Hello", "world");
	dict.add("Hola", "mundo!");

	dict.pop("Hello");

	char* r1 = dict.get("Ola");
	r1 = ((bool)(r1 != NULL) ? r1 : "Null");

	char* r2 = dict.get("Hello");
	r2 = ((bool)(r2 != NULL) ? r2 : "Null");

	char* r3 = dict.get("Hola");
	r3 = ((bool)(r3 != NULL) ? r3 : "Null");

	std::cout << "Ola: " << r1 << std::endl;
	std::cout << "Hello: " << r2 << std::endl;
	std::cout << "Hola: " << r3 << std::endl;

	std::cout << std::endl << std::endl;


	//========================================
	//   Second exemple calling functions
	//========================================
	Dictionary<void(*)()> dict2;

	dict2.add("call1", call1);
	dict2.add("call2", call2);

	dict2.get("call1")();
	dict2.get("call2")();

	return 0;
}
