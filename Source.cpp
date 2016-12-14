#include "AnyElementType.h"

int main() {
	int arr[8] = { 8,7,6,5,4,3,2,1 };
	std::string test = "t";
	Chin::MatrixLogging any;
	any.setSize(7, 7);
	any.logElem('f', 0, 1);
	any.logElem(8, 0, 2);
	any.logElem(32957934.12, 0, 3);
	any.logElem("test",0,4);
	any.logElem(arr, 0, 5);
	std::cout<<any.at(0, 1)<<std::endl;
	std::cout<<any.at(0, 2) << std::endl;
	std::cout<<any.at(0,3) << std::endl;
	//std::cout << any.at(0, 4) << std::endl;
	//std::cout << any.at(0, 5) << std::endl;
	std::cout << typeid(arr).name();
	std::cout << typeid(test).name();
	system("PAUSE");
	return 0; 
}
