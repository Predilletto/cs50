#include <cs50.h>
#include <stdio.h> 

int linear_search(int elements[], int element, int lenght);

int binary_search(int elements[], int element, int lenght);


int main(void) 
{
    int tester[] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n", linear_search(tester, 22, 10));
    printf("%d\n", binary_search(tester, 3, 10));
}

int linear_search(int elements[], int element, int lenght)
{
    for(int i = 0; i < lenght; i++)
    {
        if(elements[i] == element){
            return i;
        }
    }
    return -1; 
} 

int binary_search(int elements[], int element, int lenght)
{
    int low = 0;
    int high = lenght-1;
    do{

        int middle = (low + high)/2;
        if(elements[middle] == element){
            return middle;
        }
        else if(element < elements[middle]){
            high = middle -1; 
        }
        else if(element > elements[middle]){
            low = middle +1;
        }
    }
    while(low < high);

    return -1;
}