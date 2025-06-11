#include "bool_t.h"


namespace cm {

	bool_t::bool_t(bool value) : IBasicType(BOOL_T) {
		bool_t::m_value = value;		
	}		

	bool_t::bool_t(std::string raw_value) : IBasicType(BOOL_T) {
		bool_t::m_value = raw_value == "true";		
	}		

	bool_t::bool_t(std::string key, bool value) : bool_t(value) {
		IType::key = key;
	}		

	bool_t::bool_t(std::string key, std::string raw_value) : bool_t(raw_value) {
		IType::key = key;
	}		

	bool bool_t::isRawBool(std::string raw_value) {
		return (raw_value == "true") || (raw_value == "false");
	}

	std::string bool_t::toString() {
		return m_value ? "true" : "false";
	}

	int bool_t::toInt() {
		return m_value;
	}

	bool bool_t::toBool() {
		return m_value;
	}

}

