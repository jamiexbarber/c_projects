#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/*Selection Sort
Selection sort uses half the number of steps (worst-case estimate) as 
Bubble sort.

While Bubble Sort makes a swap for every comparison 
(there may be several swaps in one array pass-through), 

Selection Sort only makes one swap per pass-through, after choosing the smallest number in that pass-through

The twice as fast efficiency (N**2/2) is considered the same as N**2 because we don't consider constants in big O notation
*/
void selection_sort(int* array){
    int *first;
    int smallest;
    int smallest_index;
    int swap_num = 0;

    first = allocate(1);

    for(int i = 0; i < SIZE-1; i++){
        first = (array+i);     /*address of array[i]*/
        smallest = *(array+i); /*initialize smallest to array[i]*/
        for(int j = i+1; j < SIZE; j++){
            if(*(array+j) < smallest){
                smallest = *(array+j);
                smallest_index = j;
                swap_num = 1;
            }
        }
        if(swap_num){
        swap(first,(array+smallest_index));
        swap_num = 0;
        }
    }
}
/*Insertion Sort
Each value in the array is compared with all the values to the left of the chosen value. 

Assuming least to greatest, for each array value, larger than the chosen value, the array value
will be shifted to the right.

Once the chosen value is greater than an array value, the chosen value will be placed into the position just to 
the right of that array value (for loop should be broken)

This is interesting because in the worst case scenario, efficiency is N**2 (~N**2/2 comparisons and N**2/2 shifts worst case)
But in the average case scenario, it's possible to end a pass-through early, to just compare the value to the left and no shift required
so in the average case scenario, efficiency is closer to N**2/2 making it the same as Selection Sort.

The trick is, we don't need to compare all the left array values, if the first value to the left is less than the chosen value, loop broken
and the pass-through can end, the chosen value can stay and the next value can be chosen.
*/
void insertion_sort(int* array){
    int* index;
    int chosen_value;
    int left_value_position;

    index = allocate(1);

    for(int i = 1; i < SIZE; i++){
        chosen_value = *(array+i);
        left_value_position = (i - 1);

        printf("chosen_value:%d\n", chosen_value);
        while (left_value_position >= 0){
            if (chosen_value < *(array + left_value_position)){
                printf("array+left_value_posi:%d, left_value_position:%d\n", *(array + left_value_position), left_value_position);
                swap((array+left_value_position), (array+left_value_position+1)); /*shift*/
                left_value_position--;
            }
            else{
                break;
            }

        }
        
    }

    free(index);

}

int main()
{
    /*int arrayofnum[5] = {3, 6, 5, 0, 1};*/

    int *arrayofnum;
    clock_t start, end;
    double runtime;

    arrayofnum = allocate(SIZE);
    for(int i = 0; i < SIZE; i++){
        *(arrayofnum+i) = rand() % 15;
        printf("%d, ", *(arrayofnum+i));
    }
    printf("\n");
    
    start = clock();
   

    /*Bubble Sort*/
    bubble_sort(arrayofnum);

    /*Selection Sort*/
    /*selection_sort(arrayofnum);*/

    /*Insertion Sort*/
    /*insertion_sort(arrayofnum);*/

    end = clock();

    for(int i = 0; i < SIZE; i++){
        printf("%d, ", arrayofnum[i]);
    }
    printf("\n");

    runtime = (double) (end-start / CLOCKS_PER_SEC);
    printf("Runtime:%f", runtime);

    return(0);
}