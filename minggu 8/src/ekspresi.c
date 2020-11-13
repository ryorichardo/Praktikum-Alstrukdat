# include "mesintoken.h"
# include "stackt.h"
# include <math.h>

int main(){
    Stack S;
    CreateEmpty(&S);

    STARTTOKEN();
    if (EndToken){
        printf("Ekspresi kosong\n");
    }
    else{
        int x1, x2;
        while (!EndToken){
            if (CToken.tkn == 'b'){
                Push(&S, CToken.val);
                printf("%d\n", CToken.val);
            }
            else{
                Pop(&S, &x1);
                Pop(&S, &x2);
                if (CToken.tkn == '+'){
                    printf("%d %c %d\n", x2, CToken.tkn, x1);
                    x1 = x2 + x1;
                    printf("%d\n", x1);
                    Push(&S, x1);
                }
                else if (CToken.tkn == '-'){
                    printf("%d %c %d\n", x2, CToken.tkn, x1);
                    x1 = x2 - x1;
                    printf("%d\n", x1);
                    Push(&S, x1);
                }
                else if (CToken.tkn == '*'){
                    printf("%d %c %d\n", x2, CToken.tkn, x1);
                    x1 = x2 * x1;
                    printf("%d\n", x1);
                    Push(&S, x1);
                }
                else if (CToken.tkn == '/'){
                    printf("%d %c %d\n", x2, CToken.tkn, x1);
                    x1 = x2 / x1;
                    printf("%d\n", x1);
                    Push(&S, x1);
                }
                else if (CToken.tkn == '^'){
                    printf("%d %c %d\n", x2, CToken.tkn, x1);
                    x1 = (int)pow(x2, x1);
                    printf("%d\n", x1);
                    Push(&S, x1);
                }
            }
            ADVTOKEN();
        }
        Pop(&S, &x1);
        printf("Hasil=%d\n", x1);
    }
    return 0;
}