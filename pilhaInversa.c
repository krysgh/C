#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5


typedef struct{
  
  int top;
  int info[MAX];


}Stack;



void startStack(Stack *p, int idStack){

  
  printf("Stack %d created.\n\n", idStack);

  printf("Initializing stack %d...\n\n", idStack);

  p->top = -1;

  printf("Stack %d initialized successfully.\n\n\n", idStack);

}


bool isEMPTY(Stack *p){

  return p->top == -1;
    
}


bool isFULL(Stack *p){

  return p->top == MAX -1; 

}


void push(Stack *p, int value, int idStack){

    if(isFULL(p)){

      printf("Stack %d is full.\n\n", idStack);

    }

    else{
          
      p->info[++p->top] = value;
  
      printf("Pushing %d to the Stack %d.\n\n", value, idStack);
    
    }
      
}


int pop(Stack *p, int idStack){

   if(isEMPTY(p)){
   
     printf("Stack %d is empty.\n\n", idStack);

     return -1;

   }   

   else{
  
     int value = p->info[p->top--];

     printf("Popping %d from the Stack %d.\n\n", value, idStack);


     return value; 

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

      printf("%d\n", p->info[i]);
     
     } 


     printf("\n\n");

  }

}



int main(void) {

    printf("\n");

    Stack p1;

    startStack(&p1, 1);

    push(&p1, 10, 1);  
    push(&p1, 11, 1);
    push(&p1, 12, 1);
    push(&p1, 13, 1);
    push(&p1, 14, 1);

    showStack(&p1, 1);


    Stack p2;
    
    startStack(&p2, 2);


    while(!isEMPTY(&p1)){

      push(&p2, pop(&p1, 1), 2);

    }

    
    showStack(&p1, 1);

    showStack(&p2, 2);


    while(!isEMPTY(&p2)){
    
      pop(&p2, 2);
    
    }

    showStack(&p2,2);

    return 0;

}
