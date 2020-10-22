
OBJFILES = $(patsubst %.c, %.o, src/index.l)
TARGET   = tp1

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src && \
	flex -o lex.c index.l && \
	gcc lex.c logger.c types.c -o ../build/tp1

clean:
	rm -f $(TARGET) $(shell find . -name '*.h.gch') $(shell find . -name '*.o') $(shell find . -name '*.out') *~
run:
	./build/tp1
test1:
	./build/tp1 < resources/input.txt
test2:
	./build/tp1 < resources/input2.txt
test3:
	./build/tp1 < resources/input3.txt
test:
	./init.sh
