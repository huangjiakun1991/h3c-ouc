BIN=h3c_ouc
OBJS=h3c_ouc.o authenticate.o
CFLAGS=-lpcap -lgcrypt

$(BIN): $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o  $@

%.o: %.c
	$(GCC) $(CFLAGS) -c $<

.PHONY: clean install uninstall

install:
	$(INSTALL) -d /usr/local/bin
	$(INSTALL) -p -D -m 0755 $(BIN) /usr/local/bin

uninstall:
	$(RM) /usr/local/bin/$(BIN)

clean:
	$(RM) $(OBJS) $(BIN)
