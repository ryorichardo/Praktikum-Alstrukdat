/* Ryo Richardo 13519193 */
/* Program Konversi suhu */
#include <stdio.h>

int main(){
    float suhu;
    printf("Masukkan suhu: \n");
    scanf("%f", &suhu);
    char satuan;
    printf("Masukkan konversi: \n");
    scanf(" %c", &satuan);
    if (satuan == 'R'){
        printf("%.2f \n", (0.8*suhu));
    } else if (satuan == 'F'){
        printf("%.2f \n", (1.8*suhu + 32));
    } else if (satuan == 'K'){
        printf("%.2f \n", (suhu + 273.15));
    }
    return 0;
}