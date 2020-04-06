#include <iostream>
#include <set>
#include <map>
int main(int argc, char *argv[]) {
	std::set<int> mySet;
	auto[iter, inserted] = mySet.insert(1);
	std::cout << "inserted : " << inserted << '\n';

	std::pair a(0, 1.0f);
	auto[x, y] = a;

	//const auto[a, b, c, ...] = expression;
	//auto&[a, b, c, ...] = expressio;
	//auto&&[a, b, c, ...] = expression;

	std::pair a2(0, 1.0f);
	auto& [x2, y2] = a2;
	x2 = 10; // write access
	// a.first is now 10
	std::cout << a2.first <<  ' ' << a2.second << '\n';

	//[[maybe_unused]] auto& [a, b, c, ...] = expression;
	/* binding can be happen in 3 cases*/
	//1. if the initializer is array
	double myArray[3] = { 1., 2., 3. };
	auto[a3, b3, c3] = myArray;

	//If the initializer supports std::tuple_size<>, provides get<N>() and also exposes
	//std::tuple_element functions :
	std::pair myPair(0, 1.0f);
	auto[a4, b4] = myPair; // binds myPair.first/second

	//3. If the initialiser¡¯s type contains only non - static data members :
	struct Point {
		double x;
		double y;
	};

	auto GetStartPoint = []()->Point {
		return { 0.0, 0.0 };
	};
	auto [x_, y_] = GetStartPoint();
	//The class doesn't have to be POD, but the number of identifiers must equal to the number of non-static
	//data members

	std::map<int, std::string > myMap;
	// C++14:
	for (const auto& elem : myMap) {
		// elem.first - is velu key
		// elem.second - is the value
	}
	// C++17:
	for (const auto&[key, val] : myMap) {
		// use key/value directly
	}
}