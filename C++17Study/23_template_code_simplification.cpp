#include <iostream>

/* before c++ 17 */
template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> simpleTypeInfo(T t) {
	std::cout << "foo<integral T> " << t << '\n';
	return t;
}
template <typename T>
std::enable_if_t<!std::is_integral_v<T>, T> simpleTypeInfo(T t) {
	std::cout << "not integral \n";
	return t;
}

template <typename T>
T simpleTypeInfoTagImpl(T t, std::true_type) {
	std::cout << "foo<integral T> " << t << '\n';
	return t;
}
template <typename T>
T simpleTypeInfoTagImpl(T t, std::false_type) {
	std::cout << "not integral \n";
	return t;
}
template <typename T>
T simpleTypeInfoTag(T t) {
	return simpleTypeInfoTagImpl(t, std::is_integral<T>{});
}

template <typename T>
T simpleTypeInfoFinal(T t) {
	if constexpr (std::is_integral_v<T>) {
		std::cout << "foo<integral T> " << t << '\n';
	}
	else {
		std::cout << "not integral \n";
	}
	return t;
}

template<typename T> void linePrinter(const T& x) {
	if constexpr (std::is_integral_v<T>) {
		std::cout << "num: " << x << '\n';
	}
	else if constexpr (std::is_floating_point_v<T>) {
		const auto frac = x - static_cast<long>(x);
		std::cout << "flt: " << x << ", frac " << frac << '\n';
	}
	else if constexpr (std::is_pointer_v<T>) {
		std::cout << "ptr, ";
		linePrinter(*x);
	}
	else {
		std::cout << x << '\n';
	}
}

int main() {

}