#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"

/* State Mesin Token */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
    while(CC == BLANK){
        ADV();
    }
}

void STARTTOKEN(){
    START();
    IgnoreBlank();
    EndToken = false;
    if(CC == MARK){
        EndToken = true;
    }
    else{
        SalinToken();
    }
}

void ADVTOKEN(){
    IgnoreBlank();
    if(CC == MARK){
        EndToken = true;
    }
    else{
        SalinToken();
        IgnoreBlank();
    }
}

void SalinToken(){
    int a;
    int i = 0;
    int value = 0;
    IgnoreBlank();
    if(CC==MARK){
        EndToken = true;
    }
    else if(CC == '+' || CC == '-' || CC == '*' || CC == '/' || CC == '^'){
        CToken.tkn = CC;
        CToken.val = -1;
    }
    else{
        CToken.tkn = 'b';
        while(CC != BLANK && CC != MARK && i < NMax){
            a = CC-0;
            value = value*10 + a;
            i++;
            ADV();
        }
        CToken.val = value;
    }
}