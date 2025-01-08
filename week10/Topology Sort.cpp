#include<stdio.h>
#define MAX_SIZE 6
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE] = {5, 3, 8, 1, 2, 7};

void selection_sort(int list[], int n) {
    int i, j, least, temp;
    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) // j는 i+1부터 시작해야 함
            if (list[j] < list[least])
                least = j;
        SWAP(list[i], list[least], temp);
    }
}


void print_sort(int list[], int n){
    for (int i = 0; i < n; i++)
        printf("%2d", list[i]);
    
    printf("\n");

}

int main(){
    int n = MAX_SIZE;
    selection_sort(list, n);
    print_sort(list, n);

}