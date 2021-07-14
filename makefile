# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  CFLAGS  = -g -Wall -Imb_utils
  LDFLAGS = -lpthread
  # The build target 
  TARGET = my_bank
 $(TARGET): my_bank.cpp mb_utils/mb_util.cpp
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@
  all: $(TARGET)
 
  #$(TARGET): $(TARGET).cpp
#	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp `pkg-config --cflags --libs gstreamer-1.0`
 
  clean:
	rm -f $(TARGET)

include mb_utils/src.mk