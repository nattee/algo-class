#include <iostream>
#include <stdlib.h>

using namespace std;

int findMSS(int* data, int n, int* a, int* b)
{
	if (n == 1)
	{
        *a = 0;
        *b = 0;
		return data[0];
    }

	int hn = n / 2;
	int a0, b0, a1, b1;
	int m0 = findMSS(data, hn, &a0, &b0);
	int m1 = findMSS(data + hn, n - hn, &a1, &b1);
	a1 += hn;
	b1 += hn;

    int a2 = hn - 1;
	int t0 = data[hn - 1];
	int m2 = t0;
	for (int i = hn - 2; i >= 0; --i)
	{
		t0 += data[i];
		if (t0 > m2)
		{
            a2 = i;
            m2 = t0;
        }
	}

    int b2 = hn;
	int t1 = data[hn];
	int m3 = t1;
	for (int i = hn + 1; i < n; ++i)
	{
		t1 += data[i];
		if (t1 > m3)
		{
            b2 = i;
            m3 = t1;
        }
	}

    *a = a2;
    *b = b2;
    int res = m2 + m3;
    if (m0 > res)
    {
        res = m0;
        *a = a0;
        *b = b0;
    }
    if (m1 > res)
    {
        res = m1;
        *a = a1;
        *b = b1;
    }
	return res;
}

void genData(const char *filename,int n)
{
    FILE *fp = fopen(filename,"w");
    fprintf(fp,"%d\n",n);
    float range = 10000;
    for (int i = 0;i < n;i++) {
        int v = rand() * range / (RAND_MAX+1.0);
        v -= (range*0.5);
        fprintf(fp,"%d ",v);
    }
    fclose(fp);
}

void genData() {
    genData("1.in",1000);
    genData("2.in",2000);
    genData("3.in",10000);
    genData("4.in",10000);
    genData("5.in",10000);
    genData("6.in",50000);
    genData("7.in",50000);
    genData("8.in",50000);
    genData("9.in",50000);
    genData("10.in",50000);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    //genData();
    //return 0;

	int n = 0;
	scanf("%d", &n);
	int* data = new int[n];
	for (int i = 0; i < n; ++i)
	   scanf("%d", &data[i]);

	int a, b;
	int res = findMSS(data, n, &a, &b);
	printf("%d\n", res);
	//printf("%d %d %d\n", res, a, b);

    //system("PAUSE");
    delete[] data;
}
