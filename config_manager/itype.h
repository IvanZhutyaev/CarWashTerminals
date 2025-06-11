#ifndef ITYPE_H
#define ITYPE_H

#include <string>
#include <sstream>
#include <iostream>


namespace cm {

	class array_t;
	class object_t;

	class IType {
		public:
			IType(int class_type);
			virtual ~IType() = default;
			
			//friend object_t;
		
			//==============
			// function defined in this class	
			std::string getKey();	
			bool isKey(std::string key);
			void setKey(std::string key);
			//==============

			bool isExist(std::string key);

			virtual IType *value(std::string key) = 0;

			virtual array_t *toArray() = 0;
			virtual object_t *toObject() = 0;

			virtual std::string toString() = 0;
			virtual int toInt() = 0;
			virtual bool toBool()  = 0;

			bool isObject();
			bool isArray();
			bool isString();
			bool isInt();
			bool isBool();


		protected:
			enum ClassType {
				NONE_T = -1,
				OBJECT_T = 1,
				ARRAY_T,
				STRING_T,
				INT_T,
				BOOL_T,
			};
			

			std::string key;

			const void throwInvalidArgument(const std::string &key);
			static const void throwInvalidArgumentRawValue(const std::string &raw_value);
			const void throwOutOfRange(const std::string &id);
			const void throwBadCast(const int &cast_type);
			const void throwRunTimeError();

			std::string intToString(int value);
			int stringToInt(std::string value);
			
		private:
			int class_type;
 			//std::string key;
		
			std::string class_type_ToString(int class_type = NONE_T);

	};

}
#endif
