/* Ryo Richardo */
/* 13519193 */
/* Driver Program Point */

#include "point.c"

int main(){
    POINT P, P2;
    printf("Input koordinat titik P\n");
    BacaPOINT(&P);
    printf("Titik P mempunyai koordinat: \n");
    TulisPOINT(P);
    printf("\n");
    printf("Input koordinat titik P2\n");
    BacaPOINT(&P2);
    printf("Titik P2 mempunyai koordinat: \n");
    TulisPOINT(P2);
    printf("\n");

    printf("Apakah P = P2?\n");
    printf("%d\n", EQ(P, P2));
    printf("Apakah P != P2?\n");
    printf("%d\n", NEQ(P, P2));
    printf("Apakah P titik origin?\n");
    printf("%d\n", IsOrigin(P));
    printf("Apakah P berada di sumbu x?\n");
    printf("%d\n", IsOnSbX(P));
    printf("Apakah P berada di sumbu y?\n");
    printf("%d\n", IsOnSbY(P));
    printf("P berada di kuadran = %d\n", Kuadran(P));

    printf("Titik NextX P adalah = "); 
    TulisPOINT(NextX(P));
    printf("\n");
    printf("Titik NextY P adalah = ");
    TulisPOINT(NextY(P));
    printf("\n");

    float deltax, deltay;
    printf("Input deltax dan deltay\n");
    scanf("%f %f", &deltax, &deltay);
    printf("Titik delta P adalah = ");
    TulisPOINT(PlusDelta(P, deltax, deltay));
    printf("\n");

    boolean x;
    printf("Input 1 jika ingin dicerminkan sumbu X, 0 jika dicerminkan sumbu Y\n");
    scanf("%d", &x);
    printf("Hasil pencerminan = ");
    TulisPOINT(MirrorOf(P, x));
    printf("\n");
    printf("Jarak P ke titik origin = %f\n", Jarak0(P));
    printf("Jarak antara P dan P2 = %f\n", Panjang(P, P2));

    POINT P3, P4;
    P3 = P;
    P4 = P;
    printf("P jika diproyeksikan ke sumbu x = ");
    GeserKeSbX(&P3);
    TulisPOINT(P3);
    printf("\n");
    printf("P jika diproyeksikan ke sumbu y = ");
    GeserKeSbY(&P4);
    TulisPOINT(P4);
    printf("\n");

    float sudut;
    printf("Input sudut rotasi searah jarum jam\n");
    scanf("%f", &sudut);
    Putar(&P, sudut);
    TulisPOINT(P);
    return 0;
}