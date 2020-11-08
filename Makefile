
OBJFILES = $(patsubst %.c, %.o, src/lib/index.l)
TARGET   = lex-xd

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.c index.l && \
	yacc -d yacc.l -o  && \
	gcc lex.c yacc.c ../common/tokens.c -o ../../build/lex-xd

clean:
	rm -f $(TARGET) $(shell find . -name '*.h.gch') $(shell find . -name '*.o') $(shell find . -name '*.out') *~
run:
	./build/xd-compiler
test1:
	./build/xd-compiler < resources/input.txt
test2:
	./build/xd-compiler < resources/input2.txt
test3:
	./build/xd-compiler < resources/input3.txt
test:
	./init.sh
