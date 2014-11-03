#include <vector>
#include <iostream>
#include <stack>

using namespace std;
int n;
vector<vector<bool>> edge;
stack<int> s;
vector<bool> visited;
vector<int> component; // component id
vector<vector<int>> comp_list; // list of node in each component

//new graph
int n2;    //num node
vector<vector<bool>> e2;


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
      else {
        if (component[i] != n2) {
          //add edge
          e2[n2][component[i]] = true;
        }
      }
    }
  }
}

void dfs3(int idx) {
  visited[idx] = true;
  for (int i = 0;i < n2;i++) {
    if (e2[idx][i] && visited[i] == false) {
      dfs3(i);
    }
  }
  s.push(idx);
}

int main() {
  //freopen("data/2.in","r",stdin);
  int p;
  cin >> n >> p;
  edge.resize(n);
  visited.resize(n);
  component.resize(n);
  comp_list.resize(n);
  e2.resize(n);
  //printf("%d %d\n",p,n);
  for (int i = 0;i < n;i++) {
    edge[i].resize(n);
    e2[i].resize(n);
  }
  for (int i = 0;i < p;i++) {
    int a,b;
    cin >> a >> b;
    edge[a][b] = true;
  }

  // SCC
  for (int i = 0;i < n;i++) {
    if (!visited[i]) {
      dfs1(i);
    }
  }

  //create new graph
  n2 = 0;
  for (int i = 0;i < n;i++) visited[i] = false;
  while (s.empty() == false) {
    int v = s.top(); s.pop();
    if (visited[v] == false) {
      dfs2(v);
      n2++;
    }
  }

  //aggregrate component
  for (int i = 0;i < n;i++) {
    comp_list[component[i]].push_back(i);
  }

  //debug
  //show component
//  printf("--- node = %d ---\n",n2);
//  for (int i = 0;i < n2;i++) {
//    cout << i << ": ";
//    for (auto &x : comp_list[i]) {
//      cout << x << " ";
//    }
//    cout << endl;
//  }
//  //show edge
//  cout << "--- edge ----" << endl;
//  for (int i = 0;i < n2;i++) {
//    cout << i << ": ";
//    for (int j = 0;j < n2;j++) {
//      if (e2[i][j])
//        cout << j << " ";
//    }
//    cout << endl;
//  }

  //longest path in DAG
  int remain = n2;
  vector<int> indeg(n2);
  vector<int> length(n2);
  for (int i = 0;i < n2;i++) visited[i] = false;
  for (int i = 0;i < n2;i++) {
    for (int j = 0;j < n2;j++) {
      if (e2[i][j]) indeg[j]++;
    }
  }
  while (remain > 0) {
    //find 0
    for (int i = 0;i < n2;i++) {
      if (indeg[i] == 0 && visited[i] == false) {
        //remove node
        visited[i] = true;
        //remove edge
        for (int j = 0;j < n2;j++) {
          if (e2[i][j]) {
            //edge[i][j] = false;
            indeg[j]--;
          }
        }

        //process
        int max = -1;
        for (int j =0;j < n2;j++) {
          if (e2[j][i] && length[j] > max) max = length[j];
        }
        length[i] = max + 1;
        break;
      }
    }
    remain--;
  }

  // -- debug display length
//  for (int i = 0;i < n2;i++) {
//    printf("length[%d]: %d\n",i,length[i]);
//  }


  //gen result
  int k = 0;
  for (int i = 0;i < n2;i++)
    if (length[i] > k) k = length[i];
  vector<int> count(k+1);
  for (int i = 0;i < n2;i++) {
    count[length[i]] += comp_list[i].size();
  }
  for (int i = 0;i <= k;i++) {
    cout << count[i] << " ";
  }
  cout << endl;
}
