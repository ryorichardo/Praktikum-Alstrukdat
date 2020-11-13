#include "prioqueuechar.h"

int main() {
    int i, n, nani = 1;
    infotype x;
    PrioQueueChar Q;
    scanf("%d", &n);
    MakeEmpty(&Q, 100);
    for (i = 1; i <= n; i++){
        scanf("%d %c", &Prio(x), &Info(x));
        Enqueue(&Q, x);
        while (Prio(InfoHead(Q)) == nani){
            Dequeue(&Q, &x);
            printf("%d %c\n", i, Info(x));
            nani++;
        }
    }
    return 0;
}