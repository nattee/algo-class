#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	int na[3];
	int nep[3][3];

	memset(na, 0, sizeof(na));
	memset(nep, 0, sizeof(nep));
	scanf("%d", &n);

	int* s = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &s[i]);
		s[i]--;
		na[s[i]]++;
	}

	for (int i = 0; i < n; ++i)
	{
		if (i < na[0])
			nep[s[i]][0]++;
		else if (i < na[0] + na[1])
			nep[s[i]][1]++;
		else nep[s[i]][2]++;
	}
	int noCh = 
		min(nep[0][1], nep[1][0]) +
		min(nep[0][2], nep[2][0]) +
		min(nep[1][2], nep[2][1]) +
		2 * abs(nep[0][1] - nep[1][0]);

	//for (int i = 0; i < 3; ++i)
	//{
	//	for (int j = 0; j < 3; ++j)
	//		printf("%d ", nep[i][j]);
	//	printf("\n");
	//}
	printf("%d\n", noCh);
	delete[] s;
	
    //system("PAUSE");
    return EXIT_SUCCESS;
}
