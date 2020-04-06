#include <iostream>

template <auto value> void f() {
	std::cout << typeid(value).name() << '\n';
}
//c++11, 14
//template <typename Type, Type value> constexpr Type TConstant = value;
//constexpr auto const MySuperConst = TConstant<int, 100>;

template <auto value> constexpr auto TConstant = value;
constexpr auto const MySuperConst = TConstant<100>;

template <auto ... vs> struct HeterogenousValueList {};
using MyList = HeterogenousValueList<'a', 100, 'b'>;

int main() {
	f<10>(); //
}
/* other changes
	Allow typename in a Template Template Parameters.
	Allow Constant Evaluation for all Non-Type Template Arguments.
	Variable Templates for Traits.
		ex :	std::is_integral<T>::value has std::is_integral_v<T>
				std::is_class<T>::value has std::is_class_v<T>
	Pack Expansions in Using Declarations
		-> i need to study more about overload
		template<class... Ts> struct overloaded : Ts... {
			using Ts::operator()...;
		};

	Logical Operation Metafunctions
		- template<class... B> struct conjunction; - logical AND
		- template<class... B> struct disjunction; - logical OR
		- template<class B> struct negation; - logical negation
		->in <type_traits>
		template<typename... Ts>
			std::enable_if_t<std::conjunction_v<std::is_same<int, Ts>...> >
			PrintIntegers(Ts ... args) {
				(std::cout << ... << args) << '\n';
			}
	std::void_t Transformation Trait
		template< class... >
		using void_t = void;

	void Compute(int &) { } // example function
	
	template <typename T, typename = void>
	struct is_compute_available : std::false_type {};
	
	template <typename T>
	struct is_compute_available<T,
		std::void_t<decltype(Compute(std::declval<T>())) >>
			: std::true_type {};
	
	static_assert(is_compute_available<int&>::value);
	static_assert(!is_compute_available<double&>::value);
*/