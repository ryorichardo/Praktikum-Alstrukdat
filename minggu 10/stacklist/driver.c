#include "stacklist.c"

void PrintForward (Stack L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = Top(L);
    printf("[");
    while (P != Nil){
        printf("%d,", Info(P));
        P = Next(P);
    }
    printf("]");
}

int main(){
    Stack Q;
    CreateEmpty(&Q);
    int i;
    for(i = 0; i < 5; i++){
        Push(&Q, i);
    }
    PrintForward(Q);
    printf("\n");
    Pop(&Q, &i);
    PrintForward(Q);
    return 0;
}