//time() 함수


#include <stdio.h>

#include <time.h>



int main() {

    int sum = 0;

    time_t start = time(NULL);



    for (int i = 0; i < 100000; i++)

        for (int j = 0; j < 100000; j++)

            sum += i * j;



    time_t end = time(NULL);

    printf("소요시간: %lf\n", (double)(end - start)); // 노트북 gram 약 33초

}

    /*
//clock() 함수



#include <stdio.h>

#include <time.h>



int main() {

    clock_t start = clock();



    int sum = 0;

    for (int i = 0; i < 100000; ++i)

        for (int j = 0; j < 100000; ++j)

            sum += 1;

    clock_t end = clock();

    printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //LG Gram 약 29초

}*/