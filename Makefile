CFLAGS = -ansi -Wall -pedantic
LDFLAGS = -Wl,-s
P=test_getopt
CC=clang
ANALYZER=scan-build

all: $(P).c
	$(ANALYZER) $(CC) $(CFLAGS) $(LDFLAGS) $(P).c -o $(P).exe

clean:
	rm -f $(P).exe
	
