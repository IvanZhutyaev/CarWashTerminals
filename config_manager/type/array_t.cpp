#include "array_t.h"

namespace cm {

	array_t::array_t() : IComplexType(ARRAY_T) {
	}

	array_t::~array_t() {

	}

	void array_t::append(IType *value) {
		IType *local_value = value;
		local_value->setKey(IType::intToString(length()));
		m_value.push_back(local_value);
	}

	IType *array_t::value(int id) {
		if (id > length() - 1)
			throwOutOfRange(intToString(id));
		return m_value.at(id);
	}

	int array_t::length() {
		return m_value.size();
	}
	
	std::string array_t::symBegin() {
		return SYM_BEGIN();
	}

	std::string array_t::symEnd() {
		return SYM_END();
	}

	bool array_t::needKey() {
		return NEED_KEY();
	}

	void array_t::append(std::string key, IType *value) { 
		append(value);
	}

	IType *array_t::value(std::string id) {
		return value(IType::stringToInt(id));
	}

	array_t *array_t::toArray() {
		return this;
	}

	object_t *array_t::toObject() {
		throwBadCast(OBJECT_T);
		return nullptr;
	}

}

