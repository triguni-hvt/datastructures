#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Stack
{
    int* arr;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int*)malloc(sizeof(int)*capacity);
    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity;
}

void push(struct Stack* stack, char op)
{
    stack->arr[++stack->top] = op;
}

char pop(struct Stack* stack)
{
    if(isEmpty(stack))
        return '$';
    return stack->arr[stack->top--];
}

char topelement(struct Stack* stack)
{
    return stack->arr[stack->top];
}

int isOperand(char ch)
{
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');  
}

int opPrec(char op)
{
    switch(op)
    {
        case '+' :
        case '-' :
            return 1;
        
        case '/' :
        case '*' :
            return 2;
            
        case '^' :
            return 3;
    }
    return -1;
}

 
int infixToPostfix(char* exp) 
{ 
    int i, k; 
  
     
    struct Stack* stack = createStack(strlen(exp)); 
    if(!stack)
        return -1 ; 
  
    for (i = 0, k = -1; exp[i]; ++i) 
    { 
        
        if (isOperand(exp[i])) 
            exp[++k] = exp[i]; 
          
        
        else if (exp[i] == '(') 
            push(stack, exp[i]); 
          
        
        else if (exp[i] == ')') 
        { 
            while (!isEmpty(stack) && topelement(stack) != '(') 
                exp[++k] = pop(stack); 
            if (!isEmpty(stack) && topelement(stack) != '(') 
                return -1;            
            else
                pop(stack); 
        } 
        else 
        { 
            while (!isEmpty(stack) && opPrec(exp[i]) <= opPrec(topelement(stack))) 
                exp[++k] = pop(stack); 
            push(stack, exp[i]); 
        } 
  
    } 
  
    while (!isEmpty(stack)) 
        exp[++k] = pop(stack ); 
  
    exp[++k] = '\0'; 
    printf( "%s", exp ); 
}

int main() 
{
	char exp[] = "a+b*c";
	infixToPostfix(exp);
	return 0;
}