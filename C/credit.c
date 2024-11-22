#include <cs50.h>
#include <stdio.h> 

void check_card(long card);
void display_last_digit(long card); 


int main(void) {
    long card; 

    do{
        card = get_long("Number: ");

    } while(card < 1);

   check_card(card);




    return 0;
}


void check_card(long card){
    long rest=card;
    long digit;
    long sum=0;
bool just_sum=true;         
    int card_type; 

    while(rest > 0){
        if(rest >= 10 && rest <=99){
            card_type = rest;
        } 

        digit=rest%10; 
        if(just_sum){
            rest = (rest/10);
            sum += digit;
            just_sum=false;
        } else{
            if(digit*2 >= 10){

                sum+=((digit*2)%10);
                sum+=(digit*2)/10;
                rest = (rest/10);
                just_sum=true;
             }
         else {

                rest = (rest/10);
                sum += digit*2; 
                just_sum=true;
            } 
        }    
    } 

    if(sum%10 == 0 && (card_type == 34 || card_type == 37)){
        printf("AMEX\n");
    }
    else if(sum%10==0 && (card_type >= 51 && card_type <= 55)){
        printf("MASTERCARD\n");
    }
    else if(sum%10 ==0 && (card_type >=40 && card_type <= 49)){
        printf("VISA\n");
    }
    else{
        printf("Invalid \n");
    }
   
}
