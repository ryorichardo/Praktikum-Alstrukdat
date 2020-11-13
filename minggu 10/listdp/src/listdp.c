/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

//#define Nil NULL

/* Definisi Type Data */
//typedef int infotype;
//typedef struct tElmtlist *address;
//typedef struct tElmtlist { 
//	infotype info;
//	address next;
//	address prev;
//} ElmtList;
//typedef struct {
//	address First;
//	address Last;
//} List;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
//#define Info(P) (P)->info
//#define Next(P) (P)->next
//#define Prev(P) (P)->prev
//#define First(L) ((L).First)
//#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return(First(L) == Nil && Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    address P;
    P = (address) malloc(sizeof(infotype));
    if (P == Nil){
        return Nil;
    }
    else{
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
        return P;
    }
}

void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    Next(P) = Nil;
    Prev(P) = Nil;
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Prec == Last(*L)){
        InsertLast(L, P);
    }
    else{
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
    }
}

void InsertBefore (List *L, address P, address Succ){
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    if (Succ == First(*L)){
        InsertFirst(L, P);
    }
    else{
        Next(P) = Succ;
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
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
    if (First(*L) == Nil){
        Last(*L) = Nil;
    }
    else{
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    Last(*L) = Prev(*P);    
    if (Last(*L) == Nil){
        First(*L) = Nil;
    }
    else{
        Next(Last(*L)) = Nil;
    }
}

void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X);
    if (P == First(*L)){
        DelFirst(L, &P);
    }
    else if (P == Last(*L)){
        DelLast(L, &P);
    }
    else if (P != Nil){
        address Prec = Prev(P);
        DelAfter(L, &P, Prec);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    if (Prec != Last(*L)){
        if (Next(Prec) == Last(*L)){
            DelLast(L, Pdel);
        }
        else{
            *Pdel = Next(Prec);
            Next(Prec) = Next(*Pdel);
            Prev(Next(*Pdel)) = Prec;
        }
    }
}

void DelBefore (List *L, address *Pdel, address Succ){
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    if (Succ != First(*L)){
        if (Prev(Succ) == First(*L)){
            DelFirst(L, Pdel);
        }
        else{
            *Pdel = Prev(Succ);
            Prev(Succ) = Prev(*Pdel);
            Next(Prev(*Pdel)) = Succ;
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = First(L);
    printf("[");
    while (P != Last(L)){
        printf("%d,", Info(P));
        P = Next(P);
    }
    printf("%d]", Info(P));
}

void PrintBackward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = Last(L);
    printf("[");
    while (P != First(L)){
        printf("%d,", Info(P));
        P = Prev(P);
    }
    printf("%d]", Info(P));
}
