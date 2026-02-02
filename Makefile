CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

BUILD = build
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(BUILD)/%.o)
BIN = $(BUILD)/glowshroom

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin


all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

install: $(BIN)
	install -d $(BINDIR)
	install -m 755 $(BIN) $(BINDIR)/glowshroom

uninstall:
	rm -f $(BINDIR)/glowshroom

.PHONY: all clean install uninstall
