#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {
   string chaine("(((((3+9))+1*3)))*(((4))+5)");

   Automate *a = new Automate(chaine);
   a->run();
   return 0;
}

