#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


#include "itype.h"
#include "ibasictype.h"
#include "icomplextype.h"
#include "type/object_t.h"
#include "type/array_t.h"
#include "type/string_t.h"
#include "type/int_t.h"
#include "type/bool_t.h"

class ConfigManager {
	public:
		explicit ConfigManager(const std::string &path = "");

		enum errors {
			no,
			file_already_open,
			file_not_open,
		};

		void setFilePath(const std::string &path);
		int read(std::stringstream &buffer);
		int read(const std::string &path = "");
		cm::IType *rootObject();

		cm::IBasicType *create_type(std::string raw_value);

	private:
		const char SYMBOL_COMMENT = '#';
		std::string path;
		std::fstream *file;
		cm::object_t root_obj;


		int open(std::ios_base::openmode mode = std::fstream::in);
		int close();

		int parser(std::stringstream &buffer, cm::IComplexType *type, const std::string &expect = "");
		void removeSpaces(std::string *line);

};

#endif

