#include <iostream>

class Query {
public:
	Query& addInt(int i) {
		std::cout << "addInt: " << i << '\n';
		return *this;
	}

	Query& addFloat(float f) {
		std::cout << "addFloat: " << f << '\n';
		return *this;
	}
};

float computeFloat() {
	std::cout << "computing float... \n";
	return 10.1f;
}

float computeInt() {
	std::cout << "computing int... \n";
	return 8;
}

int main() {
	Query q;
	q.addFloat(computeFloat()).addInt(computeInt());
}