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


/*Bubble Sort:
Two pointers will point to the first element and the
second element in an array, 

the two elements will be compared, 

if one is smaller than the other, the elements are swapped, 

if not, both pointers are incremented and the next two elements are compared

this is done until every element in the array has been compared

if no swaps are needed for an entire for loop (pass-through), the array is sorted

Worst-case Efficiency: N**2, for 5 elements 10 comparisons, 10 swaps */

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

    free(first);
    free(next);
}

void selection_sort(int* array){
int *first;
int smallest;
int smallest_index;
int swap_num = 0;
int unsorted = 1;

first = allocate(1);




while(unsorted){

    first = array;     /*address of array[0]*/
    smallest = *array; /*array[0]*/
    unsorted = 0;


    for(int i = 0; i < SIZE; i++){
        if(*first < smallest){
            smallest = *first;
            smallest_index = i;
            swap_num = 1;
            unsorted = 1;
        }
    }
    if(swap_num){
        swap(first,(array+smallest_index));
        swap_num = 0;
    }
    (first++);
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
    /*bubble_sort(arrayofnum);*/

    /*Selection Sort*/
    selection_sort(arrayofnum);

    for(int i = 0; i < SIZE; i++){
        printf("%d, ", arrayofnum[i]);
    }
    printf("\n");

    return(0);
}