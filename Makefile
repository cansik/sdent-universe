CC = ${GBDKDIR}/bin/lcc -Wa-l -Wl-m -Wl-j

SRC = $(shell find ./src -name *.c)
OBJ = $(SRC:%.c=%.o)
BIN = bin/main.gb

all: $(BIN)

$(BIN): $(OBJ)
		$(CC) -o $(BIN) $(OBJ)

%.o: %.c
		$(CC) -c $< -o $@

clean:
		rm -f $(BIN) $(OBJS) *~
