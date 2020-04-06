#include <iostream>
#include <string>

// inside a header file:
struct MyClass {
	static const int sValue;
};

// later in the same header file:
inline int const MyClass::sValue = 777;

/*
	or even in a same header file
*/
struct MyClass3 {
	inline static const int sValue = 777;
};
//note that constexpr variables are inline implicitly, so 
//constexpr inline myVar = 10;.
//is same to constexpr myVar = 10;

/*
class MyClass {
	static inline int Seed(); // static method
};
inline int MyClass::Seed() {
	static const int seed = rand();
	return seed;
}
*/

//can be converted to 
class MyClass2 {
	static inline int seed = rand();
};
//c++17 guarantees that MYClass::seed will 
//have the smae value(generated at runtime) across all the compilation units!
int main() {

}