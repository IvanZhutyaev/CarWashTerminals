#ifndef ARRAY_T_H
#define ARRAY_T_H 

#include <vector>

#include "icomplextype.h"

namespace cm {

	class array_t : public IComplexType {
		public:
			array_t();
			~array_t();

			static std::string SYM_BEGIN() { return "["; };
			static std::string SYM_END() { return "]"; };
			static bool NEED_KEY() { return false; };


			void append(IType *value);
			IType *value(int id);
			int length();

			// interface method
			std::string symBegin() override;
			std::string symEnd() override; 
			bool needKey() override;
			void append(std::string key, IType *value) override;
			IType *value(std::string id) override;

			array_t *toArray() override;
			object_t *toObject() override;
			
		private:
			std::vector<IType*> m_value; 

	};
}

#endif
