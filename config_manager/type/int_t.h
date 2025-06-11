#ifndef INT_T_H
#define INT_T_H

#include "ibasictype.h"

namespace cm {
 
	class int_t : public IBasicType {
		public:
			explicit int_t(std::string key, int value);			
			explicit int_t(std::string key, std::string raw_value);			
			explicit int_t(int value);			
			explicit int_t(std::string raw_value);			

			std::string toString() override;
			int toInt() override;
			bool toBool() override;

			static bool isRawInt(std::string raw_value);

		private:
			int m_value;
	};

}


#endif
