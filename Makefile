
OBJFILES = $(patsubst %.c, %.o, src/lex/index.l)
TARGET   = lex-xd

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lex && \
	flex -o lex.c index.l && \
	gcc lex.c ../common/logger.c ../common/types.c -o ../../build/lex-xd

clean:
	rm -f $(TARGET) $(shell find . -name '*.h.gch') $(shell find . -name '*.o') $(shell find . -name '*.out') *~
run:
	./build/lex-xd
test1:
	./build/lex-xd < resources/input.txt
test2:
	./build/lex-xd < resources/input2.txt
test3:
	./build/lex-xd < resources/input3.txt
test:
	./init.sh
