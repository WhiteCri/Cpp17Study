#include <iostream>
//Since C++17 lambda expressions (their call operator operator()) that follow the rules of
//standard constexpr functions are implicitly declared as constexpr
int main() {
	constexpr auto SquareLambda = [](int n) {return n * n; };
	static_assert(SquareLambda(3) == 10, "her!");
}
//features of constexpr functions
/*
	- they cannot be virtual
	- their return type shall be a literal type
	- their parameter types shall be a literal type
	- their function bodies cannot contain: asm definition, a goto statement, try-block, or
		a variable that is a non-literal type or static or thread storage duration
*/