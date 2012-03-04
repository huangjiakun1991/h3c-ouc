export DESUDIR = /usr/bin/
export CONFDIR = /usr/share/gh3c/
export DSKTDIR = /usr/share/applications/
export GCC=gcc
export RM=rm -f
export CP=cp
export INSTALL=install

.PHONY: CLI GUI clean

all: CLI GUI

CLI:
	@cd CLI && $(MAKE)

GUI: CLI
	$(CP) CLI/h3c_ouc GUI/

install: install-CLI install-GUI

install-CLI:
	@cd CLI && $(MAKE) install

install-GUI:
	@cd GUI && $(MAKE) install

uninstall: uninstall-CLI uninstall-GUI

uninstall-CLI:
	@cd CLI && $(MAKE) uninstall

uninstall-GUI:
	@cd GUI && $(MAKE) uninstall

clean:
	@cd CLI && $(MAKE) clean
	@cd GUI && $(MAKE) clean
