//__declspec, __attribute__, #pragma

//struct S { short f[3]; } __attribute__ ((aligned (8)));

//void fatal () __attribute__ ((noreturn));
[[deprecated("use AwesomeFunc instead")]] void GoodFunc() { }
/*
	Attribute is additional information that can be used by the compiler to produce code
	Unlike C#, C++ compiler has fixed the meta-information system, so we can not add user-defined attributes.
	C# code can derive from System.Attribute

	Before C++ 11,

	gcc specific attributes:
	int square (int) __attribute__ ((pure)); // pure function

	MSVC specific attributes
	__declspec(deprecated) void LegacyCode() { }

	Attributes in C++11 and c++14,
	[[attrib_name]] void foo() { } // on a function
	struct [[deprecated]] OldStruct { } // on a struct

	C++11:
	[[noreturn]] : control flow will not return to the caller
	->std::abort, std::exit

	[[carries_dependency]] : indicates that the dependency chain in release-consume std::memory_order porpagates
	in and out of the function, which allows the compiler to skip unnecessary memory fence

	C++14:
	[[deprecated]] and [[deprecated("reason")]] :

	ex : [[deprecated("use AwesomeFunc instead")]] void GoodFunc() { }

	C++17:
	- [[fallthrough]]
	- [[nodiscard]]
	- [[maybe_unused]]

	with 3 features : 
		- Attributes for namespaces and enumerators
		- ignore unknown attributes
		- using attribute namespaces without repetition
	
	[[fallthrough]] - indicates that a fall-through in a switch statement is intentional
	and a warning should not be issued for it
		switch (c) {
		case 'a':
			f(); // Warning! fallthrough is perhaps a programmer error
		case 'b':
			g();
			[[fallthrough]]; // Warning suppressed, fallthrough is ok
		case 'c':
			h();
		}

	[[maybe_unused]] : suppresses compiler warnings about unused entities:
	
		static void impl1() { ... } // Compilers may warn when function not called
		[[maybe_unused]] static void impl2() { ... } // Warning suppressed
		void foo() {
			int x = 42; // Compilers may warn when x is not used later
			[[maybe_unused]] int y = 42; // Warning suppressed for y
		}
		it is useful when some of the variables and functions are used in debug only path 

	[[nodiscard]] : can be applied to a function or a type declaration to mark the importance
	of the returned value

		[[nodiscard]] int Compute();
		void Test() {
			Compute();	// Warning! return value of a
						// nodiscard function is discarded
		}

		enum class [[nodiscard]] ErrorCode {
			OK,
			Fatal,
			System,
			FileIssue
		};
		ErrorCode OpenFile(std::string_view fileName);
		ErrorCode SendEmail(std::string_view sendto,
		std::string_view text);
		ErrorCode SystemCall(std::string_view text);

	- Attributes for namespaces and enumerators
		namespace [[deprecated("use BetterUtils")]] GoodUtils {
			void DoStuff() { }
		}
		namespace BetterUtils {
			void DoStuff() { }
		}
		// use:
		GoodUtils::DoStuff();

		will make msgs like
		warning: 'GoodUtils' is deprecated: use BetterUtils
		[-Wdeprecated-declarations]

	- ignore unknown attributes
		[[MyCompilerSpecificNamespace::do_special_thing]]
		void foo();

		will make in GCC 7.1
		warning: 'MyCompilerSpecificNamespace::do_special_thing'
		scoped attribute directive ignored [-Wattributes]
		void foo();

	- using attribute namespaces without repetition
		void f() {
			[[rpr::kernel, rpr::target(cpu,gpu)]] // repetition
			doTask();
		}
		Proposed change:
		void f() {
			[[using rpr: kernel, target(cpu,gpu)]]
			doTask();
		}
*/
int main() {
	GoodFunc();
}