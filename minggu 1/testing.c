/* Ryo Richardo 13519193 */
/* Program Konversi suhu */
#include <stdio.h>

int main(){
    float suhu;
    char satuan;
    printf("Masukkan suhu: \n");
    scanf("%f", &suhu);
    printf("Masukkan konversi: \n");
    scanf(" %c", &satuan);
    switch (satuan) {
      case 'R':
        printf("%.2f \n", (0.8*suhu));
        break;
      case 'F':
        printf("%.2f \n", (1.8*suhu + 32));
        break;
      case 'K':
        printf("%.2f \n", (suhu + 273.15));
        break;
    }
    return 0;
}
