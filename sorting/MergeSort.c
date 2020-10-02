#include <stdio.h>

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

void merge(int array[], int lo, int mid, int hi) {
    int aux[hi+1];
    int i = lo;
    int j = mid+1;

    for (int k = 0; k <= hi; k++) 
        aux[k] = array[k];

    for (int k = 0; k <= hi; k++) {
        if (i > mid) array[k] = aux[j++];
        else if (j > hi) array[k] = aux[i++];
        else if (aux[i] < aux[j]) array[k] = aux[i++];
        else array[k] = aux[j++];
    }
}

void mergeSort(int array[], int lo, int hi) {
    
}

int main() {
    
    int array[] = {1,3,5,7,2,4,6,8};

    print_array(array, 8);

    mergeSort(array, 0, 7);
    
    print_array(array, 8);

    return 0;
}



