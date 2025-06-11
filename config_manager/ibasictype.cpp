#include "ibasictype.h"

namespace cm {
	
	IBasicType::IBasicType(int class_type) : IType(class_type) {
	}

	IType *IBasicType::value(std::string key) {
		if (this->isKey(key))
			return this;
		
		throwInvalidArgument(key);
		return nullptr;
	}
	
	array_t *IBasicType::toArray() {
		throwBadCast(ARRAY_T);
		return nullptr;
	}

	object_t *IBasicType::toObject() {
		throwBadCast(OBJECT_T);
		return nullptr;
	}

}

