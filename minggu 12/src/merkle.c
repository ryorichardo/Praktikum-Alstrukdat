#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "listrek.h"

BinTree BuildMerkleTree(int h){
	if(h == 0){
		int x; 
        scanf("%d", &x);
		return AlokNode(x);
	}
	BinTree root = AlokNode(0);
	Left(root) = BuildMerkleTree(h-1);
	Right(root) = BuildMerkleTree(h-1);
	Akar(root) = Akar(Left(root)) + Akar(Right(root));
	return root;
}

int main(){
	int h, i = 0; 
    long long count = 1;
    scanf("%d", &h);
	while(count < h){
		count *= 2;
		i++;
	}
	if (count != h){
		printf("Jumlah masukan tidak sesuai\n");
	}
    else{
	    BinTree T = BuildMerkleTree(i);
	    PrintTree(T, 2);
    }
    return 0;
}