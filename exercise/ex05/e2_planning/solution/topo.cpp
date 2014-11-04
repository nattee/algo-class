#include <vector>
#include <iostream>
#include <stack>

using namespace std;

stack<int> topo;
vector<vector<bool> > edge;
int N;

vector<bool> visited;

void dfs(int i) {
  visited[i] = true;
  for (int j = 0;j < N;j++) {
    if (!visited[j] && edge[i][j])
      dfs(j);
  }
  topo.push(i);
}


int main() {
  cin >> N;
  edge.clear(); edge.resize(N);
  for (int i = 0;i < N;i++) edge[i].resize(N);

  for (int i = 0;i < N;i++) {
    int M;
    cin >> M;
    while(M--) {
      int x;
      cin >> x;
      edge[x][i] = true;
    }
  }

  //TOPO sort
  visited.clear(); visited.resize(N);
  for (int i = 0;i < N;i++) {
    if (!visited[i])
      dfs(i);
  }

  while (!topo.empty()) {
    int x = topo.top();
    topo.pop();
    cout << x << " ";
  }
  cout << endl;
}
