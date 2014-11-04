#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int N,E,K;
  cin >> N >> E >> K;
  vector<vector<bool> > edge;
  vector<bool> visited;
  vector<int> d;
  edge.resize(N);
  for (int i = 0;i < N;i++) { edge[i].clear();edge[i].resize(N); }
  for (int i = 0;i < E;i++) {
    int a,b;
    cin >> a >> b;
    edge[a][b] = edge[b][a] = true;
  }

  int max = 0;
  queue<int> q;
  d.resize(N);
  visited.resize(N);
  for (int i = 0;i < N;i++) {
    for (int i = 0;i < N;i++) {
      visited[i] = false;
      d[i] = N;
    }
    int count = 1;
    q.push(i); d[i] = 0; visited[i] = true;
    //printf("at %d\n",i);
    while(!q.empty()) {
      int idx = q.front(); q.pop();
      if (d[idx] == K) continue;
      for (int i = 0;i < N;i++) {
        if (edge[idx][i] && !visited[i]) {
          visited[i] = true; count++;
          d[i] = d[idx] + 1;
          q.push(i);
          //printf("include %d from %d with length = %d\n",i,idx,d[i]);
        }
      }
    }
    //printf("at %d, conut = %d\n",i,count);
    if (count > max) max = count;
  }
  cout << max << endl;
}
