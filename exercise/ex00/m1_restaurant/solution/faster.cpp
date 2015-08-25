#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int main() {
  int N,M;
  vector<int> T,avail;
  // min priority_queue, pair is (TIME,index)
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq; 
  cin >> N >> M;
  for (int i = 0;i < N;i++) {
    int a;
    cin >> a;
    T.push_back(a);
    pq.push(make_pair(0,i));
  }

  avail.resize(N);
  while (M--) {
    //find earliest server
    auto x = pq.top();
    pq.pop();
    cout << x.first << endl;
    //update the time
    x.first += T[x.second];
    pq.push(x);
  }
}
