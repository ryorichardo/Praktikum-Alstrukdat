/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

/* Ukuran minimum dan maksimum baris dan kolom */
//#define BrsMin 0
//#define BrsMax 99
//#define KolMin 0
//#define KolMax 99

//typedef int indeks; /* indeks baris, kolom */
//typedef int ElType; 
//typedef struct { 
//	ElType Mem[BrsMax+1][KolMax+1];
//    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
//	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
//} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
   NBrsEff(*M) = NB;
   NKolEff(*M) = NK;
}

/* *** Selektor *** */
//#define NBrsEff(M) (M).NBrsEff
//#define NKolEff(M) (M).NKolEff
//#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
   return (i <= BrsMax && i >= BrsMin && j <= KolMax && j >= KolMin);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
   return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
   return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
   return (NBrsEff(M) - 1);
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
   return (NKolEff(M) - 1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
   return (i < NBrsEff(M) && i >= BrsMin && j < NKolEff(M) && j >= KolMin);
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
   return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
   *MHsl = MIn;
   NBrsEff(*MHsl) = NBrsEff(MIn);
   NKolEff(*MHsl) = NKolEff(MIn);
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
   MakeMATRIKS(NB, NK, M);
   int i, j, input;
   for (i = BrsMin; i < NBrsEff(*M); i++){
      for (j = KolMin; j < NKolEff(*M); j++){
         scanf("%d", &input);
         Elmt(*M, i, j) = input;
      }
   }
}

void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
   int i, j;
   for (i = BrsMin; i < NBrsEff(M); i++){
      for (j = KolMin; j < NKolEff(M); j++){
         if (j == (NKolEff(M)-1)){
            printf("%d", Elmt(M, i, j));
         }
         else{
            printf("%d ", Elmt(M, i, j));
         }
      }
      if (i != (NBrsEff(M)-1)){
         printf("\n");
      }
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
   int i, j;
   for (i = BrsMin; i < NBrsEff(M1); i++){
      for (j = KolMin; j < NKolEff(M1); j++){
         Elmt(M1, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
      }
   }
   return M1;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
   int i, j;
   for (i = BrsMin; i < NBrsEff(M1); i++){
      for (j = KolMin; j < NKolEff(M1); j++){
         Elmt(M1, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
      }
   }
   return M1;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
   MATRIKS M3;
   MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
   int i, j, k;
   for (i = BrsMin; i < NBrsEff(M1); i++){
      for (j = KolMin; j < NKolEff(M2); j++){
         for (k = KolMin; k < NKolEff(M1); k++){
            Elmt(M3, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
         }
      }
   }
   return M3;
}

MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
   int i, j;
   for (i = BrsMin; i < NBrsEff(M); i++){
      for (j = KolMin; j < NKolEff(M); j++){
         Elmt(M, i, j) = Elmt(M, i, j) * X;
      }
   }
   return M;
}

void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
   int i, j;
   for (i = BrsMin; i < NBrsEff(*M); i++){
      for (j = KolMin; j < NKolEff(*M); j++){
         Elmt(*M, i, j) = Elmt(*M, i, j) * K;
      }
   }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
   if (NBElmt(M1) != NBElmt(M2)){
      return false;
   }
   else{
      int i = BrsMin, j = KolMin;
      boolean same = true;
      while (same && i < NBrsEff(M1)){
         while (same && j < NKolEff(M1)){
            if (Elmt(M1, i, j) != Elmt(M2, i, j)){
               same = false;
            }
            j++;
         }
         i++;
      }
      return same;
   }
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
   return !EQ(M1, M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
   return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
   return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
   return NBrsEff(M) == NKolEff(M);
}

boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
   if (!IsBujurSangkar(M)){
      return false;
   }
   else{
      int i = BrsMin, j = KolMin;
      boolean sim = true;
      while (sim && i < NBrsEff(M)){
         while (sim && j < NKolEff(M)){
            if (Elmt(M, i, j) != Elmt(M, j, i)){
               sim = false;
            }
            j++;
         }
         i++;
      }
      return sim;
   }
}

boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
   if (!IsBujurSangkar(M)){
      return false;
   }
   else{
      int i = BrsMin, j = KolMin;
      boolean sat = true;
      while (sat && i < NBrsEff(M)){
         while (sat && j < NKolEff(M)){
            if (i == j){
               if (Elmt(M, i, i) != 1){
                  sat = false;
               }
            }
            else{
               if (Elmt(M, i, j) != 0){
                  sat = false;
               }
            }
            j++;
         }
         i++;
      }
      return sat;
   }
}

boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
   int i, j, count = 0;
   for (i = BrsMin; i < NBrsEff(M); i++){
      for (j = KolMin; j < NKolEff(M); j++){
         if (Elmt(M, i, j) == 0){
            count ++;
         }
      }
   }
   return (count <= (0.05 * (BrsMax+1) * (KolMax+1)));
}

MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
   return(KaliKons(M, -1));
}

float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
   int n, i, j, line1, line2;
   float count = 1;
   boolean found;
   for (n = BrsMin; n < NBrsEff(M); n++){
      if (Elmt(M, n, n) == 0){
         found = false;
         i = n+1;
         while (!found && i < NBrsEff(M)){
            if (Elmt(M, i, n) != 0){
               found = true;
               for (j = n; j < NKolEff(M); j++){
                  Elmt(M, n, j) += Elmt(M, i, j);
               }
            }
            i++;
         }
         if (!found){
            return 0;
         }
      }
      for (i = n+1; i < NBrsEff(M); i++){       
         if (Elmt(M, i, n) != 0){        
            line1 = Elmt(M, n, n);
            line2 = Elmt(M, i, n); 
               for (j = n; j < NKolEff(M); j++){
                  Elmt(M, i, j) *= line1;
                  Elmt(M, n, j) *= line2;
                  Elmt(M, i, j) -= Elmt(M, n, j);
               }
               count /= (line1 * line2);
            }
         }
         count *= Elmt(M, n, n);
      }
   return count;
}

void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
   int i, j;
   for (i = BrsMin; i < NBrsEff(*M); i++){
      for (j = KolMin; j < NKolEff(*M); j++){
         Elmt(*M, i, j) = Elmt(*M, i, j) * (-1);
      }
   }
}

void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
   int i, j, temp;
   for (i = BrsMin; i < NBrsEff(*M); i++){
      for (j = KolMin; j < NKolEff(*M); j++){
         if (j > i){
            temp = Elmt(*M, i, j);
            Elmt(*M, i, j) = Elmt(*M, j, i);
            Elmt(*M, j, i) = temp;
         }
      }
   }
}

float RataBrs (MATRIKS M, indeks i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
   float sum = 0;
   int j;
   for (j = KolMin; j < NKolEff(M); j++){
      sum += Elmt(M, i, j);
   }
   return(sum/NKolEff(M));
}

float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
   float sum = 0;
   int i;
   for (i = BrsMin; i < NBrsEff(M); i++){
      sum += Elmt(M, i, j);
   }
   return(sum/NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
         min berisi elemen minimum pada baris i dari M */
   *max = Elmt(M, i, KolMin);
   *min = Elmt(M, i, KolMin);
   int j;
   for (j = KolMin; j < NKolEff(M); j++){
      if (Elmt(M, i, j) > *max){
         *max = Elmt(M, i, j);
      }
      if (Elmt(M, i, j) < *min){
         *min = Elmt(M, i, j);
      }
   }
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
   *max = Elmt(M, BrsMin, j);
   *min = Elmt(M, BrsMin, j);
   int i;
   for (i = BrsMin; i < NBrsEff(M); i++){
      if (Elmt(M, i, j) > *max){
         *max = Elmt(M, i, j);
      }
      if (Elmt(M, i, j) < *min){
         *min = Elmt(M, i, j);
      }
   }
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
   int j, count = 0;
   for (j = KolMin; j <NKolEff(M); j++){
      if (Elmt(M, i, j) == X){
         count++ ;
      }
   }
   return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
   int i, count = 0;
   for (i = BrsMin; i <NBrsEff(M); i++){
      if (Elmt(M, i, j) == X){
         count++ ;
      }
   }
   return count;
}