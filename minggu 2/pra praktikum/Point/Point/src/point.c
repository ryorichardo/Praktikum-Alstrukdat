/* Ryo Richardo */
/* 13519193 */
/* Realisasi Program Point */

#include "point.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
        Absis(P) = X;
        Ordinat(P) = Y;
        return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float X, Y;
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X, Y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%.2f,%.2f)", Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))); 
}

boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2))); 
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    return ((Absis(P) == 0) && (Ordinat(P) == 0)); 
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P) == 0); 
}

boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P) == 0); 
}

int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    if ((Absis(P) > 0) && (Ordinat(P) > 0)){
        return 1;
    } 
    else if ((Absis(P) < 0) && (Ordinat(P) > 0) ){
        return 2;
    }
    else if ((Absis(P) < 0) && (Ordinat(P) < 0)){
        return 3;
    }
    else if ((Absis(P) > 0) && (Ordinat(P) < 0)){
        return 4;
    }
    else{
        return -1;
    } 
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
   return MakePOINT(Absis(P) + 1, Ordinat(P));
}

POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
   return MakePOINT(Absis(P), Ordinat(P) + 1);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
   return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}

POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
   if (SbX){
      return MakePOINT(Absis(P), -Ordinat(P));
   }
   else{
      return MakePOINT(-Absis(P), Ordinat(P));
   }
}

float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
    return(sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    return sqrt(((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2))) + ((Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2))));
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    *P = MakePOINT(Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}

void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    *P = MakePOINT(Absis(*P), 0);
}

void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    *P = MakePOINT(0, Ordinat(*P));
}

void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX){
        *P = MakePOINT(Absis(*P), -Ordinat(*P));
    }
    else{
        *P = MakePOINT(-Absis(*P), Ordinat(*P));
    }
}

void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/ 
    float rad, sinus, cosinus, x, y;
    rad = M_PI / 180;
    sinus = sin(-1 * Sudut * rad);
    cosinus = cos(-1 * Sudut * rad);
    x = cosinus * Absis(*P) - sinus * Ordinat(*P);
    y = sinus* Absis(*P) + cosinus * Ordinat(*P);
    *P = MakePOINT(x, y);
}