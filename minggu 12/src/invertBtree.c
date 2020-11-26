#include "bintree.h"
void InvertBtree(BinTree *P){
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
    if (!IsTreeEmpty(*P)){
        InvertBtree(&Right(*P));
        InvertBtree(&Left(*P));
        MakeTree(Akar(*P), Right(*P), Left(*P), P);
    }
}