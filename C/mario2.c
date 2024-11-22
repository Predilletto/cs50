

#include <stdio.h>

void draw_blocks(int height);

int main()
{
    
    int height;

   do{
        printf("Height:");
        scanf("%d", &height);
   } while (height < 1);
   
   printf("\n");

   draw_blocks(height);
   return 0;
}



void draw_blocks(int height) {
	int blanks; 
        
    	blanks=height;
    	int blocks=1;
    
    for(int i=0; i < height; i++){
        for(int j=0; j<blanks; j++){
     
            printf(" "); 

        }
        for(int k=0; k < blocks; k++){
            printf("#");    

        }
        printf("  ");
        for(int l=0; l<blocks; l++){
            printf("#");
        }
        printf("\n"); 
        blocks++;
        blanks--;
        
    }
    
    
    
}