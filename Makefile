VERSION = 0.1
CC			= clang
PY      = python3
CFLAGS  = -Wall -O3  -Wpedantic -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

OBJ = main.o phi.o
SRC = $(OBJ:%.o=%.c) main.c docopt.c
HDR = $(OBJ:%.o=%.h)

BIN = private

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

docopt:
	$(PY) docopt_c/docopt_c.py -o docopt.c privatecalc.docopt

clean:
	rm -rfv $(BIN) $(OBJ) docopt.c

