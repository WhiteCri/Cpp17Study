#include <iostream>
#include <optional>

#if defined __has_include
# if __has_include(<charconv>)
# define has_charconv 1
# include <charconv>
# endif
#endif
std::optional<int> ConvertToInt(const std::string& str) {
	int value{ };
#ifdef has_charconv
	const auto last = str.data() + str.size();
	const auto res = std::from_chars(str.data(), last, value);
	if (res.ec == std::errc{} && res.ptr == last)
		return value;
#else
	// alternative implementation...
#endif
	return std::nullopt;
}
int main() {

}

//for older compilers use :
//#if defined __has_include && __has_include(<charconv>)