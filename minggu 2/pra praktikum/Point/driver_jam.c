/* Ryo Richardo */
/* 13519193 */
/* Driver Program Jam */

#include "jam.c"

int main(){
    JAM J;
    printf("Masukan jam_menit_detik \n");
    BacaJAM(&J);
    printf("Jam yang anda input adalah: \n");
    TulisJAM(J);
    printf("\n");

    printf("Jika dikonversi ke detik maka terdapat %d detik\n", JAMToDetik(J));

    JAM J2;
    printf("Masukan jam kedua dengan format yang sama \n");
    BacaJAM(&J2);
    
    printf("Apakah Jam 1 = Jam 2?\n");
    printf("%d\n", JEQ(J, J2));
    printf("Apakah Jam 1 != Jam 2?\n");
    printf("%d\n", JNEQ(J, J2));
    printf("Apakah Jam 1 < Jam 2?\n");
    printf("%d\n", JLT(J, J2));
    printf("Apakah Jam 1 > Jam 2?\n");
    printf("%d\n", JGT(J, J2));

    int N;
    printf("Input sembarang nilai N \n");
    scanf("%d", &N);
    printf("Satu detik setelah Jam pertama adalah: \n");
    TulisJAM(NextDetik(J));
    printf("\n");
    printf("Satu detik sebelum Jam pertama adalah: \n");
    TulisJAM(PrevDetik(J));
    printf("\n");
    printf("N detik setelah Jam pertama adalah: \n");
    TulisJAM(NextNDetik(J, N));
    printf("\n");
    printf("N detik sebelum Jam pertama adalah: \n");
    TulisJAM(PrevNDetik(J, N));
    printf("\n");

    printf("Selisih antara Jam 2 dan Jam 1 adalah %d detik\n", Durasi(J, J2));
    return 0;
}