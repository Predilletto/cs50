#include <cs50.h> 
#include <stdio.h>

void array_to_string(int arr[], int size);

void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);

int main(void) {
    int tester[] = {2,45,62,23,4,7,16,0,0,1}; 

    array_to_string(tester,10);
    selection_sort(tester, 10);
    array_to_string(tester,10);
    bubble_sort(tester,10);
    array_to_string(tester,10);
}


void array_to_string(int arr[], int size){
    printf("[ ");
    
    for(int i=0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void selection_sort(int arr[], int size){
    
    int start = 0;
    
    while(start < size -1) {
        int min_index = start;
        for(int i = start +1; i<size; i++)
        {
         if(arr[i]< arr[min_index]){
            min_index = i;
         } 
        }
    if(min_index != start){
            int temp = arr[min_index];
            arr[min_index] = arr[start];
            arr[start]= temp;
         }

        start++;
    }
}

void bubble_sort(int arr[], int size) {
    int start = 0;
    int swapped;

    while(start < size -1){
        swapped = 0;
        for(int i = 0; i < size -2; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]= temp;
                swapped=1; 
            }
        }   
        if(!swapped){
            break;
        }
        start++;
    }

}