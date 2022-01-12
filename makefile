# the compiler: gcc for C program, define as g++ for C++
CC = g++
INCLUDE_HEADER:=-I./include/
SRC_FILES_LIST:=src/my_bank.cpp
include mb_utils/src.mk
include sb_data/src.mk
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall $(INCLUDE_HEADER)
LDFLAGS = -lpthread
# The build target 
TARGET = my_bank 
 
 $(TARGET): $(SRC_FILES_LIST)
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@
  all: $(TARGET)
 
  #$(TARGET): $(TARGET).cpp
  #this part for gstreamer code compilation
#	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_FILES_LIST) `pkg-config --cflags --libs gstreamer-1.0`
 
  clean:
	rm -f $(TARGET)

