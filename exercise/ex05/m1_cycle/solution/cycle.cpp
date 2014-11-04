#include <iostream>
#include <vector>

using namespace std;

int N,E;
vector<vector<int> > edge;
vector<bool> visited;
bool cycle;

void dfs(int idx,int from) {
  visited[idx] = true;
  for (int i = 0;i < N;i++) {
    if (edge[idx][i] && from != i) {
      if (visited[i]) {
        cycle = true;
        return;
      } else {
        dfs(i,idx);
      }
    }
    if (cycle) break;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> N >> E;
    edge.clear();edge.resize(N);
    visited.clear();visited.resize(N);
    for (int i = 0;i < N;i++) { edge[i].clear(); edge[i].resize(N);}
    for (int i = 0;i < E;i++) {
      int a,b;
      cin >> a >> b;
      edge[a][b] = true; edge[b][a] = true;
    }

    cycle = false;
    for (int i = 0;i < N;i++) {
      if (!visited[i]) {
        dfs(i,-1);
      }
      if (cycle) break;
    }
    cout << (cycle ? "YES" : "NO") << endl;
  }
}
