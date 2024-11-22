#include <cs50.h> 
#include <ctype.h>  
#include <stdio.h> 

const int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10}; 


int get_points(string word);



int main(void){
        string word1;
        string word2;
        
    
        word1 = get_string("Player 1:"); 
        word2 = get_string("Player 2:");
    

        int points1 = get_points(word1);
        int points2 = get_points(word2); 

        if(points1 == points2) {
            printf("Tie\n");
        }else if(points1 > points2) {
            printf("Player 1 wins\n");
        } else{ 
            printf("Player 2 wins\n");
        }


    return 0;
}



int get_points(string word){
    int sum = 0;
    int i = 0;
    char letter;

    while(word[i]!= '\0') {    
        letter = toupper(word[i]);
        if(isalpha(letter)) {
            int index= letter - 65;
            sum+= points[index];         
        };
        i++;
    }
    return sum; 
}