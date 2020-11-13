/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

//#define Nil NULL

//typedef int infotype;
//typedef struct tElmtlist *address;
//typedef struct tElmtlist {
//	infotype info;
//	address next;
//} ElmtList;
//typedef struct {
//	address First;
//} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

//#define Info(P) (P)->info
//#define Next(P) (P)->next
//#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P;
    P = (address) malloc(sizeof(infotype));
    if (P == Nil){
        return Nil;
    }
    else{
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
}

void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    Next(*P) = Nil;
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    while (P != Nil && Info(P) != X){
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    if (P != Nil){
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    }
    else{
        address P1 = First(*L);
        while (Next(P1) != Nil){
            P1 = Next(P1);
        }
        Next(P1) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    if (!IsEmpty(*L)){
        if (Info(First(*L)) == X){
            address P = First(*L);
            First(*L) = Next(P);
            Next(P) = Nil;
            free(P);
        }
        else{
            address P = First(*L);
            while (Next(P) != Nil && Info(Next(P)) != X){
                P = Next(P);
            }
            if (Next(P) != Nil){
                address P1 = Next(P);
                Next(P) = Next(P1);
                Next(P1) = Nil;
                free(P1);
            }
        }
    }
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    if (NbElmt(*L) == 1){
        *P = First(*L);
        First(*L) = Nil;
    }
    else{
        address P1 = First(*L);
        while (Next(Next(P1)) != Nil){
            P1 = Next(P1);
        }
        *P = Next(P1);
        Next(P1) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    address P = First(L);
    if (P != Nil){
        printf("%d", Info(P));
        P = Next(P);
    }
    while (P != Nil){
        printf(",%d", Info(P));
        P = Next(P);
    }
    printf("]");
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int sum = 0;
    address P = First(L);
    while (P != Nil){
        sum++;
        P = Next(P);
    }
    return sum;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L){
/* Mengirimkan nilai Info(P) yang minimum */
    address P = First(L);
    infotype min = Info(P);
    while (P != Nil){
        if (Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
    address P = First(L);
    infotype max = Info(P);
    while (P != Nil){
        if (Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    if (IsEmpty(*L1)){
        First(*L3) = First(*L2);
    }
    else{
        First(*L3) = First(*L1);
        InsertLast(L3, First(*L2));
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}