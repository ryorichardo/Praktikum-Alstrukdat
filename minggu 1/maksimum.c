/* Ryo Richardo 13519193 */
/* Program Mencari nilai terbesar */
#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    int c;
    scanf("%d", &c);
    if (a >= b && a >= c){
        printf("%d \n", a);
    } else if (b >= a && b >= c){
        printf("%d \n", b);
    } else if (c >= a && c >= b){
        printf("%d \n", c);
    }
    return 0
}