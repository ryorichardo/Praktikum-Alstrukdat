#include "vector.c"

int main(){
    float x,y;
    printf("masukkan koordinat x y \n");
    scanf("%f %f", &x, &y);
    VECTOR v;
    v = MakeVector(x,y);
    printf("vector tsb adalah \n");
    TulisVector(v);
    printf("\n");
    printf("panjang vector adalah: %f\n", Magnitude(v));
    float a,b;
    printf("masukkan koordinat vector baru \n");
    scanf("%f %f", &a, &b);
    VECTOR v2;
    v2 = MakeVector(a,b);
    printf("Hasil penjumlahan vector tsb adalah \n");
    TulisVector(Add(v, v2));
    printf("\n");
    printf("Hasil substrak vector tsb adalah\n");
    TulisVector(Substract(v,v2));
    printf("\n");
    printf("Hasil perkalian dot adalah %f \n", Dot(v, v2));
    float s;
    printf("masukkan s \n");
    scanf("%f", &s);
    printf("Hasil kali skalar adalah \n");
    TulisVector(Multiply(v, s));
    return 0;
}