#include <iostream>
#include <string>
#include <utility>
#include <typeinfo>
#include <vector>
#include <cstring>

namespace Chin{
class MatrixLogging {
public:
	int rowNums = 0;
	int colNums = 0;
	size_t sizearr;
	std::string toLog;
	std::vector< std::vector< std::pair<void*, std::string> > > matrix;

	void setSize(int rows, int cols) {
		matrix = std::vector< std::vector< std::pair<void*, std::string> > >(rows, std::vector< std::pair<void*, std::string> >(cols));
		rowNums = rows;
		colNums = cols;
	}

	template <typename type>
	void logElem(type var, int x, int y, size_t  test = -1) {
		void* pointer = new type(var);
		matrix.at(x).at(y) = std::make_pair(pointer, typeid(var).name());
		sizearr = test;
	}

	/*template <typename type>
	void logArr(type fakearr[],int x,int y,int size) {
		type *holder = new type[size];
		for (int i = 0; i < size; i++) {
			holder[i] = *(type *)(fakearr + i);
		}
		void* pointer = holder;
		matrix.at(x).at(y) = std::make_pair(pointer, typeid(holder[0]).name());
	}*/

	/*template <typename type>
	type arrAt(int i, int j,int index) {
		type returnVal = (matrix.at(i).at(j).first)+index;
		//type returnVal = holder + index;
		return returnVal;
	}*/

	std::string at(int i, int j) {
		std::string returnVal; 
		if (matrix.at(i).at(j).second == "double") {
			double doubleHolder = *(double*)matrix.at(i).at(j).first;
			returnVal = std::to_string(doubleHolder);

			return returnVal;

		}
		if (matrix.at(i).at(j).second == "int") {
			int intHolder = *(int*)matrix.at(i).at(j).first;
			returnVal = std::to_string(intHolder);

			return returnVal;
		}
		if (matrix.at(i).at(j).second == "char") {
			char charHolder = *((char*)(matrix.at(i).at(j).first));
			std::string returnValor(1,charHolder);

			return returnValor;
		}
		if (matrix.at(i).at(j).second == "char const *") {
			//std::string stringHolder = *(const char*)matrix.at(i).at(j).first;
			//returnVal = stringHolder;
			//return returnVal;
		}

		/*if (matrix.at(i).at(j).second == "int[8]") {
			std::string stringHolder = *(std::string*)matrix.at(i).at(j).first;
			std::string returnVal = stringHolder;
			return returnVal;
		}*/
		


	}

	~MatrixLogging() {
		for (int i = 0; i < rowNums; i++) {
			delete matrix.at(i).at(0).first;
			for (int j = 0; j < colNums; j++) {
				delete matrix.at(i).at(j).first;
			}
		}
	}

};
}