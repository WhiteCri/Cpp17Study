#include <iostream>

struct S {
	int n;
	std::string s;
	float d;
};

class MyClass {
public:
	int GetA() const { return a; }
	float GetB() const { return b; }
private:
	int a;
	float b;
};

template <std::size_t I> auto get(MyClass& c) {
	if constexpr (I == 0)		return c.GetA();
	else if constexpr (I == 1)	return c.GetB();
}

//specialisations to support tuple-like interface
namespace std {
	template <> struct tuple_size<MyClass> : integral_constant<size_t, 2> {};
	template <> struct tuple_element<0, MyClass> { using type = int; };
	template <> struct tuple_element<1, MyClass> { using type = float; };
}

//or do the template specialisation
//template <> auto& get<0>(MyClass &c) { return c.GetA(); }

int main() {
	S s;
	auto[a, b, c] = s;
}