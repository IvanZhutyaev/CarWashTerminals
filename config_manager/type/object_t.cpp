#include "object_t.h"

namespace cm {

	object_t::object_t() : IComplexType(OBJECT_T) {
		IType::key = ROOT_OBJECT();
	}

	object_t::object_t(std::string key) : IComplexType(OBJECT_T) {
		IType::key = key;
	}

	object_t::~object_t() {

	}

	IType *object_t::value(int id) {
		if (id > length() - 1)
			throwOutOfRange(intToString(id));
		return m_value.at(id);
	}

	int object_t::length() {
		return m_value.size();
	}

	std::string object_t::symBegin() { return SYM_BEGIN(); }
	std::string object_t::symEnd() { return SYM_END(); }
	bool object_t::needKey() { return NEED_KEY(); }

	void object_t::append(std::string key, IType *value) {
		IType *local_value = value;
		local_value->setKey(key);
		m_value.push_back(local_value);
	}

	IType *object_t::value(std::string key) {
		for (IType *parameter : m_value) {

			if (parameter->isKey(key))
				return parameter;
		}
		
		throwInvalidArgument(key);

		return nullptr;
	}

	array_t *object_t::toArray() {
		throwBadCast(ARRAY_T);
		return nullptr;
	}

	object_t *object_t::toObject() {
		return this;
	}

}

