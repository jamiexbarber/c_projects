#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/*Questions to self*/
/*How pass an array of numbers through a function*/
/*How (and when) to produce my own header files*/

void swap(int *a, int *b){
    int temp;
    /*value stored in a */
    temp = *a;

    /*assign the value in b, as the new value stored in a*/ 
    *a = *b;

    /*assign the value in a, as the new value stored in b*/
    *b = temp;
}

int *allocate(int numofelements){
    int *p;

    p = (int *)calloc(numofelements, sizeof(int));
    if(p == NULL){
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    return(p);
}

/*The efficiency of bubble sort
The idea is */
void bubble_sort(int *array){
    int *first;
    int *next;
    int unsorted = 1;

    first = allocate(1);
    next = allocate(1);
    
    while(unsorted){
        unsorted = 0;
        first = array;
        next = first + 1;

        for(int i = 0; i < SIZE; i++){
            if (*first < *next){
                swap(first, next);
                unsorted = 1;
            }
            *(first++);
            *(next++);
        
        }
    }
}

int main()
{
    /*int arrayofnum[5] = {3, 6, 5, 0, 1};*/

    int *arrayofnum;

    arrayofnum = allocate(SIZE);
    for(int i = 0; i < SIZE; i++){
        *(arrayofnum+i) = rand() % 20;
        printf("%d, ", *(arrayofnum+i));
    }
    printf("\n");
    
   

    /*Bubble Sort*/
    bubble_sort(arrayofnum);

    for(int i = 0; i < SIZE; i++){
        printf("%d, ", arrayofnum[i]);
    }
    printf("\n");

    return(0);
}