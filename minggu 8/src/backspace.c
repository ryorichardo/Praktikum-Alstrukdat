# include "stackt.h"

int main(){
    int n, m, i, x;
    Stack A, B;
    CreateEmpty(&A);
    CreateEmpty(&B);
    scanf("%d %d", &n, &m); //scan jumlah n dan m
    for(i = 0; i < n; i++){ //scan elemen A sebanyak n
        scanf("%d", &x);
        if (x == 0){ //jika scan bil 0
            if (!IsEmpty(A)){ //jika A masih berisi, delete 1 element
                Pop(&A, &x);
            }
        }
        else{ //jika scan selain 0, push
            Push(&A, x);
        }
    }
    for(i = 0; i < m; i++){ //scan elemen B sebanyak m, sisanya mirip2 sm A
        scanf("%d", &x);
        if (x == 0){
            if (!IsEmpty(B)){
                Pop(&B, &x);
            }
        }
        else{
            Push(&B, x);
        }
    }
    boolean ans = true;
    if (Top(A) != Top(B)){ //jika indeks last A != B (jumlah A != jumlah B)
        ans = false;
    }
    else{
        while (!IsEmpty(A) && !IsEmpty(B) && ans){ //membandingkan setiap elemen hingga habis atau berbeda
            Pop(&A, &i);
            Pop(&B, &x);
            if (i != x){
                ans = false;
            }
        }
    }
    if(ans){
        printf("Sama\n");
    }
    else{
        printf("Tidak sama\n");
    }
    return 0;
}