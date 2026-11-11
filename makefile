mypreprocessor: main.o comment_removal.o file_inclusion.o macro_substitution.o 
	cc main.o comment_removal.o file_inclusion.o macro_substitution.o -o mypreprocessor
main.o: main.c
	cc -c main.c
comment_removal.o: comment_removal.c
	cc  -c comment_removal.c
file_inclusion.o: file_inclusion.c
	cc -c file_inclusion.c
macro_substitution.o: macro_substitution.c
	cc -c macro_substitution.c
clear:
	@echo "clearing up..."
	@rm -f *.o
