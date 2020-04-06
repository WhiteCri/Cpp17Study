#include <iostream>
#include <string>
#include <mutex>
#include <shared_mutex>

using namespace std::string_literals; // enables s-suffix for std::string literals
int main() {
	std::pair myPair{ 42, "hello world!" };//Class Template Argument Deduction
	//also works with copy initialisation and new()

	auto otherPair = std::pair{ 42, "Hello"s }; // also deduced
	auto ptr = new std::pair{ 42, "World"s }; // for new

	/*
		Below becomes
		// lock guard:
		std::shared_timed_mutex mut;
		std::lock_guard<std::shared_timed_mutex> lck(mut);
	*/
	std::shared_timed_mutex mut;
	std::lock_guard lck(mut);

	//now partial deduction cannot happen
	//std::tuple<int> t(1, 2, 3); // Error: partial deduction

	//with those expression, we don't have to use make_xxx series, such as make_pair
	//but make_shared is in another case, cuz it does not only creates memory, but also generates control block


}