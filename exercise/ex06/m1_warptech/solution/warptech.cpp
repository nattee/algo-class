#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> parent,srank;
int component;
multimap<int,pair<int,int> > edge;
vector<int> range;      // range[x] = min edge cost to have x components


void init(int n) {
  for (int i = 0;i < n;i++) {
    parent[i] = i;
    srank[i] = 0;
  }
  component = n;
}

void create(int n) {
  parent.resize(n);
  srank.resize(n);
  init(n);

  range.resize(n+1);
}

int findSet(int s) {
  if (parent[s] != s) {
    parent[s] = findSet(parent[s]);
  }
  return parent[s];
}

void unionSet(int a,int b) {
  int ra = findSet(a);
  int rb = findSet(b);
  if (ra == rb) return;
  component--;
  if (srank[ra] < srank[rb])
    parent[ra] = rb;
  else if (srank[ra] > srank[rb])
    parent[rb] = ra;
  else {
    parent[rb] = ra;
    srank[a] = srank[a] + 1;
  }
}

int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  create(N);
  edge.clear();
  //read input
  for (int i = 0;i < M;i++) {
    pair<int,int> e;
    int c;
    cin >> e.first >> e.second >>  c;
    edge.insert(make_pair(c,e));
  }
  //process
  int last_comp = component;
  range[component] = 0;
  for (multimap<int,pair<int,int> >::iterator x = edge.begin(); x != edge.end();x++) {
    int a,b,c;
    a = x->second.first;
    b = x->second.second;
    c = x->first;
    //printf("process edge (%d,%d) %d\n",a,b,c);
    unionSet(a,b);
    //printf("component is now %d\n",component);
    if (component < last_comp) {
      for (int i = last_comp - 1; i >= component;i--)
        range[i] = c;
      last_comp = component;
    }
  }
  //answer
  for (int i = 0;i < Q;i++) {
    int D;
    cin >> D;
    cout << range[D] << endl;
  }
}
