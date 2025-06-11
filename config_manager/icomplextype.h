#ifndef ICOMPLECTYPE_H
#define ICOMPLECTYPE_H

#include "itype.h"

namespace cm {

	class IComplexType : public IType {
		public:
			IComplexType(int class_type);

			virtual std::string symBegin() = 0;
			virtual std::string symEnd() = 0; 
			virtual bool needKey() = 0;
			virtual void append(std::string key, IType *value) = 0;

			std::string toString() override;
			int toInt() override;
			bool toBool() override;

	};

}


#endif
