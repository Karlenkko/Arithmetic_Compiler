#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole {
    public:
        Symbole() {}
        Symbole(int i) : ident(i) {  }
        virtual ~Symbole() { }
        operator int() const { return ident; }
        virtual void Affiche();
        virtual int getVal() {return -1;}
   protected:
      int ident{};
};

class Entier : public Symbole {
    public:
        Entier(int v) : Symbole(INT), valeur(v) { }
        ~Entier() { }
        virtual void Affiche();
        virtual int getVal() {return valeur;}
    protected:
        int valeur;
};

// symbole non terminal E
class Expr : public Symbole {
	public:
        Expr(int val) : Symbole(EXPR), valeur(val) {}
		~Expr() {}
		virtual void Affiche();
        virtual int getVal() {return valeur;};
	protected:
		int valeur;
};
