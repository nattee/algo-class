#include <iostream>
#include <vector>

using namespace std;

int count,n;
vector<bool> used;


bool isValid(vector<int> &x,int m) {
  for (int i = 0;i < m;i++) {
    if (abs(x[m]-x[i]) == m-i) return false;
  }
  return true;
}

void search(vector<int> &x,int m) {
  if (n == m) {
    count++;
  } else {
    for (int i = 0;i < n;i++) {
      if (used[i]) continue;
      x[m] = i;
      used[i] = true;
      if (isValid(x,m)) search(x,m+1);
      used[i] = false;
    }
  }
}

int main() {
  count = 0;
  cin >> n;
  vector<int> x(n,0);
  used.resize(n);
  search(x,0);
  cout << count << endl;
}
