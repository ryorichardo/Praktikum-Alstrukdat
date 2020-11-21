#include "listrek.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int jumlah = 0;
List temp = Nil;
int fungsimagic(List L, int tot, int n){
	if(IsEmpty(L)){
        return 1;
    } 
	else{
        jumlah++; 
	    fungsimagic(Tail(L), tot+1, n);
    }
	if(n + tot - 1 == jumlah){
        temp = L;
    } 
	if(n + tot == jumlah){
        Dealokasi(L);
        if(tot == 0){
            return 0;
        }
    }
    if(n + tot + 1 == jumlah){
        SetNext(L, temp);
    }
}

List delNFromEnd(List L, int n){
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
    if(IsEmpty(L)){
        return L;
    }
	if(!fungsimagic(L, 0, n)){
        return temp;
    }
	return L;
}