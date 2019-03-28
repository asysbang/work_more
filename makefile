PROG = work-more
CC = g++ 
BINDIR = debian/work-more/usr/lib/work-more
INSTALL = cp 

CFLAGS    := `pkg-config --cflags gtk+-3.0`  # CFLAGS
LDFLAGS   := `pkg-config --libs gtk+-3.0`    # LDFLAGS

LOCAL_SRC_FILE := src/work_more.cpp \
	src/clipboard/clipboard_helper.cpp \
	src/gui/*.cpp \
	src/module/*.cpp

LOCAL_C_INCLUDES := includes

# Compile commands. 
$(PROG):src 

	$(CC) -o $(PROG) $(LOCAL_SRC_FILE)  $(CFLAGS) $(LDFLAGS) -I$(LOCAL_C_INCLUDES)
# make clean command. 
clean: 
	rm -rf $(PROG)

# make install command.
install:
	mkdir -p $(BINDIR)
	mkdir -p debian/work-more/usr/bin
	$(INSTALL) $(PROG) debian/work-more/usr/bin/
	$(INSTALL) -r img $(BINDIR)
	$(INSTALL) -r cfg $(BINDIR)

# make uninstall command.
uninstall:
	rm -rf $(BINDIR)
	rm debian/work-more/usr/bin/work-more




