
SOURCES=ledapp.c
EXECUTABLE=ledapp
LIBRARIES=
CFLAGS=-Wall

ifneq ($(ARCH),target)
CC=gcc
DIR=host/
EXE=$(EXECUTABLE)
else
CC=arm-angstrom-linux-gnueabi-gcc
DIR=target/
EXE=$(addsuffix .target,$(EXECUTABLE))
endif

OBJECTS=$(SOURCES:%.c=$(DIR)%.o)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LIBRARIES)

$(DIR)%.o: %.c $(DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR):
	@mkdir $(DIR)

clean:
	@rm $(OBJECTS) $(EXE)
	@rmdir $(DIR)

help:
	@echo "Instructions for makefile:"
	@echo "make [OPTIONS]                 make for host"
	@echo "make ARCH=target [OPTIONS]     make for target"
	@echo "OPTIONS:"
	@echo "clean          removes objects directory and executable"