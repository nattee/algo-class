#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int h,m;
    int min;
    int nm,nh;
    scanf("%d %d",&h,&m);
    scanf("%d",&min);
    nm = (m + min) % 60;
    nh = ( h + (m + min) / 60) ;
    nh = nh % 24;
    printf("%02d %02d\n",nh,nm);
}
