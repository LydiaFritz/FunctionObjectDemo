#include <iostream>

class A {
private:
	int a_val;
	int* bonus[2];
public:
	A() { a_val = 1; }
	A(int a) { a_val = a; bonus[0] = new int(a); bonus[1] = new int(a*a); }
	int getVal() { return a_val; }
	void setVal(int a) { a_val = a; }
	//function object
	int operator()(int multiplier) {
		return a_val * multiplier;
	}
};

int main() {

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

}

