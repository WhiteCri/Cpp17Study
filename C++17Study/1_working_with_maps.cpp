#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, int> mapUserAge{
		{"Alex", 45}, {"John", 25}
	};

	std::map mapCopy{ mapUserAge };//type deduction

	if (auto[iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded)
		std::cout << iter->first << " reassigned...\n";
	auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26);
	std::cout << wasAdded << '\n';
	for (const auto&[key, value] : mapCopy)
		std::cout << key << ", " << value << '\n';
}