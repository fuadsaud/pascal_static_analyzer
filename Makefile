CC         = clang
CFLAGS     = -x c++ -l stdc++
LEX        = flex
LEX_FLAGS  = -l
YACC       = bison
YACC_FLAGS = -d
FIXTURE    = other_test.pas
LEXER      = lex.yy.c
LEXER_DEF  = pascal.l
PARSER     = pascal.tab.c
PARSER_H   = pascal.tab.h
PARSER_DEF = pascal.y
OUT        = pascal

run: compile
	./$(OUT) < $(FIXTURE)
lexer:
	$(LEX) $(LEX_FLAGS) -o $(LEXER) $(LEXER_DEF)
parser: lexer
	$(YACC) $(YACC_FLAGS) $(PARSER_DEF) -o $(PARSER)
compile: parser
	$(CC) $(CFLAGS) *.c *.cpp -o $(OUT)
clean:
	rm $(OUT) $(LEXER) $(LEXER_H) $(PARSER) $(PARSER_H)
