#include <iostream>
#include "lexer.h"
#include "Automate.h"

int main(int argc, char *argv[]) {
   string chaine("(((((3+9))+1* 3)))*(((4 ))+5)");
    if (argc > 1) {
        chaine = argv[1];
    }
   Automate a = Automate(chaine);
   a.run();
   return 0;
}

