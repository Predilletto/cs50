#include <cs50.h>
#include <ctype.h>
#include <stdio.h> 

double get_score(string text);

int main(void)
{

    string text = get_string("text: ");
    int index = get_score(text)+0.5;

    if(index < 0){
        printf("Before Grade 1\n");
    } 
    else if(index >16){
        printf("Grade 16+\n");
    } 
    else{
        printf("Grade %i\n", index); 
    }
    

    
}
 


double get_score( string text){
    float words = 0;
    float setences = 0; 
    float letters = 0;
    int i = 0;
    double index = 0;

    while(text[i] != '\0'){
        char c = text [i];
        char d = text [i+1];

        if(isalpha(c)){
            if(!isalpha(d)){
                if(d != '\'' && d != '-'){
                words++;

                } 
            }
            letters++;
        }
        else if((c == '.' && d !='.') || c == '!' || c== '?') {
            setences++; 
        }
        i++; 
    } 
  
    double l = (letters/words) * 100;   
    double s = (setences/words) * 100; 

    index = 0.0588 * l - 0.296 * s - 15.8;

    return index;     
} 


