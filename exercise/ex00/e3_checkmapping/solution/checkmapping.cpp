#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0;i < n;i++) {
    int a;
    cin >> a;
    if (a < 1 || a > n || v[a-1] > 0) {
      cout << "NO" << endl;
      return 0;
    }
    v[a-1]++;
  }
  cout << "YES" << endl;
}
