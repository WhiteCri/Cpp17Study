#include <iostream>
#include <string>
#include <map>

//c++ 17 supports...
//if (init; condition)
//and
//switch(init; condition)

/*before c++17 ...
{
	auto val = GetValue();
	if (condition(val))
	// on success
	else
	// on false...
}

now we can write
	if (auto val = GetValue(); condition(val))
	// on success
	else
	// on false...
	
variable 'val' exists in if/else
*/

int main() {
	//we can replace below code
	/*
	const std::string myString = "My Hello World Wow";
	const auto pos = myString.find("Hello");
	if (pos != std::string::npos)
		std::cout << pos << " Hello\n"
	const auto pos2 = myString.find("World");
		if (pos2 != std::string::npos)
	std::cout << pos2 << " World\n"
*/
	//to
	std::string myString = "Hello World!";
	if (const auto pos = myString.find("Hello"); pos != std::string::npos)
		std::cout << pos << " Hello\n";
	if (const auto pos = myString.find("World"); pos != std::string::npos)
		std::cout << pos << " World\n";

	if (const auto pos = myString.find("World"); pos != std::string::npos)
		std::cout << pos << " World\n";
	else
		std::cout << pos << " not found!!\n";

	//with the map...
	// better together: structured bindings + if initializer
	std::map<std::string, int> mymap = { {"еб©М", 24} };
	std::pair value = { "а╓╧н", 40 };
	if (auto[iter, succeeded] = mymap.insert(value); succeeded) {
		// ...
		std::cout << "succeeded!\n";
	} // iter and succeeded are destroyed here

	std::string str = "Hi World";
	if (auto[pos, size] = std::pair(str.find("Hi"), str.size()); pos != std::string::npos)
		std::cout << pos << " Hello, size is " << size;
}

