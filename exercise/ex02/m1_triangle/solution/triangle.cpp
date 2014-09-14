#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<vector<int>> a;
  vector<vector<int>> best;
  a.resize(n);
  //read input
  for (int i = 0;i < n;i++) {
    a[i].resize(i+1);
    for (int j = 0;j <= i;j++) {
      int k;
      cin >> k;
      a[i][j] = k;
    }
  }

  //calculate
  best.resize(n);
  //init the last row
  best[n-1].resize(n);
  for (int i = 0;i < n;i++) { best[n-1][i] = a[n-1][i]; }
  //process the remaining
  for (int i = n-2;i >= 0;i--) {
    best[i].resize(i+1);
    for (int j = 0;j < i+1;j++) {
      best[i][j] = max(best[i+1][j],best[i+1][j+1]) + a[i][j];
    }
  }
  cout << best[0][0] << endl;
}
