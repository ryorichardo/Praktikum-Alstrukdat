#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean IsKataSama (Kata K1, Kata K2){
    boolean sama = (K1.Length == K2.Length);
    if (sama){
        int i = 0;
        while (i < K1.Length && sama){
            if (K1.TabKata[i] != K2.TabKata[i]){
                sama = false;
            }
            i++;
        }
    }
    return sama;
}

int main(){
    Kata titik, koma;
    titik.TabKata[0] = 'T';
    titik.TabKata[1] = 'I';
    titik.TabKata[2] = 'T';
    titik.TabKata[3] = 'I';
    titik.TabKata[4] = 'K';
    titik.Length = 5;

    koma.TabKata[0] = 'K';
    koma.TabKata[1] = 'O';
    koma.TabKata[2] = 'M';
    koma.TabKata[3] = 'A';
    koma.Length = 4;

    int reg = 0, pjg = 0, i, count = 0;

    STARTKATA();
    IgnoreBlank();
    boolean first = true;
    while (!EndKata){
        if (!IsKataSama(CKata, titik) && !IsKataSama(CKata, koma)){
            if (CKata.Length < 10){
                reg ++;
            }
            else{
                pjg++;
            }
            if (!first && CKata.Length > 0){
                printf(" ");
            }
            first = false;
            for (i = 0; i < CKata.Length; i++){
                printf("%c", CKata.TabKata[i]);
            }
        }
        else if (IsKataSama(CKata, titik)){
            printf(".");
        }
        else if (IsKataSama(CKata, koma)){
            printf(",");
        }
        count++;
        ADVKATA();
    }

    int harga;
    if (count > 10){
        harga = 0.9*(1000*reg + 1500*pjg); 
    }
    else{
        harga = 1000*reg + 1500*pjg;
    }

    printf("\n%d\n%d\n%d\n", reg, pjg, harga);
    return 0;
}