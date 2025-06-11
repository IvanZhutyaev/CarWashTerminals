#ifndef BOOL_T_H
#define BOOL_T_H

#include "ibasictype.h"

namespace cm {
 
	class bool_t : public IBasicType {

		public:
			explicit bool_t(std::string key, bool value);			
			explicit bool_t(std::string key, std::string raw_value);			
			explicit bool_t(bool value);			
			explicit bool_t(std::string raw_value);			

			std::string toString() override;
			int toInt() override;
			bool toBool() override;

			static bool isRawBool(std::string raw_value);

		private:
			bool m_value;
	};

}


#endif
