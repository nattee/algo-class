#include <iostream>
#define MAX 30

using namespace std;

int c[MAX][MAX];

int bino(int n,int k) {
  if (n == k) return 1;
  if (k == 0) return 1;
  if (c[n][k] > 0) return c[n][k];
  c[n][k] = bino(n-1,k-1) + bino(n-1,k);
  return c[n][k];
}

int main() {
  for (int i = 0;i < MAX;i++)
    for (int j = 0;j < MAX;j++)
      c[i][j] = 0;


  int n,k;
  cin >> n >> k;
  cout << bino(n,k) << endl;
}
