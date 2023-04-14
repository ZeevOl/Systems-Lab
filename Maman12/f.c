#include "declerations.h"


int *get_set(int*size) {
    int *p = (int *) calloc(ENLARGE_SIZE, sizeof(int));
    int *res;
    if (p == NULL) {
        printf("Error: memory can't be allocated!");
        exit(0);
    }
    int num = 0;
    int counter = 0;
    while (scanf("%d", &num)) {

        if (counter % ENLARGE_SIZE==0 ) {
            int *p1 = realloc(p, (counter+ENLARGE_SIZE)* sizeof(int) );
            if (p1 == NULL) {
                printf("Error: memory can't be allocated!");
                exit(0);
            }
            p = p1;
        }
        p[counter] = num;
        counter++;



    }
    res = remove_duplications(p, counter,size);
    free(p);
    return res;

}


void print_set(int *arr, int counter) {
    int i = 0;
    printf("{");
    for (i; i < counter; ++i) {
        if (i == counter - 1)printf("%d}", arr[i]);
        else
            printf("%d,", arr[i]);

    }
    free(arr);

}

int *remove_duplications(int *arr, int counter,int *size) {
    int *newArr = (int *) calloc(counter, sizeof(int));
    int j = 0;
    int i = 0;
    int k = 0;
    int newSize=0;

    if (newArr == NULL) {
        printf("Error: memory can't be allocated!");
        exit(0);
    }

    for (i; i < counter; i++) {
        for (j; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }

        }
        if (j == i) {
            newArr[k] = arr[i];
            k++;
            newSize++;
        }

        j = 0;

    }
*size=newSize;
    return newArr;


}


