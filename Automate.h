#pragma once
#include <stack>
class State;

class Automate {
	public:
		Automate () {};
		void decaler (Symbole * symbole, State * state);
		void reduire (Symbole * symbole, int n);
	protected:
		stack <State *> stateStack;
		stack <Symbole *> symboleStack;
		Lexer * lexer;
}
