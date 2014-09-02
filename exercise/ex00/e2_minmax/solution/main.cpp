#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[])
{
    int a,b,c;
	scanf("%d %d\n",&a,&b);
	scanf("%d\n",&c);
	int **foo = new int*[a];
	for(int i=0;i<a;i++) {
		foo[i] = new int[b];
	}

	for(int i=0;i<a;i++) {
		for(int j=0;j<b;j++) {
			scanf("%d",&foo[i][j]);
		}
	}

	int r1,c1,r2,c2;
  //int max_r,max_c;
	for (int i = 0; i < c; i++) {
    	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    	if(r1 > r2 || c1 > c2)
    		printf("INVALID\n");
    	else if((r1 > a && r2 > a) || (c1 > b && c2 >b) || (r1 < 1 && r2 < 1) || (c1 < 1 && c2 < 1))
    		printf("OUTSIDE\n");
    	else {
    		if(r1 < 1)
    			r1 = 1;
    		if(r2 < 1)
    			r2 = 1;
    		if(r1 > a)
    			r1 = a;
    		if(r2 > a)
    			r2 = a;
    		if(c1 < 1)
    			c1 = 1;
    		if(c2 < 1)
    			c2 = 1;
    		if(c1 > b)
    			c1 = b;
    		if(c2 > b)
    			c2 = b;
    		int max = -INT_MAX;
        //printf(" searching from row %d-->%d and col %d-->%d\n",r1,r2,c1,c2);
    		for(int i=r1-1;i<r2;i++) {
    			for(int j=c1-1;j<c2;j++) {
    				if(max < foo[i][j]) {
    					max = foo[i][j];
              //max_r = i+1;
              //max_c = j+1;
            }
    			}
    		}
    		printf("%d\n",max);
    		//printf("at r =  %d c = %d\n",max_r,max_c);
    	}
    }

}
