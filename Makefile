CC = ${GBDKDIR}/bin/lcc
CFLAGS1 = -Wa-l -Wl-m -Wl-j
CFLAGS2 = -Wa-l -Wf-ba0

SRC = $(shell find ./src -name *.c)
OBJ = $(SRC:%.c=%.o)
BIN = bin/main.gb

all: $(BIN)

$(BIN): $(OBJ)
		$(CC) -o $(BIN) $(OBJ)

%aveScore.o: %aveScore.c
		$(CC) -c $< -o $@ $(CFLAGS2)

%.o: %.c
		$(CC) -c $< -o $@ $(CFLAGS1)

clean:
		rm -f $(BIN) $(OBJS) *~
