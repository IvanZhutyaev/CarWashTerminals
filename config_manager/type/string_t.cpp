#include "string_t.h"


namespace cm {

	string_t::string_t(std::string raw_value) : IBasicType(STRING_T) {
		if (isRawString(raw_value)) {
			// remove double quotes
			raw_value = raw_value.substr(1, raw_value.length() - 2);

			// replace special characters
			// list of character available in function body
			raw_value = replaceSpecialCharacters(raw_value);
		}

		string_t::m_value = raw_value;		
	}

	string_t::string_t(std::string key, std::string raw_value) : string_t(raw_value) {
		IType::key = key;
	}		

	bool string_t::isRawString(std::string raw_value) {
		return (raw_value.at(0) == '"') && (raw_value.at(raw_value.length() - 1) == '"');
	}

	// support special character with length = 2 symbols
	std::string string_t::replaceSpecialCharacters(std::string value) {
		const int list_size = 3;
		const std::string find_char_list[list_size] = {"\\n", "\\\"", "\\\'"};
		const std::string replace_char_list[list_size] = {"\n", "\"", "\'"};

		std::size_t pos;
		std::string new_value = value;
		
		std::string new_special_character;
		for (int i = 0; i < list_size; i++) {
			pos = new_value.find(find_char_list[i]);
			while (pos != std::string::npos) {
				new_value.replace(pos, 2, replace_char_list[i]);
				pos = new_value.find(find_char_list[i]);
			}
		}

		return new_value;
	}


	std::string string_t::toString() {
		return m_value;
	}

	int string_t::toInt() {
		return stringToInt(m_value);

	}

	bool string_t::toBool() {
		return (!(m_value == "") || 
		 	 (m_value == "0") || 
			 (m_value == "false"));
	}

}

