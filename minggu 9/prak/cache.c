#include "listlinier.h"
# include <stdlib.h>
# include <stdio.h>

int main(){
    int jumlah, aksi, i, j;
    scanf("%d", &jumlah);
    scanf("%d", &aksi);
    List L;
    address P, P1;
    CreateEmpty(&L);
    for (i = 1; i <= jumlah; i++){
        P = Alokasi(i);
        if (i == 1){
            InsertFirst(&L, P);
            P1 = P;
        }
        else{
            InsertAfter(&L, P, P1);
            P1 = P;
        }
    }
    for (i = 0; i < aksi; i++){
        scanf("%d", &j);
        if (Search(L, j) != Nil){
            DelP(&L, j);
            P = Alokasi(j);
            InsertFirst(&L, P);
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        }
        else{
            DelLast(&L,&P);
            P = Alokasi(j);
            InsertFirst(&L, P);
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
    }
}