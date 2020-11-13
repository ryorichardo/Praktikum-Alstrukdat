/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */
#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

//#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
//typedef struct {
//    int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
//    char info;  /* elemen karakter */
//} infotype;
//typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
//typedef struct {
//    infotype * T;   /* tabel penyimpan elemen */
//    address HEAD;  /* alamat penghapusan */
//    address TAIL;  /* alamat penambahan */
//    int MaxEl;     /* Max elemen queue */
//} PrioQueueChar;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueChar, maka akses elemen : */
//#define Prio(e)     (e).prio
//#define Info(e)     (e).info
//#define Head(Q)     (Q).HEAD
//#define Tail(Q)     (Q).TAIL
//#define InfoHead(Q) (Q).T[(Q).HEAD]
//#define InfoTail(Q) (Q).T[(Q).TAIL]
//#define MaxEl(Q)    (Q).MaxEl
//#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)){
        return 0;
    }
    else{
        if (Head(Q) <= Tail(Q)){
            return (Tail(Q) - Head(Q) + 1);
        }
        else{
            return (MaxEl(Q) - Head(Q) + Tail(Q) + 1);
        }
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype*)malloc((Max)* sizeof (infotype)); 
    if ((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    if(IsEmpty(*Q)){
        Head(*Q)=0;
    }
    Tail(*Q) = (Tail(*Q)+1) % MaxEl(*Q);
    InfoTail(*Q) = X;
    int i = Tail(*Q);
    int j = (i + MaxEl(*Q)-1)% MaxEl(*Q);
    infotype temp;
    while (i != Head(*Q) && Prio(Elmt(*Q, i)) < Prio(Elmt(*Q, j))){
        temp = Elmt(*Q, i);
        Elmt(*Q, i) = Elmt(*Q, j);
        Elmt(*Q, j) = temp;
        i = j;
        j = (i + MaxEl(*Q) - 1)% MaxEl(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
    if (!IsEmpty(Q)){
        int count = 0, i = Head(Q);
        while (count < NBElmt(Q)){
            printf("%d %c\n", Prio(Elmt(Q,i)), Info(Elmt(Q,i)));
            i = (i+1)%NBElmt(Q);
            count++;
        }
    }
    printf("#\n");
}