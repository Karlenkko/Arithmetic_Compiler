#pragma once
#include <stack>
#include "lexer.h"
#include "symbole.h"
using namespace std;

class State;

class Automate {
	public:
        Automate(string chaine);
        void decaler (Symbole * symbole, State * state);
		void reduire (Symbole * symbole, int n);
		void run();
		~Automate();
	protected:
		stack <State *> stateStack;
		stack <Symbole *> symboleStack;
		Lexer * lexer;
};
