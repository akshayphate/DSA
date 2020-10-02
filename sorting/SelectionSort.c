#include <stdio.h>

void selectionSort(int[], int);
void exch(int[], int, int);
void print_array(int[], int);

int main() {
    
    int array[] = {1,0,5,2,3,4,9,8,7,6};

    print_array(array, 10);

    selectionSort(array, 10);
    
    print_array(array, 10);

    return 0;
}

void selectionSort(int array[], int len) {

    for (int i = 0; i < len; i++) {
        int key = i;
        
        for (int j = i+1; j < len; j++) {
            if (array[j] < array[key])
                key = j;
        }

        if (key != i) exch(array, key, i);
    }
}

void exch(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void print_array(int array[], int len) {
    int i = 0;

    while (i != len)
        printf("%d ", array[i++]);

    printf("\n");
}