#include "itype.h"

namespace cm {
	IType::IType(int class_type) {
		IType::class_type = class_type;
	}

	std::string IType::getKey() {
		return key;
	}

	bool IType::isKey(std::string key) {
		return IType::key == key;
	}

	void IType::setKey(std::string key) {
		IType::key = key;
	}

	std::string IType::intToString(int value) {
		std::string svalue;
		std::stringstream sstream;

		sstream << value;
		sstream >> svalue;

		return svalue;
	}

	int IType::stringToInt(std::string value) {
		int ivalue;
		std::stringstream sstream;

		if (value.find_first_not_of("0123456789") != std::string::npos) {
			throw std::invalid_argument( "value contain non numbers" );
			return -1;
		}

		sstream << value;
		sstream >> ivalue;

		return ivalue;
	}

	bool IType::isExist(std::string key) {
		try {
			this->value(key);
			return true;
		} catch (std::invalid_argument &e) {
			return false;
		}
	}

	bool IType::isObject() { return class_type == OBJECT_T; }
	bool IType::isArray() { return class_type == ARRAY_T; }
	bool IType::isString() { return class_type == STRING_T; }
	bool IType::isInt() { return class_type == INT_T; }
	bool IType::isBool() { return class_type == BOOL_T; }


	const void IType::throwInvalidArgument(const std::string &key) {
		throw std::invalid_argument("parameter with key equal \"" + key + "\" does not exist");
	}

	const void IType::throwInvalidArgumentRawValue(const std::string &raw_value) {
		throw std::invalid_argument("value \"" + raw_value + "\" cant be converted to a type");
	}

	const void IType::throwOutOfRange(const std::string &id) {
		throw std::out_of_range("parameter with id equal \"" + id + "\" does not exist");
	}

	const void IType::throwBadCast(const int &cast_type) {
		throw std::runtime_error("Type " + class_type_ToString() + " cant be cast to " + class_type_ToString(cast_type));
	}

	const void IType::throwRunTimeError() {
		throw std::runtime_error("Append cant use to " + class_type_ToString());
	}

	std::string IType::class_type_ToString(int class_type) {
		if (class_type == NONE_T)
			class_type = IType::class_type;
		
		switch (class_type) {
			case NONE_T:
				throw std::invalid_argument("class_type dont set");
				break;
			case OBJECT_T:
				return "object_t";
			case ARRAY_T:
				return "array_t";
			case STRING_T:
				return "string_t";
			case INT_T:
				return "int_t";
			case BOOL_T:
				return "bool_t";
			default:
				throw std::invalid_argument("class_type: " + class_type_ToString() + "dont have string iplementation");
				break;
		}
	}

}
