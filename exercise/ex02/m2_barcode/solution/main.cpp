#include <iostream>
#include <string.h>

using namespace std;

void ResizeArray(int** ary, int* cap, int length)
{
	if (length > *cap)
	{
		int newCap = length + length / 2;
		int* tmp = new int[newCap];
		if (*ary)
		{
			memcpy(tmp, *ary, sizeof(int) * (*cap));
			delete[] (*ary);
		}
		*ary = tmp;
		*cap = newCap;
	}
}

void DeleteArray(int* ary, int length, int offset, int dLen)
{
	if (offset >= length - dLen) return;
	dLen = min(dLen, length - (offset + dLen));
	memcpy(ary + offset, ary + (length - dLen), sizeof(int) * dLen);
}

int BarcodeCounting(int N, int M, int K)
{
	int* B = 0;
	int cap = 0;
	int len = 1;

	K++;
	ResizeArray(&B, &cap, K * len);
	for (int i = 0; i < K; ++i) B[i] = 1;

	for (int i = K; i < N; ++i)
	{
		int tLen = len;
		for (int j = 0; j < len; ++j)
		{
			int* b = B + j * K;
			for (int k = K - 1; k >= 0; --k)
			{
				if (b[k] < M)
				{
					ResizeArray(&B, &cap, K * (++tLen));
					b = B + j * K;
					int* tb = B + (tLen - 1) * K;
					memcpy(tb, b, sizeof(int) * K);
					tb[k]++;
				}
				if (b[k] != 1) break;
			}
		}
		DeleteArray(B, tLen * K, 0, len * K);
		len = tLen - len;
	}
	
	// print debug
	//for (int j = 0; j < len; ++j)
	//{
	//	int* b = B + j * K;
	//	int i = 0;
	//	for (int k = 0; k < K; ++k)
	//		for (int l = 0; l < b[k]; ++l)
	//			printf("%d", k % 2);
	//	printf("%\n");
	//}

	delete[] B;
	return len;
}

int main(int argc, char *argv[])
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
	printf("%d\n", BarcodeCounting(N, M, K));
}
