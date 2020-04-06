#include <iostream>
#include <string>

struct Test {
	void foo() {
		std::cout << m_str << '\n';
		auto addWordLambda = [this]() {m_str += "World"; };
		addWordLambda();
		std::cout << m_str << '\n';
	}

	std::string m_str{ "hello" };
};

int main() {
	Test t;
	t.foo();
}