#include <iostream>

using namespace std;

int table[102][102];

int barcode_topdown(int n,int k,int m) {
  if (n <= 0) return 0;
  if (k == 1) {
    if (n <= m) return 1;
    if (n > m) return 0;
  }
  if (table[n][k] > -1) return table[n][k];
  int sum = 0;
  for (int i = 1;i <= m;i++) {
    sum+=barcode_topdown(n-i,k-1,m);
  }
  table[n][k] = sum;
  return sum;
}


int main() {
  int n,m,k;
  cin >> n >> m >> k;
  k++;
  for (int i = 0;i <= n;i++)
    for (int j = 0;j <= k;j++)
      table[i][j] = -1;
  cout << barcode_topdown(n,k,m) << endl;

}
