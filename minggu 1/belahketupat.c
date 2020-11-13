/* Ryo Richardo 13519193 */
/* Program belahketupat */
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    if (N % 2 == 1){
        int i, j, space = 1;
        space = (N+1)/2;
        for (i = 1; i <= space; i++){
            for (j = 1; j <= (space - i); j++){
                printf(" ");
            }
            for (j = 1; j <= (2*i -1); j++){
                printf("*");
            }
            printf("\n");
        }
        for (i = 1; i < space; i++){
            for (j = 1; j <= i; j++){
                printf(" ");
            }
            for (j = 1; j <= (N - 2*i); j++){
                printf("*");
            }
            printf("\n");
        }
    }
    else {
        printf("Masukan tidak valid");
    }
    return 0;
}
