AS = ${GBDKDIR}/bin/lcc -c
CC = ${GBDKDIR}/bin/lcc -Wa-l -Wl-m -Wl-j

BIN = universe.gb
OBJS =  main.o  player.o

all: $(BIN)

$(BIN): $(OBJS)
		$(CC) -o $(BIN) $(OBJS)

clean:
		rm -f $(BIN) $(OBJS) *~
