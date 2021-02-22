#include "state.h"

State0::State0() : State("E0") {}
State1::State1() : State("E1") {}
State2::State2() : State("E2") {}
State3::State3() : State("E3") {}
State4::State4() : State("E4") {}
State5::State5() : State("E5") {}
State6::State6() : State("E6") {}
State7::State7() : State("E7") {}
State8::State8() : State("E8") {}
State9::State9() : State("E9") {}

bool State0::transition(Automate &automate, Symbole * symbole) {
	switch (*symbole){
		case INT:
			automate.decaler(symbole, new State3);
			break;
		case OPENPAR:
			automate.decaler(symbole, new State2);
			break;
		case EXPR:
			automate.decaler(symbole, new State1);
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return false;
	}
	return true;
}

bool State1::transition(Automate &automate, Symbole * symbole) {
	switch (*symbole){
		case PLUS:
			automate.decaler(symbole, new State4);
			break;
		case MULT:
			automate.decaler(symbole, new State5);
			break;
		case FIN:
		    return false;
        default:
            automate.decaler(new Symbole(ERREUR), NULL);
            return false;
	}
	return true;
}

bool State2::transition(Automate &automate, Symbole * symbole) {
	switch (*symbole){
		case INT:
			automate.decaler(symbole, new State3);
			break;
		case OPENPAR:
			automate.decaler(symbole, new State2);
			break;
		case EXPR:
			automate.decaler(symbole, new State6);
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return false;
	}
	return true;
}

// regle 5
bool State3::transition(Automate &automate, Symbole * symbole) {
	if(*symbole == PLUS || *symbole == MULT || *symbole == CLOSEPAR || *symbole == FIN) {
		automate.reduire(symbole, 1);
	} else {
		automate.decaler(new Symbole(ERREUR), NULL);
		return false;
	}
	return true;
}

bool State4::transition(Automate &automate, Symbole * symbole) {
	switch (*symbole){
		case INT:
			automate.decaler(symbole, new State3);
			break;
		case OPENPAR:
			automate.decaler(symbole, new State2);
			break;
		case EXPR:
			automate.decaler(symbole, new State7);
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return false;
	}
	return true;
}

bool State5::transition(Automate &automate, Symbole * symbole) {
	switch (*symbole){
		case INT:
			automate.decaler(symbole, new State3);
			break;
		case OPENPAR:
			automate.decaler(symbole, new State2);
			break;
		case EXPR:
			automate.decaler(symbole, new State8);
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return false;
	}
	return true;
}

bool State6::transition(Automate &automate, Symbole * symbole) {
	switch (*symbole) {
		case PLUS:
			automate.decaler(symbole, new State4);
			break;
		case MULT:
			automate.decaler(symbole, new State5);
			break;
		case CLOSEPAR:
			automate.decaler(symbole, new State9);
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return false;
	}
	return true;
}

bool State7::transition(Automate &automate, Symbole * symbole) {
	if(*symbole == PLUS || *symbole == CLOSEPAR || *symbole == FIN) {
		// regle 2
		automate.reduire(symbole, 3);
	} else if (*symbole == MULT) {
		automate.decaler(symbole, new State5);
	} else {
		automate.decaler(new Symbole(ERREUR), NULL);
		return false;
	}
	return true;
}

// regle 3
bool State8::transition(Automate &automate, Symbole * symbole) {
	if(*symbole == PLUS || *symbole == MULT || *symbole == CLOSEPAR || *symbole == FIN) {
		automate.reduire(symbole, 3);
	} else {
		automate.decaler(new Symbole(ERREUR), NULL);
		return false;
	}
	return true;
}

// regle 4
bool State9::transition(Automate &automate, Symbole * symbole) {
	if(*symbole == PLUS || *symbole == MULT || *symbole == CLOSEPAR || *symbole == FIN) {
		automate.reduire(symbole, 3);
	} else {
		automate.decaler(new Symbole(ERREUR), NULL);
		return false;
	}
	return true;
}
