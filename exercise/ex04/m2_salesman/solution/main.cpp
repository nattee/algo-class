#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n, m;
	scanf("%d %d", &n, &m);

	int* s = new int[m];
	int* d = new int[m];
	int* p = new int[n * 2];
	for (int i = 0; i < m; ++i)
		scanf("%d", &s[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &d[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &p[i * 2], &p[i * 2 + 1]);

	int* sd0 = new int[m];
	int* sd1 = new int[m];

	sd0[0] = 0;
	for (int i = 1; i <  m; ++i)
		sd0[i] = sd0[i - 1] + d[i - 1];
	sd0[0] = sd0[m - 1] + d[m - 1];

	sd1[m - 1] = 0;
	for (int i = m - 2; i >= 0; --i)
		sd1[i] = sd1[i + 1] + d[i];
	sd1[m - 1] = sd1[0] + d[m - 1];

#define GETDIST(dd, x, y) 				\
	{									\
		int d0 = sd0[(y)] - sd0[(x)];	\
		if (d0 < 0) d0 += sd0[0];		\
		int d1 = sd1[(y)] - sd1[(x)];	\
		if (d1 < 0) d1 += sd1[m - 1];	\
		(dd) = min(d0, d1);				\
	}

	for (int i = 0; i < n; ++i)
	{
		int a = p[i * 2];
		int b = p[i * 2 + 1];

		int sumD = 0;
		for (int j = 0; j < m; ++j)
		{
			int x = s[j];
			int y = s[(j + 1) % m];
			
			int dxy, dxa, dxb, day, dby;
			GETDIST(dxy, x, y);
			GETDIST(dxa, x, a);
			GETDIST(dxb, x, b);
			GETDIST(day, a, y);
			GETDIST(dby, b, y);
			
			int minD = dxy;
			if (dxa + dby < minD) minD = dxa + dby;
			if (dxb + day < minD) minD = dxb + day;
			sumD += minD;
		}

		printf("%d\n", sumD);
	}

	delete[] s;
	delete[] d;
	delete[] p;
	delete[] sd0;
	delete[] sd1;
}
