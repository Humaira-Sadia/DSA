#include<stdio.h>    
void fib(int n){    
    static int x=0,y=1,z;    
    if(n>0){    
         z = x + y;    
         x = y;    
         y = z;    
         printf("%d ",z);    
         fib(n-1);    
    }    
}    
int main(){    
    int n;    
    printf("Enter the number of elements: ");    
    scanf("%d",&n);    
    printf("\nFibonacci Series: ");    
    printf("%d %d ",0,1);    
    fib(n-2);//n-2 because 2 numbers are already printed.    
  return 0;  
 }    