#include "arraydin.c"

int main (){
    int maxel, q, i, op, x;
    TabInt T;
    scanf("%d", &maxel);
    MakeEmpty(&T, maxel);
    BacaIsi(&T);
    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d", &x);
            if (MaxEl(T) == Neff(T)){
                printf("array sudah penuh\n");
            }
            else{
                AddAsLastEl(&T, x);
                printf("%d ", MaxEl(T));
                TulisIsiTab(T);
                printf("\n");
            }
        }
        else if (op == 2){
            scanf("%d", &x);
            GrowTab(&T, x);
            printf("%d ", MaxEl(T));
            TulisIsiTab(T);
            printf("\n");
        }
        else if (op == 3){   
            scanf("%d", &x);
            if (x > MaxEl(T)){
                printf("array terlalu kecil\n");
            }
            else{
                ShrinkTab(&T, x);
                printf("%d ", MaxEl(T));
                TulisIsiTab(T);
                printf("\n");
            }
        }
        else if (op == 4){
            CompactTab(&T);
            printf("%d ", MaxEl(T));
            TulisIsiTab(T);
            printf("\n");
        }
    }
    return 0;
}