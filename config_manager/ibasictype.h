#ifndef IBASETYPE_H
#define IBASETYPE_H

#include "itype.h"

//#include "string_t.h"
//#include "int_t.h"
//#include "bool_t.h"

namespace cm {

	class IBasicType : public IType {
		public:
			IBasicType(int class_name);

			IType *value(std::string key) override;

			array_t *toArray() override;
			object_t *toObject() override;
			
	};

}

#endif
