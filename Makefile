
OBJFILES = $(patsubst %.c, %.o, src/index.l)
TARGET    = tp1

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src && \
	flex -o lex.c index.l && \
	gcc lex.c logger.c types.c -o ../build/tp1

clear:
	rm src/flex.c && \
	rm -f $(shell find . -name '*.o') $(shell find . -name '*.h.gch') *~
clean:
	rm -f $(OBJFILES) $(TARGET) $(shell find . -name '*.h.gch') *~
run:
	./build/tp1
test1:
	./build/tp1 < resources/input.txt
test2:
	./build/tp1 < resources/input2.txt
