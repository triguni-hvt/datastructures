#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;
int isFull()
{
    if(top==(CAPACITY-1))
    return 1;
    else
    return 0;
    
}
int isEmpty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int element)
{
    if(isFull())
    {
        printf("Stack is Full\n\n");
    }
    else
    {
        top++;
        stack[top]=element;
        printf("%d is push succesfully\n\n",element);
    }
}
void pop()
{ int element;
    if(isEmpty())
    {
        printf("stack is Empty\n\n");
        
    }
    else
    {
       element=stack[top];
       top--;
       printf("%d is pop\n\n",element);
       
    }
}
void peek()
{
    if(isEmpty())
    {
        printf("stack is Empty\n\n");
        
    }
    else
    {
        printf("top element is %d\n\n",stack[top]);
    }
}
void traverse()
{int i;
    if(isEmpty())
    {
        printf("stack is Empty\n\n");
        
    }
    else
    {  
        printf("stack element: ");
        for(i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n\n");
    }
}
int main()
{int n,p;
printf("Enter 1 for push element in stack\nEnter 2 for pop element in stack\nEnter 3 to see top element in stack\n");
printf("Enter 4 for display element\nEnter 5 for EXIT\n");
while(1)
{
printf("Enter your choice:");
scanf("%d",&n);
   switch(n)
   {
       case 1:printf("Enter element ");
              scanf("%d",&p);
              push(p);
              break;
        case 2:pop();
              break;
        case 3:peek();
              break;
        case 4:traverse();
               break;
        case 5:exit(1);
               break;
        default:printf("Invalid input\n\n");
   }
}
}