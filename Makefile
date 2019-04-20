# This is my first Makefile
SRC = main.c Tree.c Node.c Grab.c Counter.c Buffer.c
OBJS = $(addsuffix .o, $(basename $(SRC)))
CFLAGS = -Wall
#Enable compilator's warnings
CFLSGS+= -o0
#assemble without optimisation, for deep debugging
CFLAGS+= -g3 -DDEBUG
EXECUTABLE=CLI
#required keys for adding "debug info" into executble file
.PHONY: all clean

all: $(SRC) $(EXECUTABLE)
$(EXECUTABLE): $(OBJS)
	gcc $(CFLAGS) $(OBJS)

%.o:%.c
	gcc $(CFLAGS) $< -c -o $*.o 

clean: 
	rm $(OBJS) a.out