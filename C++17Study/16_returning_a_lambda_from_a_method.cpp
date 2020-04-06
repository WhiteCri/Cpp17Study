#include <iostream>
#include <string>

struct Baz {
	auto foo() {
		//c++17, capture a whole object
		auto lam = [*this]() { std::cout << s;};//this captures copy of the whole object
	//c++14,
	//auto lam = [self = *this]{ std::cout << self.s; };
		//return [=] {std::cout << s << '\n'; };

		return lam;
	}
	
	std::string s;
};

int main() {
	auto f1 = Baz{ "ala" }.foo();//this in lambda become a dangling pointer
	int a[100] = {};
	for (int i = 0; i < 100; ++i)
		f1();
}