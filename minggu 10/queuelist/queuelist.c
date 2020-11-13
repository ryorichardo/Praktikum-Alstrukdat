#include "queuelist.h"
#include <stdio.h>

/* Konstanta */
//#define Nil NULL

/* Deklarasi infotype */
//typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
//typedef struct tElmtQueue * address;
//typedef struct tElmtQueue { 
//	infotype Info;
//	address Next; 
//} ElmtQueue; 

/* Type queue dengan ciri HEAD dan TAIL : */
//typedef struct { 
//	address HEAD;  /* alamat penghapusan */
//	address TAIL;  /* alamat penambahan */
//} Queue;

/* Selektor */
//#define Head(Q) (Q).HEAD
//#define Tail(Q) (Q).TAIL
//#define InfoHead(Q) (Q).HEAD->Info
//#define InfoTail(Q) (Q).TAIL->Info
//#define Next(P) (P)->Next
//#define Info(P) (P)->Info

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
    *P = (address) malloc(sizeof(infotype));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
    Next(P) = Nil;
    free(P);
}

boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
   return (Head(Q) == Nil && Tail(Q) == Nil);
}

int NbElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
   if (IsEmpty(Q)){
      return 0;
   }
   else{
      int count = 1;
      address P = Head(Q);
      while (P != Tail(Q)){
         P = Next(P);
         count++;
      }
      return count;
   }
}

/*** Kreator ***/
void CreateEmpty(Queue * Q){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
   Head(*Q) = Nil;
   Tail(*Q) = Nil;
}

/*** Primitif Enqueue/Dequeue ***/
void Enqueue (Queue * Q, infotype X){
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
   address P; 
   Alokasi(&P, X);
   if (P != Nil){
      if (IsEmpty(*Q)){
         Head(*Q) = P;
         Tail(*Q) = P;
      }
      else{
         Next(Tail(*Q)) = P;
         Tail(*Q) = P;
      }
   }
}

void Dequeue(Queue * Q, infotype * X){
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
   *X = InfoHead(*Q);
   address P = Head(*Q);
   Head(*Q) = Next(P);
   if (Head(*Q) == Nil){
      Tail(*Q) = Nil;
   }    
   Dealokasi(P);
}