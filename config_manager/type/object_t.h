#ifndef OBJECT_T_H
#define OBJECT_T_H 

#include <vector>

#include "icomplextype.h"

namespace cm {

	class object_t : public IComplexType {
		public:
			object_t();
			explicit object_t(std::string key);
			~object_t();

			static std::string ROOT_OBJECT() { return "salt*root_object_key*salt"; };

			static std::string SYM_BEGIN() { return "{"; };
			static std::string SYM_END() { return "}"; };
			static bool NEED_KEY() { return true; };

			IType *value(int id);
			int length();
			
			// interface method
			std::string symBegin() override;
			std::string symEnd() override; 
			bool needKey() override;
			void append(std::string key, IType *value) override;
			IType *value(std::string key) override;

			array_t *toArray() override;
			object_t *toObject() override;

		private:

			std::vector<IType*> m_value; 
	};
}

#endif
