#include "matriks.c"

int main(){
    MATRIKS M;
    int max, min;
    BacaMATRIKS(&M, 3, 3);
    TulisMATRIKS(M);
    printf("\nrata rata baris 0 = %f\n", RataBrs(M, 0));
    printf("rata rata kolom 0 = %f\n", RataKol(M, 0));
    printf("jumlah elmt 1 di baris 0 = %d\n", CountXBrs(M, 0, 1));
    printf("jumlah elmt 1 di kolom 0 = %d\n", CountXKol(M, 0, 1));
    return 0;
}