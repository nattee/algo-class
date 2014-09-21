#include <iostream>
#include <string>

using namespace std;

int main() {
  int r,c;
  int grid[1001][1001];
  int sum[1001][1001];
  string st;
  cin >> r >> c;
  for (int i = 0;i < r;i++) {
    cin >> st;
    for (int j = 0;j < c;j++) {
      grid[i+1][j+1] = st[j] == '1' ? 1 : 0;
    }
  }

  sum[0][0] = 0;
  for (int i = 1;i <= r;i++) sum[i][0] = sum[i-1][0] + grid[i][0];
  for (int j = 1;j <= c;j++) sum[0][j] = sum[0][j-1] + grid[0][j];
  for (int i = 1;i <= r;i++) {
    for (int j = 1;j <= c;j++) {
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
    }
  }

  int max = 0;
  for (int i = 1;i <= r;i++) {
    for (int j = 1;j <= c;j++) {
      int k = 1;
      while (i+k-1 <= r && j+k-1 <= c) {
        if (k > max && sum[i+k-1][j+k-1] - sum[i-1][j+k-1] - sum[i+k-1][j-1] + sum[i-1][j-1] == k*k) {
          max = k;
        }
        k++;
      }
    }
  }
  cout << max << endl;
}
