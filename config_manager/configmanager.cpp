#include "configmanager.h"

ConfigManager::ConfigManager(const std::string &path) {
	setFilePath(path);
}

cm::IBasicType *ConfigManager::create_type(std::string raw_value) {
	if (cm::string_t::isRawString(raw_value)) {
		return new cm::string_t(raw_value);
	} else if (cm::int_t::isRawInt(raw_value)) {
		return new cm::int_t(raw_value);
	} else if (cm::bool_t::isRawBool(raw_value)) {
		return new cm::bool_t(raw_value);
	} 
	throw std::runtime_error("unknown type");
	return nullptr; 
}

void ConfigManager::setFilePath(const std::string &path) {
	ConfigManager::path = path;
}

int ConfigManager::open(std::ios_base::openmode mode) {
	file = new std::fstream();

	if (file->is_open()) 
		return errors::file_already_open;
	
	file->open(path, mode);

	if (!file->is_open()) 
		return errors::file_not_open;

	return errors::no;
}

int ConfigManager::close() {
	if (!file->is_open())
		return errors::file_not_open; 
	
	file->close();

	return 0;
}

cm::IType *ConfigManager::rootObject() {
	return &root_obj;
}

int ConfigManager::read(std::stringstream &buffer) {
	buffer.clear();
	buffer.seekg (0, buffer.beg);

	return parser(buffer, &root_obj);
}

int ConfigManager::parser(std::stringstream &buffer, cm::IComplexType *type, const std::string &expect) {
	std::string line;
	std::string key;
	std::string value;
	std::size_t pos;
	static int line_number;

	if (expect == "")
		line_number = 0;

	while (buffer.good()) {
		std::getline(buffer, line);
		line_number++;
		//std::cout << "line " << line_number << ": " << line << std::endl;

		removeSpaces(&line);

		// remove empty lines and comments
		if (line == "" || line.at(0) == SYMBOL_COMMENT)
			continue;

		if (line == expect)
			return 0;

		pos = line.find('=');  

		if (type->needKey()) {
			if (pos == std::string::npos)
				throw std::invalid_argument("expected '=' sumbol in line " + std::to_string(line_number));
			key = line.substr(0, pos);
			value = line.substr(pos + 1);
		} else {
			if (pos != std::string::npos)
				throw std::invalid_argument("symbol '=' unexpected in line " + std::to_string(line_number));
			value = line;
		}

		// object type that needed keyword
		if (value == cm::object_t::SYM_BEGIN()) {
			cm::object_t *tmp_obj = new cm::object_t();
			parser(buffer, tmp_obj, cm::object_t::SYM_END());
			type->append(key, tmp_obj);
		// array type that needed keyword
		} else if (value == cm::array_t::SYM_BEGIN()) {
			cm::array_t *tmp_arr = new cm::array_t();
			parser(buffer, tmp_arr, cm::array_t::SYM_END());
			type->append(key, tmp_arr);
		// other types
		} else
			type->append(key, create_type(value));
	}

	// geconfig_file.rnerate error if file ended and function 
	// expect symbol of close block
	// e.g. reading array_t that starting with "["
	// inside root object then file ended and 
	// function still expection close symbol "]"
	// raise error
	return expect == "" ? 0 : throw std::invalid_argument("expected '" + expect + "' sumbol in line " + std::to_string(line_number));
}


int ConfigManager::read(const std::string &path) {
	std::stringstream buff;

	if (path != "")
		setFilePath(path);
	open();
	buff << file->rdbuf();
	read(buff);
	close();

	return 0;
}

void ConfigManager::removeSpaces(std::string *line) {
	bool flag_isstring = false;
	std::string newline = "";
	std::string line_copy = *line;
	for (int i = 0; line_copy[i]; i++) {
		// if found \" then is string. Set flag to true. 
		// If \" found again then string end. Set flag to false.
		if ((line_copy[i] == '\"') && (line_copy[i-1] != '\\'))
			flag_isstring = !flag_isstring;
		
		// skip line if current symbol contain space(' ') or tab symbol ('\t')
		// and it is not string(is_string == false)
		if (((line_copy[i] == ' ') || (line_copy[i] == '\t')) && !flag_isstring)
			continue;

		newline += line_copy[i];
	}	
	*line = newline;
}

