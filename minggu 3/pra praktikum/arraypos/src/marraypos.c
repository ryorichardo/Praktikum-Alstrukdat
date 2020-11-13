/* Ryo Richardo 13519193 */
/* Praktikum 3 */
/* Soal 1 */
#include "arraypos.c"
#include <stdio.h>

int main(){
    TabInt T;
    int x;
    BacaIsi(&T);
    scanf("%d", &x);
    TulisIsiTab(T);
    if (Search1(T, x) == IdxUndef){
        printf("\n%d tidak ada\n", x);
    }
    else{
        printf("\n%d\n", Search1(T, x));
    }

    Sort(&T, true);
    int min, max, med;
    min = Elmt(T, GetFirstIdx(T));
    max = Elmt(T, GetLastIdx(T));
    med = Elmt(T, (GetLastIdx(T)/2));

    if (x == max){
        printf("maksimum\n");
    }
    if (x == min){
        printf("minimum\n");
    }
    if (x == med){
        printf("median\n");
    }
    return 0;
}