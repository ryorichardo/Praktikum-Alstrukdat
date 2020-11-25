#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/bintree.h"
#include "../src/listrek.h"

// Konstruktor
START_TEST(MakeTree_TC1){
  addrNode L = AlokNode(2);
  addrNode R = AlokNode(3);
  BinTree P;
  MakeTree(1, L, R, &P);
  ck_assert_int_eq(1, Akar(P));
  ck_assert_int_eq(2, Akar(Left(P)));
  ck_assert_int_eq(3, Akar(Right(P)));
} END_TEST

START_TEST(BuildBalanceTree_TC1){
  BinTree P = BuildBalanceTree(0);
  ck_assert_ptr_eq(P, Nil);
} END_TEST

// Manajemen Memory
START_TEST(AlokNode_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, Akar(P));
} END_TEST

// Predikat
START_TEST(IsTreeEmpty_TC1){
  BinTree P = Nil;
  ck_assert_int_eq(1, IsTreeEmpty(P));
} END_TEST

START_TEST(IsTreeOneElmt_TC1){
  BinTree P;  
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, IsTreeOneElmt(P));
} END_TEST

START_TEST(IsUnerLeft_TC1){
  BinTree P, L;
  MakeTree(1, Nil, Nil, &L);
  MakeTree(1, L, Nil, &P);
  ck_assert_int_eq(1, IsUnerLeft(P));
} END_TEST

START_TEST(IsUnerRight_TC1){
  BinTree P, R;
  MakeTree(1, Nil, Nil, &R);
  MakeTree(1, Nil, R, &P);
  ck_assert_int_eq(1, IsUnerRight(P));
} END_TEST

START_TEST(IsBiner_TC1){
  BinTree P, L = AlokNode(2), R = AlokNode(2);
  MakeTree(1, L, R, &P);
  ck_assert_int_eq(1, IsBiner(P));
} END_TEST

// Searching
START_TEST(SearchTree_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, SearchTree(P, 1));
} END_TEST

// Fungsi lain
START_TEST(NbElmt_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, NbElmt(P));
} END_TEST

START_TEST(NbDaun_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, NbDaun(P));
} END_TEST

START_TEST(IsSkewLeft_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, IsSkewLeft(P));
} END_TEST

START_TEST(IsSkewRight_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, IsSkewRight(P));
} END_TEST

START_TEST(Level_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, Level(P, 1));
} END_TEST

START_TEST(Tinggi_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, Tinggi(P));
} END_TEST

// Operasi lain
/*START_TEST(AddDaunTerkiri_TC1){
  BinTree P;
  AddDaunTerkiri(&P, 1);
  ck_assert_int_eq(1, Akar(P));
} END_TEST*/

START_TEST(AddDaun_TC1){
  BinTree P;
  MakeTree(0, Nil, Nil, &P);
  AddDaun(&P, 0, 1, true);
  ck_assert_int_eq(1, Akar(Left(P)));
} END_TEST

START_TEST(DelDaunTerkiri_TC1){
  BinTree P;
  MakeTree(0, Nil, Nil, &P);
  int X;
  DelDaunTerkiri(&P, &X);
  ck_assert_int_eq(0, X);
} END_TEST

START_TEST(DelDaun_TC1){
  BinTree P;
  MakeTree(0, Nil, Nil, &P);
  DelDaun(&P, 0);
  ck_assert_ptr_eq(P, Nil);
} END_TEST

START_TEST(MakeListDaun_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  List L = MakeListDaun(P);
  ck_assert_int_eq(1, Info(L));
} END_TEST

START_TEST(MakeListPreorder_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  List L = MakeListPreorder(P);
  ck_assert_int_eq(1, Info(L));
} END_TEST

START_TEST(MakeListLevel_TC1){
BinTree P;
MakeTree(1, Nil, Nil, &P);
List L = MakeListLevel(P, 1);
ck_assert_int_eq(1, Info(L));
} END_TEST

// Binary Search Tree
START_TEST(BSearch_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  ck_assert_int_eq(1, BSearch(P, 1));
} END_TEST

/*START_TEST(InsSearch_TC1){
  BinTree P;
  InsSearch(&P, 1);
  ck_assert_int_eq(1, Akar(P));
} END_TEST*/

START_TEST(DelBtree_TC1){
  BinTree P;
  MakeTree(1, Nil, Nil, &P);
  DelBtree(&P, 1);
  ck_assert_ptr_eq(P, Nil);
} END_TEST


/* ********** SUITE DAN EKSEKUSI ********** */
Suite *bintree_suite(void) { 
  Suite *s;
  TCase *tc_konstruktor, *tc_memory, *tc_predikat, *tc_searching, *tc_fungsi, *tc_operasi, *tc_binary;
  s = suite_create("Binary Tree");

  tc_konstruktor = tcase_create("Konstruktor");
  tcase_add_test(tc_konstruktor, MakeTree_TC1);
  tcase_add_test(tc_konstruktor, BuildBalanceTree_TC1);
  suite_add_tcase(s, tc_konstruktor);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, AlokNode_TC1);
  suite_add_tcase(s, tc_memory);

  tc_predikat = tcase_create("Predikat");
  tcase_add_test(tc_predikat, IsTreeEmpty_TC1);
  tcase_add_test(tc_predikat, IsTreeOneElmt_TC1);
  tcase_add_test(tc_predikat, IsUnerLeft_TC1);
  tcase_add_test(tc_predikat, IsUnerRight_TC1);
  tcase_add_test(tc_predikat, IsBiner_TC1);
  suite_add_tcase(s, tc_predikat);

  tc_searching = tcase_create("Searching");
  tcase_add_test(tc_searching, SearchTree_TC1);
  suite_add_tcase(s, tc_searching);

  tc_fungsi = tcase_create("Fungsi");
  tcase_add_test(tc_fungsi, NbElmt_TC1);
  tcase_add_test(tc_fungsi, NbDaun_TC1);
  tcase_add_test(tc_fungsi, IsSkewLeft_TC1);
  tcase_add_test(tc_fungsi, IsSkewRight_TC1);
  tcase_add_test(tc_fungsi, Level_TC1);
  tcase_add_test(tc_fungsi, Tinggi_TC1);
  suite_add_tcase(s, tc_fungsi);

  tc_operasi = tcase_create("Operasi");
  //tcase_add_test(tc_operasi, AddDaunTerkiri_TC1);
  tcase_add_test(tc_operasi, AddDaun_TC1);
  tcase_add_test(tc_operasi, DelDaunTerkiri_TC1);
  tcase_add_test(tc_operasi, DelDaun_TC1);
  tcase_add_test(tc_operasi, MakeListDaun_TC1);
  tcase_add_test(tc_operasi, MakeListPreorder_TC1);
  tcase_add_test(tc_operasi, MakeListLevel_TC1);
  suite_add_tcase(s, tc_operasi);

  tc_binary = tcase_create("Binary Search Tree");
  tcase_add_test(tc_binary, BSearch_TC1);
  //tcase_add_test(tc_binary, InsSearch_TC1);
  tcase_add_test(tc_binary, DelBtree_TC1);
  suite_add_tcase(s, tc_binary);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = bintree_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}