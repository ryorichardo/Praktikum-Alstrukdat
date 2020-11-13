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
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    while (P != Nil && Info(P) != X){
        P = Next(P);
    }
    return P;
}

boolean FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    address P1 = First(L);
    while(P1 != Nil && P1 != P){
        P1 = Next(P1);
    }
    return(P == P1);
}

address SearchPrec (List L, infotype X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    if (IsEmpty(L) || NbElmt(L) == 1){
        return Nil;
    }
    else{
        address P = First(L);
        while(Next(P) != Nil && Info(Next(P)) != X){
            P = Next(P);
        }
        if (Next(P) == Nil){
            return Nil;
        }
        return P;
    }
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

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
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

address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    address P = First(L), max = First(L);
    while (P != Nil){
        if (Info(P) > Info(max)){
            max = P;
        }
        P = Next(P);
    }
    return max;
}

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

address AdrMin (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    address P = First(L), min = First(L);
    while (P != Nil){
        if (Info(P) < Info(min)){
            min = P;
        }
        P = Next(P);
    }
    return min;
}

float Average (List L){
/* Mengirimkan nilai rata-rata info(P) */
    address P = First(L);
    int sum = 0, count = 0;
    while(P != Nil){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    if (count == 0){
        return 0;
    }
    return (sum/count);
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    address P = First(*L);
    while (!IsEmpty(*L)){
        First(*L) = Next(P);
        Dealokasi(&P);
        P = First(*L);
    }
}

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    address P, S, fst;
    fst = First(*L);
    DelLast(L, &P);
    InsertFirst(L, P);
    S = First(*L);
    while (P != fst){
        DelLast(L, &P);
        InsertAfter(L, P, S);
        S = Next(S);
    }
    InsertLast(L, P);
}

List FInversList (List L){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    InversList(&L);
    return L;
}

void CopyList (List *L1, List *L2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    First(*L2) = First(*L1);
}

List FCopyList (List L){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    address P = First(L), P1;
    List L1;
    if (IsEmpty(L)){
        First(L1) = Nil;
    }
    else{
        InsertFirst(&L1, P);
        Next(P);
        while(P != Nil){
            P1 = Alokasi(Info(P));
            InsertAfter(&L1, P1, P);
            P = Next(P);
        }
    }
    return L1;
}

void CpAlokList (List Lin, List *Lout){
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
    *Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
    List L4 = FCopyList(L1), L5 = FCopyList(L2);
    Konkat1(&L4, &L5, L3);
}

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

void PecahList (List *L1, List *L2, List L){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

}
