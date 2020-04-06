#include <iostream>
#include <array>

template<typename T> struct MyType {
	T str;
};
MyType(const char *)->MyType<std::string>;

int main() {
	std::array arr{ 1, 2, 3, 4 };
	MyType t{ "Hello World" };
}

/*
	CTAD(class type argument deduction limit
	- it doesn¡¯t work with template aggregate types
	- the deduction doesn¡¯t include inheriting constructors
	- it doesn¡¯t work with template aliases
*/