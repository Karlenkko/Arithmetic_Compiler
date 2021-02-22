#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("1+3");


   Automate *a = new Automate(chaine);
   a->run();
//   Symbole * s;
//   while(*(s=l.Consulter())!=FIN) {
//      s->Affiche();
//      cout<<endl;
//      l.Avancer();
//   }
   return 0;
}

