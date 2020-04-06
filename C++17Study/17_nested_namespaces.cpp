/*
namespace MySuperCompany {
	namespace SecretProject {
		namespace SafetySystem {
			class SuperArmor {
				// ...
			};
			class SuperShield {
				// ...
			};
		} // SafetySystem
	} // SecretProject
} // MySuperCompany
*/
//this becomes more compact
/*
namespace MySuperCompany::SecretProject::SafetySystem {
	class SuperArmor {
		// ...
	};
	class SuperShield {
		// ...
	};
*/

/*
also the standard library had changed from
namespace std {
	namespace regex_constants {
		typedef T1 syntax_option_type;
		// ...
	}
}
to
namespace std::regex_constants {
	typedef T1 syntax_option_type;
	// ...
}
*/
