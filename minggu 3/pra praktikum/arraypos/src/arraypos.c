/* Ryo Richardo 13519193 */
/* Pra praktikum 3 */

#include "boolean.h"
#include "arraypos.h"
#include <stdio.h>

/*  Kamus Umum */
//#define IdxMax 99
/* Indeks maksimum array */
//#define IdxMin 0
/* Indeks minimum array */
//#define IdxUndef -999 
/* Indeks tak terdefinisi*/
//#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
    int i;
    for (i = IdxMin; i <= IdxMax; i++){
        Elmt(*T, i) = ValUndef;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    int i = IdxMin;
    while (Elmt(T, i) != ValUndef){
        i++;
    }
    return (i);
}

int MaxNbEl (TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (IdxMax+1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return (IdxMin);
}

IdxType GetLastIdx (TabInt T){
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
boolean IsIdxValid (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
    return(NbElmt(T) == 0);
}

boolean IsFull (TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return(NbElmt(T) == (IdxMax+1));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    MakeEmpty(T);
    int N;
    scanf("%d", &N);
    while ((N < IdxMin) || (N > (MaxNbEl(*T)))){
        scanf("%d", &N);
    }        
    int input;
    int i;
    for (i = IdxMin; i < N; i++){
        scanf("%d", &input);
        Elmt(*T, i) = input;
    }
}
    
void TulisIsiTab (TabInt T){
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
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt T3;
    MakeEmpty(&T3);
    if (plus){
        int i;
        for (i = IdxMin; i <= GetLastIdx(T2); i++){
            Elmt(T3, i) = Elmt(T1, i) + Elmt(T2, i);
        }
    }
    else{
        int i;
        for (i = IdxMin; i <= GetLastIdx(T2); i++){
            Elmt(T3, i) = Elmt(T1, i) - Elmt(T2, i);
        }
    }
    return (T3);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
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
IdxType Search1 (TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    if (IsEmpty(T)){
        return (IdxUndef);
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
            return (IdxUndef);
        }
    }
}

boolean SearchB (TabInt T, ElType X){
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
void MaxMin (TabInt T, ElType * Max, ElType * Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    int i = IdxMin;
    *Max = Elmt(T, i);
    *Min = Elmt(T, i);
    while (Elmt(T, i) != ValUndef){
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
ElType SumTab (TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
    int sum = 0;
    int i;
    for (i = IdxMin; i < NbElmt(T); i++){
        sum += Elmt(T, i);
    }
    return (sum);
}

int CountX (TabInt T, ElType X){
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

boolean IsAllGenap (TabInt T){
/* Menghailkan true jika semua elemen T genap */
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
void Sort (TabInt * T, boolean asc){
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
void AddAsLastEl (TabInt * T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    Elmt(*T, NbElmt(*T)) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}