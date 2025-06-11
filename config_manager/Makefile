ROOT_DIR = $(shell pwd)

CXX = /usr/bin/g++ 
#CXX = g++
CXXFLAGS = -g -Wall -fPIC

TARGET = libconfigmanager.so

INCLUDE = 

BDIR = $(ROOT_DIR)/build
CREATE_DIR = mkdir -p $(BDIR)
SDIR = $(ROOT_DIR)

HEADER_DIRS = $(SDIR)
INCLUDE += $(addprefix -I,$(HEADER_DIRS))

SRC_NAMES=$(shell find $(SDIR) -name '*.cpp' -exec basename {} ';')
SRCS_FULL=$(shell find $(SDIR) -name '*.cpp')
OBJ_NAMES=$(SRC_NAMES:.cpp=.o )
OBJS_FULL=$(foreach obj,$(OBJ_NAMES),$(BDIR)/$(obj))

HEADER_FILES_ROOT=$(shell find $(SDIR) -maxdepth 1 -name '*.h')
HEADER_FILES_TYPE=$(shell find $(SDIR)/type -maxdepth 1 -name '*.h')


DEPS := $(OBJ_NAMES:.o=.d)
DEPS_FULL=$(foreach dep,$(DEPS),$(BDIR)/$(dep))

#INC_DIRS := $(shell find $(SDIR) -type d)
#INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := -MMD -MP #$(INC_FLAGS)


all: $(BDIR)/$(TARGET)
	@echo Build done!
	mkdir -p $(BDIR)/lib
	mkdir -p $(BDIR)/include
	mkdir -p $(BDIR)/include/type
	cp $^ $(BDIR)/lib
	cp $(HEADER_FILES_ROOT) $(BDIR)/include
	cp $(HEADER_FILES_TYPE) $(BDIR)/include/type
	@echo Copy done!

$(BDIR)/$(TARGET): $(OBJS_FULL)
	$(CXX) $^ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE) -shared -o $@  

$(BDIR)/%.o: $(SDIR)/%.cpp
	$(CREATE_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(BDIR)/%.o: $(SDIR)/type/%.cpp
	$(CREATE_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(BDIR)/$(TARGET)
	rm -f $(DEPS_FULL)
	rm -f $(OBJS_FULL)
	rm -f $(BDIR)/lib/$(TARGET)
	rm -f $(BDIR)/include/*.h
	rm -f $(BDIR)/include/type/*.h
	@echo Clean done!

toproject:
	rm -f ../lib/configmanager/$(TARGET)
	rm -f ../include/configmanager/*.h
	rm -f ../include/configmanager/type/*.h
	mkdir -p ../include/configmanager/type
	cp $(BDIR)/lib/$(TARGET) ../lib/configmanager/
	cp $(shell find $(BDIR)/include -maxdepth 1 -name '*.h') ../include/configmanager/
	cp $(shell find $(BDIR)/include/type -maxdepth 1 -name '*.h') ../include/configmanager/type
	@echo Transfer files to project  done!


-include $(DEPS)

