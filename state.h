#pragma once
#include <string>
#include "Automate.h"
#include "Symbole.h"

using namespace std;

class State {
	public:
		State() {}
		State(string s) : name(s) {}
		virtual ~State() {}
		virtual bool transition (Automate &automate, Symbole * symbole) = 0;
	protected:
		string name;
};

class State0 : public State {
	public:
		State0();
        virtual ~State0() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State1 : public State {
	public:
		State1();
        virtual ~State1() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State2 : public State {
	public:
		State2();
        virtual ~State2() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State3 : public State {
	public:
		State3();
        virtual ~State3() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State4 : public State {
	public:
		State4();
        virtual ~State4() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State5 : public State {
	public:
		State5();
        virtual ~State5() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State6 : public State {
	public:
		State6();
        virtual ~State6() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State7 : public State {
	public:
		State7();
        virtual ~State7() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State8 : public State {
	public:
		State8();
        virtual ~State8() {}
		bool transition (Automate &automate, Symbole * symbole);
};
class State9 : public State {
	public:
		State9();
        virtual ~State9() {}
		bool transition (Automate &automate, Symbole * symbole);
};
