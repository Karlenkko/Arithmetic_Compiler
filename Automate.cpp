#include <iostream>
#include "Automate.h"
#include "state.h"

using namespace std;
Automate::Automate(string chaine){
    State0 * init = new State0();
    stateStack.push(init);
    this->lexer = new Lexer(chaine);
}
void Automate::run() {
    bool flag = true;
    while (flag) {
        Symbole * s = lexer->Consulter();
        lexer->Avancer();
        flag = stateStack.top()->transition(*this, s);
    }
    cout << "Le resultat de " << lexer->getFlux() <<" est:" << endl;
    symboleStack.top()->Affiche();
}

void Automate::decaler (Symbole * symbole, State * state) {
	stateStack.push(state);
	symboleStack.push(symbole);
}

void Automate::reduire (Symbole * symbole, int n) {
	int val = 0;
	Symbole * calculation[3];
	// depiler
	for(int i = 0; i < n; ++ i) {
        delete (stateStack.top());
		stateStack.pop();
		calculation[i] = symboleStack.top();
		symboleStack.pop();
	}
	// calculer val
	if (n == 1) {
		val = calculation[0]->getVal();
	} else if (n == 3) {
		if (*calculation[0] == CLOSEPAR && *calculation[2] == OPENPAR) {
			val = calculation[1]->getVal();
		} else if (*calculation[1] == MULT) {
			val = calculation[0]->getVal() * calculation[2]->getVal();
		} else if (*calculation[1] == PLUS) {
			val = calculation[0]->getVal() + calculation[2]->getVal();
		}
	}
	// empiler la partie gauche
	stateStack.top()->transition(*this, new Expr(val));
	lexer->retournerSymbole(symbole);
}
