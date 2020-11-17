/* File: listrek.h */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */


#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

//#define Nil NULL

/* Definisi Type */
//typedef int infotype;
//typedef struct tElmtlist *address;
//typedef struct tElmtlist { 
//	infotype info;
//	address next;
//} ElmtList;

/* Definisi list : */
/* List kosong : L = Nil */
//typedef address List;

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
//#define Info(P) (P)->info
//#define Next(P) (P)->next

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
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

void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    Next(P) = Nil;
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
    return (L == Nil);
}

int IsOneElmt(List L){
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
    return (!IsEmpty(L) && Next(L) == Nil);
}

/* *** Selektor *** */
infotype FirstElmt (List L){
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
    return (Info(L));
}

List Tail(List L){
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
    return (Next(L));
}

/* *** Konstruktor *** */
List Konso(infotype e, List L){
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
    address P = Alokasi(e);
    if (P != Nil){
        Next(P) = L;
        return P;
    }
    return L;
}

List KonsB(List L, infotype e){
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
    if (IsEmpty(L)){
        address P = Alokasi(e);
        return P;
    }
    else{
        Next(L) = KonsB(Tail(L),e);
        return L;
    }
}

/* *** Operasi Lain *** */
List Copy (List L){
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
    if (IsEmpty(L)){
        return Nil;
    }
    else{
        return (Konso(FirstElmt(L), Copy(Tail(L))));
    }
}

void MCopy (List Lin, List *Lout){
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
    if (IsEmpty(Lin)){
        *Lout = Nil;
    }
    else{
        List Ltemp;
        MCopy(Tail(Lin), &Ltemp);
        *Lout = Konso(FirstElmt(Lin), Ltemp);
    }
}

List Concat (List L1, List L2){
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
    if (IsEmpty(L1)){
        return Copy(L2);
    }
    else{
        return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
    }
}

void MConcat (List L1, List L2, List *LHsl){
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
    if (IsEmpty(L1)){
        *LHsl = Copy(L2);
    }
    else{
        List Ltemp;
        MConcat(Tail(L1), L2, &Ltemp);
        *LHsl = Konso(FirstElmt(L1), Ltemp);
    }
}

void PrintList (List L){
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
    if (!IsEmpty(L)){
        printf("%d\n", Info(L));
        PrintList(Tail(L));
    }
}

int NbElmtList (List L){
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
    if (IsEmpty(L)){
        return 0;
    }
    else{
        return (1 + NbElmtList(Next(L)));
    }
}

boolean Search (List L, infotype X){
/* Mengirim true jika X adalah anggota list, false jika tidak */
    if (IsEmpty(L)){
        return false;
    }
    else{
        if (Info(L) == X){
            return true;
        }
        else{
            return Search(Next(L), X);
        }
    }
}