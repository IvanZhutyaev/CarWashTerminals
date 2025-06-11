#include "icomplextype.h"

namespace cm {

	IComplexType::IComplexType(int class_type) : IType(class_type) {
	}
	
	std::string IComplexType::toString() {
		throwBadCast(STRING_T);
		return "";
	}

	int IComplexType::toInt() {
		throwBadCast(INT_T);
		return -1;
	}

	bool IComplexType::toBool() {
		throwBadCast(BOOL_T);
		return false;
	}

}


