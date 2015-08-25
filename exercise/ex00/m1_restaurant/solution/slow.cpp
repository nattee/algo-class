#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
  int N,M;
  vector<int> T,avail;
  cin >> N >> M;
  for (int i = 0;i < N;i++) {
    int a;
    cin >> a;
    T.push_back(a);
  }

  avail.resize(N);
  while (M--) {
    //find earliest server
    int min_idx = 0;
    for (int i = 1;i < N;i++) {
      if (avail[i] < avail[min_idx]) min_idx = i;
    }
    cout << avail[min_idx] << endl;
    avail[min_idx] += T[min_idx];
  }
}
