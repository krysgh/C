#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 1000


typedef struct{
  
  int top;
  char info[MAX];

}Stack;



void startStack(Stack *p, int idStack){

  printf("Stack %d created.\n", idStack);

  printf("Initializing stack %d...\n", idStack);

  p->top = -1;

  printf("Stack %d initialized successfully.\n\n", idStack);

}


bool isEMPTY(Stack *p){

  return p->top == -1;
    
}


bool isFULL(Stack *p){

  return p->top == MAX -1; 

}


void push(Stack *p, char text, int idStack){

    if(isFULL(p)){

      printf("Stack %d is full.\n\n", idStack);

    }

    else{
          
      p->info[++p->top] = text;
  
      printf("Pushing %c to the Stack %d.\n\n", text, idStack);
    
    }
      
}


int pop(Stack *p, int idStack){

   if(isEMPTY(p)){
   
     printf("Stack %d is empty.\n\n", idStack);

     return -1;

   }   

   else{
  
     char character = p->info[p->top--];

     printf("Popping %c from the Stack %d.\n\n", character, idStack);

     return character; 

   } 
}


void showStack(Stack *p, int idStack){

  if(isEMPTY(p)){
     
     printf("Stack %d is empty.\n\n", idStack);

  }

  else{
  
     int i;

     printf("Stack %d:\n", idStack);


     for( i = p->top; i >= 0; i--){

      printf("%c\n", p->info[i]);
     
     } 

     printf("\n\n");

  }
}

void isPalindrome(Stack *p, char text[]){
    
    for (int i = 0; text[i] != '\0'; i++) {
        
        if (isalnum(text[i])) {
            push(p, text[i], 1); 
        }
    }
    
    showStack(p, 1);
    
    for (int i = 0; text[i] != '\0'; i++) {
        
        if (isalnum(text[i])) {
            
            if (text[i] != pop(p, 1)) {
                puts("The text is not a palindrome.");
                exit(1);
            }
        }
    }
    
    puts("The text is a palindrome.");

}

int main(void){

    Stack stack;
    unsigned char text[MAX];
    
    startStack(&stack, 1);
    
    printf("Type a text:");
    scanf("%[^\n]", text);
    puts("\n");
    isPalindrome(&stack, text);
    
    return 0;
}