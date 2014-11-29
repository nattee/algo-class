#include <stdio.h>
#include <stdlib.h>

#define MaxN 212
#define Infinity (100000000000000000LL)

typedef long long int __int64;

int n, m, kk;
int a[MaxN][5];
__int64 d1[MaxN][MaxN];
__int64 d[MaxN][MaxN];
__int64 tmp[MaxN][MaxN];
__int64 ans;

void Find(int _m)
{
//	printf("[%d] ", _m);
	if( _m <= 1 )
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = d1[i][j];

		return;
	}

	Find(_m/2);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			tmp[i][j] = Infinity;

			for(int k = 0; k < n; k++)
			{
				if( tmp[i][j] > d[i][k] + d[k][j] )
					tmp[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			d[i][j] = tmp[i][j];

	if( _m%2 == 1 )
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				tmp[i][j] = Infinity;

				for(int k = 0; k < n; k++)
				{
					if( tmp[i][j] > d[i][k] + d1[k][j] )
						tmp[i][j] = d[i][k] + d1[k][j];
				}
			}
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = tmp[i][j];
	}
}

bool ReadData()
{
	scanf("%d %d %d", &m, &n, &kk);
	if( n == 0 && m == 0 && kk == 0 )
		return false;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);

	// Solve
	for(int i = 0; i < MaxN; i++)
		for(int j = 0; j < MaxN; j++)
			tmp[i][j] = Infinity;
/*/
	for(int i = 0; i < 2*n; i++)
	{
		for(int j = 0; j < 2*n; j++)
			printf("%I64d ", tmp[i][j]);
		printf("\n");
	}
//*/

	for(int i = 0; i < n; i++)
	{
		tmp[i][i] = 0;
		tmp[i][(i+n-1)%n] = a[i][0];
		tmp[i][(i+n+1)%n] = a[i][1];
		tmp[i][(i+n-1)%n + n] = a[i][2];
		tmp[i][(i+n+0)%n + n] = a[i][3];
		tmp[i][(i+n+1)%n + n] = a[i][4];

		tmp[i + n][(i+n-1)%n + n] = a[i][0];
		tmp[i + n][(i+n+1)%n + n] = a[i][1];
	}
/*/
	for(int i = 0; i < 2*n; i++)
	{
		for(int j = 0; j < 2*n; j++)
			printf("%I64d ", tmp[i][j]);
		printf("\n");
	}
//*/

	for(int i = 0; i < 2*n; i++)
	{
		for(int j = 0; j < 2*n; j++)
		{
			for(int k = 0; k < 2*n; k++)
			{
				if( tmp[j][k] > tmp[j][i] + tmp[i][k] )
					tmp[j][k] = tmp[j][i] + tmp[i][k];
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			d1[i][j] = tmp[i][j+n];

	Find(m-1);

/*/
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%I64d ", d1[i][j]);
		printf("\n");
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%I64d ", d[i][j]);
		printf("\n");
	}
//*/
	ans = d[0][kk];
	printf("%lld\n", ans);

	return false;
}

void WriteData()
{
}

int main()
{
	//freopen("Karin_in.txt", "rt", stdin);
	//freopen("Karin_out.txt", "wt", stdout);
	//freopen("Karin_sample_in.txt", "rt", stdin);
	//freopen("Karin_sample_out.txt", "wt", stdout);
	while(ReadData());
	return 0;
}
