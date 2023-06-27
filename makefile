CC = g++
CFLAGS = -std=c++11 -Wall

TARGET = EATON
SRCS = main.cpp Observer.cpp Device.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp Observer.h Device.h
	$(CC) $(CFLAGS) -c main.cpp

Observer.o: Observer.cpp Observer.h Device.h
	$(CC) $(CFLAGS) -c Observer.cpp

Device.o: Device.cpp Device.h Observer.h
	$(CC) $(CFLAGS) -c Device.cpp

clean:
	rm -f $(OBJS) $(TARGET)
