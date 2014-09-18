#include <iostream>
#include <string.h>

using namespace std;

int LCS(char* X, char* Y)
{
	int lenX = (int)strlen(X);
	int lenY = (int)strlen(Y);

	int* L = new int[(lenX + 1) * (lenY + 1)];
	int* prev = new int[lenX * lenY];	// \ = 0, ^ = 1, < = 2

#define ML(j, i) L[(j + 1) * (lenX + 1) + (i + 1)]
#define MP(j, i) prev[(j) * lenX + (i)]

	memset(L, 0, sizeof(int) * (lenX + 1) * (lenY + 1));

	for (int j = 0; j < lenY; ++j)
	{
		for (int i = 0; i < lenX; ++i)
		{
			if (X[i] == Y[j])
			{
				ML(j, i) = ML(j - 1, i - 1) + 1;
				MP(j, i) = 0;
			}
			else if (ML(j - 1, i) > ML(j, i - 1))
			{
				ML(j, i) = ML(j - 1, i);
				MP(j, i) = 1;
			}
			else
			{
				ML(j, i) = ML(j, i - 1);
				MP(j, i) = 2;
			}
		}
	}


	int i = lenX - 1;
	int j = lenY - 1;
	int k = ML(j, i);
	char* tmp = new char[k + 1];
	tmp[k] = '\0';
	while (i >= 0 && j >= 0)
	{
		if (MP(j, i) == 0)
		{
			tmp[--k] = X[i];
			i--; j--;
		}
		else if (MP(j, i) == 1) j--;
		else i--;
	}

    // print debug
	//printf("%s\n", tmp);
	
	int res = ML(lenY - 1, lenX - 1);

	delete[] L;
	delete[] prev;
	
	return res;
}

int main(int argc, char *argv[])
{
	char X[501];
	char Y[501];

  scanf("%s", X);
  scanf("%s", Y);
	printf("%d\n", LCS(X, Y));
	
}
