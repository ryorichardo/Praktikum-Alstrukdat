#include "matriks.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X){
/*Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. 
Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X.
Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], 
tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir 
{ I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
{ F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
Jika tidak ada elemen dengan nilai = X, menuliskan [] 
 Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 1 dan X = 3, akan tercetak: [0,2] */
    int i;
    boolean found = false;
    printf("[");
    for (i = 0; i < NBrsEff(M); i++){
        if (Elmt(M, i, j) == X){
            if (!found){
                printf("%d", i);
                found = true;
            }
            else{
                printf(",%d", i);
            }
        }
    }
    printf("]");
}

void TulisStatistikMhs (MATRIKS M, indeks i){
/* Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
{ Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
{ I.S. M terdefinisi, i adalah indeks baris efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min> }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 1 akan tercetak:
[1] 62.33 72 55 */
    float rata = RataBrs(M, i);
    ElType max, min;
    MaxMinBrs(M, i, &max, &min);
    printf("[%d] %.2f %d %d", i, rata, max, min);
}

void TulisStatistikMK (MATRIKS M, indeks j){
/*Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
{ Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika j = 1 akan tercetak:
[1] 77.00 [93 1 [2]] [55 1 [1]] */
    float rata = RataKol(M, j);
    ElType max, min;
    MaxMinKol(M, j, &max, &min);
    printf("[%d] %.2f [%d %d ", j, rata, max, CountXKol(M, j, max));
    TulisNilaiX(M, j, max);
    printf("] [%d %d ", min, CountXKol(M, j, min));
    TulisNilaiX(M, j, min);
    printf("]");
}

int main(){
    MATRIKS M;
    int nb, nk, i, j;
    scanf("%d", &nb);
    scanf("%d", &nk);
    BacaMATRIKS(&M, nb, nk);
    printf("STATISTIK PER MAHASISWA\n");
    for (i = BrsMin; i < NBrsEff(M); i++){
        TulisStatistikMhs(M, i);
        printf("\n");
    }
    printf("STATISTIK PER MATA KULIAH\n");
    for (j = KolMin; j < NKolEff(M); j++){
        TulisStatistikMK(M, j);
        printf("\n");
    }
    return 0;
}