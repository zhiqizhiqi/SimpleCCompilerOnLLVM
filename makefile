sc: lex.yy.o y.tab.o
	gcc lex.yy.o y.tab.o -o sc

lex.yy.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c y.tab.h: sa.y struct.h
	yacc -d sa.y

lex.yy.c: la.l struct.h
	flex la.l

clean:
	rm  lex.* y.tab.* 
