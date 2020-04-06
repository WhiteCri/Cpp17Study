#include <iostream>
/*
	if constexpr (cond)
		statement1 //Discarded if cond is false
	else
		statement2 //Discarded if cond is true
*/

template <typename T>
auto get_value(T t) {
	if constexpr (std::is_pointer_v<T>)
		return *t;
	else
		return t;
}

template <typename Concrete, typename... Ts>
std::unique_ptr<Concrete> constructArgs(Ts&&... params) {
	if (std::is_constructible_v<Concrete, Ts...>) // regular `if`
		return std::make_unique<Concrete>(std::forward<Ts>(params)...);
	else
		return nullptr;
}

class Test {
public:
	Test(int, int) { }
};

template <typename Concrete, typename... Ts>
std::unique_ptr<Concrete> constructArgsModified(Ts&&... params) {
	if constexpr (std::is_constructible_v<Concrete, Ts...>) // fixed!
		return std::make_unique<Concrete>(std::forward<Ts>(params)...);
	else
		return nullptr;
}

int main() {

	int a = 3;
	std::cout << get_value(a) << ' ' << get_value(&a) << '\n';
	//auto p = constructArgs<Test>(10, 10, 10); // 3 args!
	/*
		compiler changes to if (std::is_constructible_v<Concrete, int, int, int>)
	*/
	auto p2 = constructArgsModified<Test>(10, 10, 10); //The 'if' code is discared, which is difference from
	//regular if
	std::cout << p2 << '\n';

	//but the discarded code is what related to template parameter
	/*
		template <typename T>
		void Calculate(T t) {
			if constexpr (std::is_integral_v<T>) {
				// ...
				static_assert(sizeof(int) == 100);
			}
			else {
				execute(t);
				strange syntax
		}
}		in this case, the strange syntax will not be erased even when T is integral, but execute(t) will
		be erased

		also static_assert will not be erased,since it is not dependent on T
	*/
}