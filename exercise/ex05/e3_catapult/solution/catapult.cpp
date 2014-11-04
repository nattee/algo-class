#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int n;
vector<vector<bool>> edge;
stack<int> s;
vector<bool> visited;
vector<int> component; // component id
int n2; // number of component


void dfs1(int idx) {
  visited[idx] = true;
  for (int i = 0;i < n;i++) {
    if (edge[i][idx] && !visited[i]) 
      dfs1(i);
  }
  s.push(idx);
}

void dfs2(int idx) {
  visited[idx] = true;
  component[idx] = n2;
  for (int i = 0;i < n;i++) {
    if (edge[idx][i]) {
      if (!visited[i])
        dfs2(i);
    }
  }
}


int main() {
  cin >> n;
  edge.resize(n);
  visited.resize(n);
  component.resize(n);
  for (int i = 0;i < n;i++) { edge[i].resize(n); }
  for (int i = 0;i < n;i++) {
    int m,x;
    cin >> m;
    while (m--) {
      cin >> x;
      edge[i][x] = true;
    }
  }

  // SCC
  for (int i = 0;i < n;i++) {
    if (!visited[i]) {
      dfs1(i);
    }
  }

  n2 = 0;
  for (int i = 0;i < n;i++) visited[i] = false;
  while (s.empty() == false) {
    int v = s.top(); s.pop();
    if (visited[v] == false) {
      dfs2(v);
      n2++;
    }
  }

  //aggregrate component count
  vector<int> comp_count;
  comp_count.clear(); comp_count.resize(n2);
  for (int i = 0;i < n;i++) {
    comp_count[component[i]]++;
  }

  sort(comp_count.begin(),comp_count.end());

  //gen result
  for (int i = 0;i < n2;i++)
    cout << comp_count[i] << " ";
  cout << endl;
}
