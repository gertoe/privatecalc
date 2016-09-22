VERSION = 0.1
CC			= clang
CFLAGS  = -Wall -O3  -Wpedantic -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

OBJ = main.o phi.o
SRC = $(OBJ:%.o=%.c) main.c
HDR = $(OBJ:%.o=%.h)

BIN = private

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	rm -rfv $(BIN) $(OBJ)

