#include <stdio.h>

using namespace std;


int begin[700000];
int num;

void genSeq() {
    begin[1] = 1;
    begin[2] = 2;
    begin[3] = 4;
    int idx = 3; //index of [begin] to be filled
    int i = 2; //i is the count
    do {
        for (int j = begin[i+1];j > begin[i];--j)
        {
            begin[idx] = begin[idx-1] + i;
			//printf("%d %d %d\n",idx,begin[idx],i);
            idx++;
        }
        i++;

    } while (begin[idx-1] < 2000000000);
    num = idx-1;
}


int bisect(int key,int l,int r) {
    //printf("bisect at %d %d\n",l,r);
    if (l >= r) {
        return l;
    }

    int m = (l+r) / 2;
    if (begin[m] <= key && begin[m+1] > key) return m;
    if (begin[m] > key) return bisect(key,l,m-1);
    return bisect(key,m+1,r);

}


int main(int argc, char *argv[])
{
    genSeq();
    int n;
    int count = 0;
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &n);
        printf("%d\n", bisect(n,1,num));
    }

    return 0;
}
