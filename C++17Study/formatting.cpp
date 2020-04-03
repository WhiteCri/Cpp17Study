#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string text = "Hello World";
	std::cout << text << '\n';
}

int foo() {
	return std::clamp(100, 1000, 1001);
}