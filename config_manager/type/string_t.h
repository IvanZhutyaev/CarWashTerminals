#ifndef STRING_T_H
#define STRING_T_H

#include "ibasictype.h"

namespace cm {
 
	class string_t : public IBasicType {

		public:
			explicit string_t(std::string key, std::string raw_value);			
			explicit string_t(std::string raw_value);			


			std::string toString() override;
			int toInt() override;
			bool toBool() override;

			static bool isRawString(std::string raw_value);

		private:
			std::string m_value;

			std::string replaceSpecialCharacters(std::string value);
	};

}


#endif
