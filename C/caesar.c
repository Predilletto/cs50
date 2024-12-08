#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int string_to_int(string s); 

bool is_digit(char c);

void cypher(string text, int key);

int main(int argc,char *argv[]){

    if(argc != 2){
        printf("Wrong Args, please try again.\n");
        return 1; 
    }
    else {
    int key = string_to_int(argv[1]);
    if(key == -1){
        printf("Usage: key\n");
        return 1;
    } 
    else{
        string plain_text = get_string("Plaintext:\n");
        cypher(plain_text,key);
    }
    }
}

int string_to_int(string s){
    int lenght = strlen(s);
    int digit =0;
    for(int i = 0; i < lenght; i++){
        if(is_digit(s[i])){
            printf("%i\n", digit);
             digit = digit * 10 + (s[i] - '0');
        }
        else {
            return -1;
        } 
    }
    return digit;

}

bool is_digit(char c){
    return c >= '0' && c <= '9'; 
}

void cypher(string text, int key){
    int lenght = strlen(text); 
    char cyphed[lenght];

    for( int i = 0; i < lenght; i++){
        char c = text[i]; 

        if(islower(c)){
            cyphed[i]= 'a' + (c - 'a' + key)%26; 
        }
        else if(isupper(c)){
            cyphed[i] = 'A' + (c - 'A' + key)%26;
        }
        else {
            cyphed[i] = c;
        }
    }

    printf("ciphertext: %s\n",cyphed);
}