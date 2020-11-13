/* File: vector.h */
/* Tanggal: 29 Agustus 2019 */
#include "vector.h"

/* *** Definisi ABSTRACT DATA TYPE VECTOR *** */
#define VECTOR POINT
/* *** Notasi Akses: Selektor VECTOR *** */
#define AbsisComponent(V) Absis(V)
#define OrdinatComponent(V) Ordinat(V)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y){
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
   VECTOR V;
   AbsisComponent(V) = x;
   OrdinatComponent(V) = y;
   return V;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
    return(sqrt(AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v)));
}

VECTOR Add(VECTOR a, VECTOR b){
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
   float x, y;
   VECTOR v;
   x = AbsisComponent(a) + AbsisComponent(b);
   y = OrdinatComponent(a) + OrdinatComponent(b);
   v = MakeVector(x, y);
   return v;
}

VECTOR Substract(VECTOR a, VECTOR b){
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
   float x, y;
   VECTOR v;
   x = AbsisComponent(a) - AbsisComponent(b);
   y = OrdinatComponent(a) - OrdinatComponent(b);
   v = MakeVector(x, y);
   return v;
}

float Dot(VECTOR a, VECTOR b){
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
    float answer;
    answer = AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b);
    return answer;
}

VECTOR Multiply(VECTOR v, float s){
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
    float x, y;
    VECTOR ans;
    x = s*AbsisComponent(v);
    y = s*OrdinatComponent(v);
    ans = MakeVector(x, y);
    return ans;
}