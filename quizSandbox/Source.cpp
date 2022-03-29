#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

class A {
private:
	int a_val;
	int* bonus[2];
public:
	A() { a_val = 1; }
	A(int a) { a_val = a; bonus[0] = new int(a); bonus[1] = new int(a*a); }
	int getVal() { return a_val; }
	void setVal(int a) { a_val = a; }

	//OVERLOAD THE () OPERATOR SO OBJECTS 
	//OF THIS CLASS CAN BE USED AS FUNCTIONS
	int operator()(int multiplier) {
		return a_val * multiplier;
	}
};

double getAverage(double a, double b, double c) {
	return (a + b + c) / 3.0;
}


void sayName(std::string name) {
	for (char ch : name) {
		std::cout << ch << "  ";
	}
	std::cout << std::endl;
}




int main() {

	srand(time(NULL));

	//EXAMPLE 1
	//ASSIGNING A FUNCTION TO A VARIABLE
	//func is a function pointer to sayName(string)
	auto func = sayName;
	func("Karen");

	//EXAMPLE 2
	//CREATING A FUNCTION POINTER WITHOUT USING AUTO
	void(*myFunction)(std::string) = sayName;
	myFunction("Lillian");

	double(*averagingFunc)(double, double, double) = getAverage;
	std::cout << averagingFunc(2.3, 4.5, 6.889) << std::endl;

	//EXMAMPLE 3
	//USING TYPEDEF TO CREATE A FUNCTION POINTER
	typedef void(*sayNameFunc)(std::string);
	sayNameFunc function = sayName;
	function("Betsy");

	//EXAMPLE 4
	//CREATING A FUNCTION OBJECT WITH myObj
	A myObj;
	int n = 1;

	for (; n <= 10; n++) {
		myObj.setVal(n);
		for (int i = 1; i <= 10; i++) {
			//produce multiplication table
			//using the object myObj as a function
			std::cout << myObj(i) << "\t";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;


	//EXAMPLE 5
	//USING A LAMBDA EXPRESSION AS A PARAMETER TO A FUNCTION

	std::vector<int> myVec;
	for (int i = 0; i < 1000; i++) {
		myVec.push_back(rand() % 1000);
	}

	//auto it = std::find_if(myVec.begin(), myVec.end(), [](int value) { return (value%8) == 0; });

	int count = std::count_if(myVec.begin(), myVec.end(), [](int value) {return value % 8 == 0; });
	

	std::cout << count << std::endl;
	return 0;



}

