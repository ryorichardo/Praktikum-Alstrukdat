#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"

address AlokasiAss (infotype X);
void DealokasiAss (address P);
int IsEmptyAss(List L);
int IsOneElmtAss(List L);
infotype FirstElmtAss (List L);
List TailAss(List L);
List KonsoAss(infotype e, List L);
List KonsBAss(List L, infotype e);
List ConcatAss (List L1, List L2);
void MConcatAss (List L1, List L2, List *LHsl);

/****************** Kondisi list ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
START_TEST(IsOneElmt_TC1) {
  List L = Nil;
  ck_assert_int_eq(0, IsOneElmt(L));
  L= KonsoAss(2,L);
  ck_assert_int_eq(1, IsOneElmt(L));
  L= KonsoAss(2,L);
  ck_assert_int_eq(0, IsOneElmt(L));
} END_TEST

START_TEST(IsEmpty_TC1) {
  List L = Nil;
  ck_assert_int_eq(1, IsEmpty(L));
  L= KonsoAss(2,L);
  ck_assert_int_eq(0, IsEmpty(L));
} END_TEST

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
START_TEST(Alokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
} END_TEST

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
START_TEST(Dealokasi_TC1) {
  infotype X = 2;
  address P = AlokasiAss(X);
  // Delokasi, seems impossible to be tested, so just check if no runtime error
  Dealokasi(P);
} END_TEST

// Selektor
START_TEST(FirstElmt_TC1){
  List L = Nil;
  L = KonsoAss(3, L);
  ck_assert_int_eq(FirstElmt(L), FirstElmtAss(L));
} END_TEST

START_TEST(Tail_TC1){
  List L = Nil;
  L = KonsoAss(3, L);
  ck_assert_ptr_eq(Tail(L), TailAss(L));
} END_TEST

// Konstruktor
START_TEST(Konso_TC1){
  List L1 = Nil, L2 = Nil;
  L1 = Konso(2, L1);
  L2 = KonsoAss(2, L2);
  ck_assert_int_eq(Info(L1), Info(L2));
} END_TEST

START_TEST(KonsB_TC1){
  List L1 = Nil, L2 = Nil;
  L1 = KonsB(L1, 2);
  L2 = KonsBAss(L2, 2);
  ck_assert_int_eq(Info(L1), Info(L2));
} END_TEST

// Primitif
START_TEST(Copy_TC1){
  List L = Nil, L1 = Nil;
  L = KonsoAss(1, L);
  L = KonsoAss(2, L);
  L = KonsoAss(3, L);
  L1 = Copy(L);
  ck_assert_int_eq(Info(L1), Info(L));
} END_TEST

START_TEST(MCopy_TC1){
  List L = Nil, L1 = Nil;
  L = KonsoAss(1, L);
  L = KonsoAss(2, L);
  L = KonsoAss(3, L);
  MCopy(L, &L1);
  ck_assert_int_eq(Info(L1), Info(L));
} END_TEST

START_TEST(Concat_TC1){
  List L = Nil, L1 = Nil, L2 = Nil, Lt = Nil;
  L1 = KonsoAss(1, L1);
  L1 = KonsoAss(2, L1);
  L1 = KonsoAss(3, L1);
  L2 = KonsoAss(1, L2);
  L2 = KonsoAss(2, L2);
  L2 = KonsoAss(3, L2);
  L = Concat(L1, L2);
  Lt = ConcatAss(L1, L2);
  ck_assert_int_eq(Info(L), Info(Lt));
} END_TEST

START_TEST(MConcat_TC1){
  List L = Nil, L1 = Nil, L2 = Nil, Lt = Nil;
  L1 = KonsoAss(1, L1);
  L1 = KonsoAss(2, L1);
  L1 = KonsoAss(3, L1);
  L2 = KonsoAss(1, L2);
  L2 = KonsoAss(2, L2);
  L2 = KonsoAss(3, L2);
  MConcat(L1, L2, &L);
  MConcatAss(L1, L2, &Lt);
  ck_assert_int_eq(Info(L), Info(Lt));
} END_TEST

START_TEST(NbElmtList_TC1){
  List L1 = Nil;
  L1 = KonsoAss(1, L1);
  L1 = KonsoAss(2, L1);
  L1 = KonsoAss(3, L1);
  int n = NbElmtList(L1);
  ck_assert_int_eq(n, 3);
} END_TEST

START_TEST(Search_TC1) {
  List L = Nil;
  L = KonsoAss(1, L);
  int n = Search(L, 1);
  ck_assert_int_eq(n, 1);
  n = Search(L, 2);
  ck_assert_int_eq(n, 0);
} END_TEST

// List fungsi asisten
address AlokasiAss (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P;
    P = (address) malloc(sizeof(infotype));
    if (P == Nil){
        return Nil;
    }
    else{
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
}

void DealokasiAss (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    Next(P) = Nil;
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmptyAss(List L){
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
    return (L == Nil);
}

int IsOneElmtAss(List L){
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
    return (!IsEmpty(L) && Next(L) == Nil);
}

/* *** Selektor *** */
infotype FirstElmtAss (List L){
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
    return (Info(L));
}

List TailAss(List L){
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
    return (Next(L));
}

/* *** Konstruktor *** */
List KonsoAss(infotype e, List L){
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
    address P = Alokasi(e);
    if (P != Nil){
        Next(P) = L;
        return P;
    }
    return L;
}

List KonsBAss(List L, infotype e){
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */
    if (IsEmpty(L)){
        address P = Alokasi(e);
        return P;
    }
    else{
        Next(L) = KonsB(Tail(L),e);
        return L;
    }
}

/* *** Operasi Lain *** */
List ConcatAss (List L1, List L2){
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
    if (IsEmpty(L1)){
        return Copy(L2);
    }
    else{
        return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
    }
}

void MConcatAss (List L1, List L2, List *LHsl){
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
    if (IsEmpty(L1)){
        *LHsl = Copy(L2);
    }
    else{
        List Ltemp;
        MConcat(Tail(L1), L2, &Ltemp);
        *LHsl = Konso(FirstElmt(L1), Ltemp);
    }
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listrek_suite(void) { 
  Suite *s;
  TCase *tc_kondisi, *tc_memory, *tc_selektor, *tc_konstruktor, *tc_primitif;
  s = suite_create("List Rekursif");

  tc_kondisi = tcase_create("Kondisi");
  tcase_add_test(tc_kondisi, IsOneElmt_TC1);
  tcase_add_test(tc_kondisi, IsEmpty_TC1);
  suite_add_tcase(s, tc_kondisi);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_selektor = tcase_create("Selektor");
  tcase_add_test(tc_selektor, FirstElmt_TC1);
  tcase_add_test(tc_selektor, Tail_TC1);
  suite_add_tcase(s, tc_selektor);

  tc_konstruktor = tcase_create("Konstruktor");
  tcase_add_test(tc_konstruktor, Konso_TC1);
  tcase_add_test(tc_konstruktor, KonsB_TC1);
  suite_add_tcase(s, tc_konstruktor);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, Copy_TC1);
  tcase_add_test(tc_primitif, MCopy_TC1);
  tcase_add_test(tc_primitif, Concat_TC1);
  tcase_add_test(tc_primitif, MConcat_TC1);
  tcase_add_test(tc_primitif, NbElmtList_TC1);
  tcase_add_test(tc_primitif, Search_TC1);
  suite_add_tcase(s, tc_primitif);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listrek_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}