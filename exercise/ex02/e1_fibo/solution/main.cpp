#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
 
    // read input from keyboard and store in n
    int n;             
    scanf("%d",&n);
 
    int curr; // current fibonacci number
    int next; // the next fibonacci number
 
    // compute n-th fibo number
    curr = 0;            
    next = 1;
    for (int i = 0;i < n;i++) {
        int tmp = next + curr;
        curr = next;
        next = tmp;
    }
 
    //display output
    printf("%d\n",curr);
 
}
