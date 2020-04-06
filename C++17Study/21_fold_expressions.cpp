#include <iostream>
#include <string>
#include <vector>
using namespace std::string_literals;

auto SumCpp11() {
	return 0;
}

template <typename T1, typename... T>
auto SumCpp11(T1 s, T... ts) {
	return s + SumCpp11(ts...);
}

template <typename ...Args> auto sum(Args ...args) {
	return (args + ... + 0);
}

template <typename ...Args> auto sum2(Args ...args) {
	return (args + ...);
}

/*
	expression			Name						Expansion
	(... op e)			unary left fold				((e1 op e2) op ...) op eN
	(init op ... op e)	binary left fold			(((init op e1) op e2) op ...) op eN
	(e op ...)			unary right fold e1 op		(... op (eN-1 op eN))
	(e op ... op init)	binary right fold e1 op		(... op (eN-1 op (eN op init)))

	op can be : + - * / % ^ & | = < > << >> += - = *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*.
*/

template<typename ...Args>
void FoldPrint(Args&&... args) {
	(std::cout << ... << std::forward<Args>(args)) << '\n';
}

template<typename ...Args>
void FoldSeparateLine(Args&&... args) {
	auto separateLine = [](const auto& v) {
		std::cout << v << '\n';
	};
	(..., separateLine(std::forward<Args>(args))); // over comma operator
}

template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args) {
	(v.push_back(std::forward<Args>(args)), ...);
}

int main() {
	auto value = sum2(1, 2, 3, 4); // this becomes auto value = 1 + (2 + (3 + 4));
	auto str = sum2("Hello "s, "World "s);
	
	FoldPrint("hello", 10, 20, 30);
	FoldSeparateLine("hello", 10, 20, 30);

}