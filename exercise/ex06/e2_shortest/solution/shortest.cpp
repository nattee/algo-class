#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
  int N,e,s;
  cin >> N >> e >> s;
  vector<vector<pair<int,int>>> edge(N);
  vector<int> D(N,INT_MAX/2);
  while (e--) {
    int a,b,c;
    cin >> a >> b >> c;
    edge[a].push_back(make_pair(b,c));
  }

  D[s] = 0;
  for (int round = 1;round < N;round++) {
    for (int i = 0;i < N;i++) {
      for (size_t j = 0;j < edge[i].size();j++) {
        int b = edge[i][j].first;
        int c = edge[i][j].second;
        if (D[b] > D[i] + c) {
          D[b] = D[i] + c;
        }
      }
    }
  }

  //check negative cycle
  bool negative = false;
  for (int i = 0;i < N;i++) {
    for (size_t j = 0;j < edge[i].size();j++) {
      int b = edge[i][j].first;
      int c = edge[i][j].second;
      if (D[b] > D[i] + c) {
        negative = true;
        break;
      }
    }
    if (negative) break;
  }

  if (negative) cout << -1 << endl; else {
    for (int i = 0;i < N;i++) {
      cout << D[i] << " ";
    }
    cout << endl;
  }
}
