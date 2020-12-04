
OBJFILES = $(patsubst %.c, %.o, src/lib/index.l)
TARGET   = lex-xd

all: build
build: $(TARGET)

$(TARGET): $(OBJFILES)
	cd ./src/lib && \
	flex -o lex.c index.l && \
	yacc -d yacc.l -o yacc.c  && \
	gcc lex.c yacc.c ../common/logger.c ../common/tokens.c ../common/scope.c -o ../../build/lex-xd

clean:
	rm -f $(TARGET) $(shell find . -name '*.h.gch') $(shell find . -name '*.o') $(shell find . -name '*.out') *~
run:
	./build/lex-xd
test1:
	./build/lex-xd < resources/teste.uai
test2:
	./build/lex-xd < resources/teste2.uai
test3:
	./build/lex-xd < resources/teste3.uai
test4:
	./build/lex-xd < resources/teste4.uai
test5:
	./build/lex-xd < resources/teste5.uai
test:
	./init.sh
