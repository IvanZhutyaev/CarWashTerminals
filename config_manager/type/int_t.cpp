#include "int_t.h"


namespace cm {
	int_t::int_t(int value) : IBasicType(INT_T) {
		int_t::m_value = value;		
	}		

	int_t::int_t(std::string raw_value) : IBasicType(INT_T) {
		int_t::m_value = stringToInt(raw_value);		
	}		

	int_t::int_t(std::string key, int value) : int_t(value) {
		IType::key = key;
	}		

	int_t::int_t(std::string key, std::string raw_value) : int_t(raw_value) {
		IType::key = key;
	}		

	bool int_t::isRawInt(std::string raw_value) {
		return raw_value.find_first_not_of("0123456789") == std::string::npos;
	} 

	std::string int_t::toString() {
		return intToString(m_value);
	}

	int int_t::toInt() {
		return m_value;

	}

	bool int_t::toBool() {
		return m_value == 0 ? false : true;
	}

}

