#include <iostream>
#include <regex>
#include "Automate.h"
#include "state.h"

using namespace std;
Automate::Automate(string chaine){
    string trimmed = regex_replace(chaine, regex("\\s"), "");
    State0 * init = new State0();
    stateStack.push(init);
    this->lexer = new Lexer(trimmed);
}
void Automate::run() {
    bool flag = true;
    Symbole * s;
    while (flag) {
        s = lexer->Consulter();
        lexer->Avancer();
        flag = stateStack.top()->transition(*this, s);
    }
    delete s;
    cout << "Le resultat de " << lexer->getFlux() <<" est:" << endl;
    symboleStack.top()->Affiche();
    cout << endl;
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
	for(int i = 0; i < n; i ++) {
	    delete calculation[i];
	}
	// empiler la partie gauche
	stateStack.top()->transition(*this, new Expr(val));
	lexer->retournerSymbole(symbole);
}

Automate::~Automate(){
    while (!stateStack.empty()) {
        delete stateStack.top();
        stateStack.pop();
    }
    while (!symboleStack.empty()) {
        delete symboleStack.top();
        symboleStack.pop();
    }
    delete lexer;
}