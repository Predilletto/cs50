#include <cs50.h>
#include <ctype.h>
#include <stdio.h> 

double get_score(string text);
int round_double(double number); 

int main(void){

    string text = get_string("text: ");
    double index = get_score(text);

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

        if(isalpha(c)){
            if(!isalpha(text[i+1])){
                words++;
            }
            letters++;
        }
        else if(c == '.' || c == '!' || c== '?') {
            setences++; 
        }
        i++; 
    } 
    printf("letters: %f, words: %f, setences: %f\n", letters, words, setences);
    double l = (letters/words) * 100;   
    double s = (setences/words) * 100; 
    printf("L: %f, S: %f\n", l,s);
    

    index = 0.0588 * l - 0.296 * s - 15.8;

    return index;     
} 


