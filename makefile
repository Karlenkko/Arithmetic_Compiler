ECHO = @echo
RM = rm
COMP = g++
EDL = g++
CPPFLAGS = ##-ansi -pedantic -Wall -Wextra -std=c++11
PROGS = arithmetic_compiler
.O = Automate.o lexer.o state.o symbole.o main.o
all: $(PROGS)

Automate.o: Automate.cpp Automate.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

lexer.o: lexer.cpp lexer.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

state.o: state.cpp state.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

symbole.o: symbole.cpp symbole.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<
main.o: main.cpp
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

arithmetic_compiler: $(.O)
	$(ECHO) "edl de $^"
	$(COMP) -o $@ $^

efface:
	rm $(.O) $(PROGS) 
