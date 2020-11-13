/* Ryo Richardo 13519193 */
/* Praktikum 2, 3 September 2020 */

#include <stdio.h>
#include <math.h>
#include "jam.h"

int main(){
    int entries, counter;
    JAM J, J2, J3, Jmax, Jmin;
    Jmax = MakeJAM(0, 0, 0);
    Jmin = MakeJAM(23, 59, 59);
    counter = 1;
    scanf("%d", &entries);
    while (counter <= entries){
        printf("[%d]\n", counter);
        BacaJAM(&J);
        BacaJAM(&J2);
        if(JAMToDetik(J) > JAMToDetik(J2)){
            J3 = J;
            J = J2;
            J2 = J3;        
        }      
        if (JAMToDetik(J) < JAMToDetik(Jmin)){
            Jmin = J;
        }      
        if (JAMToDetik(J2) > JAMToDetik(Jmax)){
            Jmax = J2;
        }
        printf("%d\n", Durasi(J, J2));
        counter += 1;
    }
    TulisJAM(Jmin);
    printf("\n");
    TulisJAM(Jmax);
    printf("\n");
    return 0;
}