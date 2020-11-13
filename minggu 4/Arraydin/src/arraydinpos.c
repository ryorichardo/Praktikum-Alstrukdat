/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#include "arraydinpos.h"
#include <stdio.h>
#include <stdlib.h>

/*  Kamus Umum */
//#define IdxMin 0
/* Indeks minimum array */
//#define IdxUndef -1
/* Indeks tak terdefinisi*/
//#define ValUndef -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
//typedef int IdxType; /* type indeks */
//typedef int ElType;  /* type elemen tabel */
//typedef struct
//{
//  ElType *TI; /* memori tempat penyimpan elemen (container) */
//  int MaxEl;  /* ukuran elemen */
//} TabInt;
/* Indeks yang digunakan [IdxMin..MaxEl-1] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: semua elemen bernilai ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i terbesar
                                             sehingga T.TI[i] != ValUndef */

/* ********** SELEKTOR ********** */
//#define TI(T) (T).TI
//#define Elmt(T, i) (T).TI[(i)]
//#define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */ 
    TI(*T) = (int*)malloc(maxel* sizeof (ElType));
    MaxEl(*T) = maxel;
    int i;
    for (i = 0; i < maxel; i++){
        Elmt(*T, i) = ValUndef;
    }
}

void Dealokasi(TabInt *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    MaxEl(*T) = 0;
    free(T);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    int i = IdxMin;
    while ((Elmt(T, i) != ValUndef) && i < MaxEl(T)){
        i++;
    }
    return i;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (MaxEl(T));
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}

IdxType GetLastIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    if (IsEmpty(T)){
        return(IdxMin);
    }
    else{
        return (NbElmt(T)-1);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= GetFirstIdx(T)) && (i < MaxEl(T)));
}

boolean IsIdxEff(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NbElmt(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    int N;
    scanf("%d", &N);
    while ((N < IdxMin) || (N > MaxEl(*T))){
        scanf("%d", &N);
    }    
    int input;
    int i;
    for (i = IdxMin; i < N; i++){
        scanf("%d", &input);
        Elmt(*T, i) = input;
    }
}

void TulisIsiTab(TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
	printf("[");
	if (!IsEmpty(T)){
		int i;
		for (i = IdxMin; i <= GetLastIdx(T); i++){
			if (i == GetLastIdx(T)){
				printf("%d", Elmt(T, i));
			}
			else{
				printf("%d,", Elmt(T, i));
			}
		}
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt T3;
    MakeEmpty(&T3, NbElmt(T1));
    if (plus){
        int i;
        for (i = IdxMin; i <= GetLastIdx(T1); i++){
            Elmt(T3, i) = Elmt(T1, i) + Elmt(T2, i);
        }
    }
    else{
        int i;
        for (i = IdxMin; i <= GetLastIdx(T1); i++){
            Elmt(T3, i) = Elmt(T1, i) - Elmt(T2, i);
            if (Elmt(T3, i) < 0){
                Elmt(T3, i) = 0;
            }
        }
    }
    return (T3);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    if (NbElmt(T1) != NbElmt(T2)){
        return (false);
    }
    else{
        boolean check = true;
        int i = IdxMin;
        while (check && (i < NbElmt(T1))){
            if (Elmt(T1, i) != Elmt(T2, i)){
                check = false;
            }
            i++;
        }
        return (check);
    }
}  

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan ValUndef */
/* Menghasilkan indeks tak terdefinisi (ValUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    if (IsEmpty(T)){
        return (ValUndef);
    }
    else{
        int i = IdxMin;
        boolean found = false;
        while ((found == false) && (i < NbElmt(T))){
            if (Elmt(T, i) == X){
                found = true;
                return (i);
            }
            i++;
        }
        if (found == false){
            return (ValUndef);
        }
    }
}

boolean SearchB(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    int i = IdxMin;
    boolean found = false;
    while ((found == false) && (i < NbElmt(T))){
        if (Elmt(T, i) == X){
            found = true;
        }
        i++;
    }
    return (found);
}


/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    int i = IdxMin;
    *Max = Elmt(T, i);
    *Min = Elmt(T, i);
    while (i < NbElmt(T)){
        if (Elmt(T, i) > *Max){
            *Max = Elmt(T, i);
        }
        if (Elmt(T, i) < *Min){
            *Min = Elmt(T, i);
        }
        i++;
    }
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
    MakeEmpty(Tout, MaxEl(Tin));
    int i;
    for (i = IdxMin; i < MaxEl(Tin); i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
    MaxEl(*Tout) = MaxEl(Tin);
}

ElType SumTab(TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
    int sum = 0;
    int i;
    for (i = IdxMin; i < NbElmt(T); i++){
        sum += Elmt(T, i);
    }
    return (sum);
}

int CountX(TabInt T, ElType X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    int count = 0;
    int i;
    for (i = IdxMin; i < NbElmt(T); i++){
        if (Elmt(T, i) == X){
            count++;
        }
    }
    return (count);
}

boolean IsAllGenap(TabInt T){
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
    boolean genap = true;
    int i = IdxMin;
    while (genap && (i < NbElmt(T))){
        if (Elmt(T, i)%2 == 1){
            genap = false;
        }
        i++;
    }
    return (genap);
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
    if (asc){
        int min, temp, i, j;
        for (i = IdxMin; i < (NbElmt(*T)-1); i++){
            min = i;
            for (j = i+1; j < NbElmt(*T); j++){
                if (Elmt(*T, j) < Elmt(*T, min)){
                    min = j;
                }
            }
            temp = Elmt(*T, i);
            Elmt(*T, i) = Elmt(*T, min);
            Elmt(*T, min) = temp;
        }
    }
    else{
        int max, temp, i, j;
        for (i = IdxMin; i < (NbElmt(*T)-1); i++){
            max = i;
            for (j = i+1; j < NbElmt(*T); j++){
                if (Elmt(*T, j) > Elmt(*T, max)){
                    max = j;
                }
            }
            temp = Elmt(*T, i);
            Elmt(*T, i) = Elmt(*T, max);
            Elmt(*T, max) = temp;    
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    Elmt(*T, NbElmt(*T)) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}


/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    TabInt Tout;
    MakeEmpty(&Tout, (MaxEl(*T) + num));
    int i;
    for (i = IdxMin; i < MaxEl(*T); i++){
        Elmt(Tout, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = Tout;
}

void ShrinkTab(TabInt *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    GrowTab(T, -num);
}

void CompactTab(TabInt *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    int num = MaxEl(*T) - NbElmt(*T);
    GrowTab(T, -num);
}