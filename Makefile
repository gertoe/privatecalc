# ------------  settings  ------------------------------------------------------
VERSION = 0.3
CC			= clang
FLEX    = flex
COW     = bison

# DEBUG can be set to YES to include debugging info, or NO otherwise
#DEBUG := YES

# ------------  compiler flags  ------------------------------------------------
RELEASE_CFLAGS       := -Wall -O2 -Wpedantic -DBUILD=\"$(VERSION)\"
DEBUG_CFLAGS         := -Wall -O0 -Wpedantic -Wextra -pedantic -pg -ggdb $(DEFS) -DVERSION=\"$(VERSION)d\"

RELEASE_LDFLAGS      := -O2 -lrt -lm
DEBUG_LDFLAGS        := -ggdb -O1 -lrt -lm

# ------------  flags according to mode  ---------------------------------------
ifeq (YES, ${DEBUG})
	CFLAGS             := ${DEBUG_CFLAGS}
	LDFLAGS            := ${DEBUG_LDFLAGS}
else
	CFLAGS             := ${RELEASE_CFLAGS}
	LDFLAGS            := ${RELEASE_LDFLAGS}
endif

# ------------  make the targets  ----------------------------------------------
OBJ = main.o phi.o
SRC = lex.yy.c cmd.tab.c
PRI = $(OBJ:%.o=%.c)
HDR = $(OBJ:%.o=%.h)
CLI = lex.yy.c cmd.l cmd.y cmd.h cmd.tab.c cmd.tab.h

.PHONY:all clean
all: docopt privatecalc argtest

docopt:
	make -C ./docopt.c-1/
	./docopt.c-1/docopt cmd.docopt
	$(FLEX) cmd.l
	$(COW) -d cmd.y

privatecalc: $(SRC) $(PRI)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) $(PRI) -o privatecalc

argtest:
	$(CC) $(LDFLAGS) $(SRC) -O2 -DMAIN_EXAMPLE -o argtest

clean:
	make clean -C ./docopt.c-1/
	rm -rfv $(wildcard *.o *.out) $(CLI) docopt.c

tidy: clean
	rm -rfv privatecalc argtest
