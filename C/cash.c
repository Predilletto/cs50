#include <cs50.h> 
#include <stdio.h> 

const int penny=1; 
const int nickel=5;
const int dime=10; 
const int quarter=25; 


int return_change(int owed);

int main(void){
    int owed;

    do{
        owed = get_int("Change owed:");
    }
    while(owed < 1); 

    printf("%i\n", return_change(owed)); 



    return 0;
}



int return_change(int owed){
    int change = 0; 
    int rest = owed;

    if(owed >= quarter) {
        change += owed/quarter;
        rest= owed%(quarter*change);     
        printf("rest1: %i\n", rest);
    }
    if(rest >= dime){
        change += rest/dime;
        rest = rest%dime;
        printf("rest2: %i\n", rest);
    }
     if(rest >= nickel){
        change += rest/nickel;
        rest = rest%nickel;
        printf("rest3: %i\n", rest);
    } 
    if(rest >= penny) {
        change += rest/penny;
    }
 

    return change;
    
}