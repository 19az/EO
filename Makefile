CC = g++
CFLAGS =
EXE = eo
SRCS = main.cpp lib/text/line.cpp lib/text/text.cpp lib/rwfile/rwfile.cpp lib/sorting/sorting.cpp lib/symbols/symbols.cpp lib/strings/strings.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS)
 
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJS)

