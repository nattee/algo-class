#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> e; //adjacency list


bool search(int idx,vector<int> &color,int max_color) {
  if (idx == N) {
    return true;
  } else {
    for (int i = 0;i < max_color;i++) {
      //check if the vertex idx can be of color i
      bool possible = true;
      for (auto &to : e[idx]) {
        if (color[to] == i) {
          possible = false;
          break;
        }
      }
      //if possible, go ahead
      if (possible) {
        color[idx] = i;
        if (search(idx+1,color,max_color))
          return true;
      }
    }
    return false;
  }
}

int main() {
  int E;
  cin >> N >> E;
  e.resize(N);

  while (E--) {
    int a,b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  for (int i = 1;i <= N;i++) {
    vector<int> color(N,-1);
    if (search(0,color,i)) {
      cout << i << endl;
      break;
    }
  }
}
