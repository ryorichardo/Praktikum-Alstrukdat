/* Ryo Richardo 13519193 */
/* Praktikum 3 */
/* Soal 2 */
#include "arraypos.h"
#include <stdio.h>

int main(){
    TabInt T, Tasc, Tdesc;
    BacaIsi(&T);
    Tasc = T;
    Tdesc = T;

    Sort(&Tasc, true);
    Sort(&Tdesc, false);

    if (IsEQ(T, Tasc) && IsEQ(T, Tdesc)){
        printf("Array monotonik statik\n");
    }
    else if (IsEQ(T, Tasc) && !IsEQ(T, Tdesc)){
        printf("Array monotonik tidak mengecil\n");
    }
    else if (!IsEQ(T, Tasc) && IsEQ(T, Tdesc)){
        printf("Array monotonik tidak membesar\n");
    }
    else{
        printf("Array tidak monotonik\n");
    }
    
    return 0;
}