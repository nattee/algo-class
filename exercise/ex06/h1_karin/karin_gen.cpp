#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

#define MaxN 212
#define Infinity (100000000000000000LL)

using namespace std;

FILE *fin;
FILE *fout;

typedef long long int __int64;

int n, m, kk;
int a[MaxN][5];
__int64 d1[MaxN][MaxN];
__int64 d[MaxN][MaxN];
__int64 tmp[MaxN][MaxN];
int ans;
int ans2;

void Find(int _m)
{
//  printf("[%d] ", _m); 
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

bool GenData(int _n, int _m, int _w)
{
  n = _n;
  m = _m/2 + rand()%(_m/2);
  kk = rand()%n;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 2; j++)
      a[i][j] = 1 + (rand())%(_w/10);

    for(int j = 2; j < 5; j++)
      a[i][j] = _w/2 + (rand())%(_w/2);
  }

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

    tmp[i + n][(i+n-1)%n] = a[i][0];
    tmp[i + n][(i+n+1)%n] = a[i][1];
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

/*/
  for(int i = 0; i < 2*n; i++)
  {
    for(int j = 0; j < 2*n; j++)
      printf("%I64d ", tmp[i][j]);
    printf("\n");
  }

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      fprintf(fout, "%I64d ", d1[i][j]);
    fprintf(fout, "\n");
  }
//*/

/*/
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      d[i][j] = d1[i][j];

  for(int ll = 1; ll < m-1; ll++)
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
  ans2 = d[0][kk]%1000000003;
//*/
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
  ans = d[0][kk]%1000000003;

  return true;
}

void WriteData()
{
  fprintf(fin, "%d %d %d\n", m, n, kk);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 5; j++)
      fprintf(fin, "%d ", a[i][j]);
    fprintf(fin, "\n");
  }
  
  fprintf(fout, "%d\n", ans);
//  fprintf(fout, "%d %d\n", ans, ans2);
}

int main()
{
  fin = fopen("Karin_in.txt", "wt");
  fout = fopen("Karin_out.txt", "wt");
  srand(0); rand(); rand();
  
  int TestCnt = 50;
//  int TestCnt = 10;
  int testId = 0;
  
  double tmp = 40;
  while(testId < TestCnt)
  {
    tmp = tmp*1.4;
    if( GenData(3+testId/2, (int)tmp, 990) )
//    if( GenData(3+testId/2, 4+testId, 990) )
    {
      testId++;

      stringstream filename;
      filename << testId << ".in";

      fin = fopen(filename.str().c_str(),"w");
      WriteData();
      fclose(fin);
      cout << "Generated " << filename.str() << endl;
    }
  }
  
  fprintf(fin, "0 0 0\n");
  
  //system("pause");
  
  return 0;
}
