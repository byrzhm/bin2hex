CXX = g++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++17 -O2
SRCS=bin2hex.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: bin2hex

bin2hex: $(OBJS)
	$(CXX) -o bin2hex $(OBJS)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $<

install: bin2hex
	cp bin2hex /usr/local/bin

clean:
	rm -f bin2hex $(OBJS)

.PHONY: all install clean