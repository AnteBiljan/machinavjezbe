#include <iostream>
#include <string>


int main()
{
	int number = 5;
	int& tracker = number;
	int* ptr = &number;
	std::string* strptr;
	std::string someWord = "Nesto";
	strptr = &someWord;
	int** doubleptr = &ptr;

	number = 9;
	std::cout << "Hello World" << std::endl;
	std::cout << "number: " << number << std::endl;
	std::cout << "tracker: " << tracker << std::endl;
	std::cout << "pointer: " << ptr << std::endl;
	std::cout << "strpointer: " << strptr << std::endl;
	std::cout << "derefference strptr: " << *strptr << std::endl;
	*strptr = "nesto drugo";
	std::cout << "derefference strptr take 2: " << *strptr << std::endl;
	std::cout << "doubleptr ptr address: " << *doubleptr << std::endl;
	std::cout << "doubleptr ptr address: " << **doubleptr << std::endl;

	std::cin.get();
}