#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("(3+9)+3*(4+5)");


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

