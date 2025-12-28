CC      := $(CROSS_COMPILE)gcc
CFLAGS  ?= -Wall -Wextra -Werror -O2
LDFLAGS ?=

TARGET  := writer
SRCS    := writer.c
OBJS    := $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
