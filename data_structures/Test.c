#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {

    Queue* q = createQueue();
    enque(10, q);
    printQueue(q);


    return 0;
}