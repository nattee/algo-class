#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int CurrencyDenomination(int value, int* den, int dLen)
{
	int* V = new int[value + 1];
	int* C = new int[(value + 1) * dLen];
#define MC(j, i) C[(j) * dLen + (i)]

	memset(C, 0, sizeof(int) * (value + 1) * dLen);

	for (int i = 0; i <= value; ++i) V[i] = -1;
	for (int i = 0; i < dLen; ++i)
	{
		V[den[i]] = 1;
		MC(den[i], i) = 1;
	}
	V[0] = 0;

	for (int i = 0; i <= value; ++i)
	{
		if (V[i] >= 0) continue;

		int minCount = -1;
		for (int j = i / 2; j > 0; --j)
		{
			if (V[j] < 0 || V[i - j] < 0) continue;
			int count = V[j] + V[i - j];
			if (count < minCount || minCount == -1)
			{
				minCount = count;
				for (int k = 0; k < dLen; ++k)
					MC(i, k) = MC(j, k) + MC(i - j, k);
			}
		}
		V[i] = minCount;
		if (minCount == -1)
			for (int k = 0; k < dLen; ++k)
				MC(i, k) = 0;
	}

    // print debug
	//printf("   ");
	//for (int k = 0; k < dLen; ++k)
	//	printf("%d ", den[k]);
	//printf("\n");
	//for (int i = 0; i <= value; ++i)
	//{
	//	printf("%d: ", V[i]);
	//	for (int k = 0; k < dLen; ++k)
	//		printf("%d ", MC(i, k));
	//	printf("\n");
	//}

	int count = V[value];
	delete[] V;
	delete[] C;

	return count;
}

int main(int argc, char *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    int* den = new int[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &den[i]);
        
	printf("%d\n", CurrencyDenomination(M, den, N) );

    delete[] den;
    return EXIT_SUCCESS;
}
