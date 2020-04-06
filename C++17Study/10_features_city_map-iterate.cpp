#include <map>
#include <iostream>
#include <string>

int main() {
	const std::map<std::string, int> mapCityPopulation{
		{"Beijing", 21'707'000},
		{"London", 8'787'892},
		{"new York", 8'622'698}
	};

	for (auto&[city, population] : mapCityPopulation)
		std::cout << city << ": " << population << '\n';
}