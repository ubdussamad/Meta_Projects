all: lex.exe

lex.exe: lex.o
	 gcc -o lex.exe lex.o

hello.o: lex.c
	 gcc -c lex.c

clean:
	rm lex.o lex.exe
