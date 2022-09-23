CC = g++
CFLAGS =# -D NDEBUG
include ../debugflags
EXE = eo
SOURCES = main.cpp
INCLUDES_DIR = inc
include $(INCLUDES_DIR)/sorting/Makefile
include $(INCLUDES_DIR)/text/Makefile
include $(INCLUDES_DIR)/text/partitions/line/Makefile

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
 
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJECTS)

