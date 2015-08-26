#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
  vector<map<int,int>> bid; // bid[i][k] = the price that user k bid for items i
  vector<int> items;        // number of each item
  priority_queue<pair<int,int>> highest; // pq for finding k highest bidder
  vector<vector<int>> get; // get[i] = vector of users that won the i-th items

  int N,M,A;
  cin >> N >> M >> A;
  for (int i = 0;i < N;i++) {
    int a;
    cin >> a;
    items.push_back(a);
  }

  //process auction
  bid.resize(N);
  for (int i = 0;i < A;i++) {
    char mode;
    cin >> mode;
    if (mode == 'B') {
      int U,I,V;
      cin >> U >> I >> V;
      U--;I--;
      bid[I][U] = V;
    } else {
      int U,I;
      cin >> U >> I;
      U--;I--;
      bid[I].erase(U);
    }
  }

  //handling out the items
  get.resize(M);
  for (int i = 0;i < N;i++) {
    highest = priority_queue<pair<int,int>>();
    for (auto &x : bid[i]) {
      highest.push(make_pair(x.second,x.first));
    }
    while (items[i] > 0 && highest.empty() == false) {
      auto x = highest.top();
      highest.pop();
      get[x.second].push_back(i);
      items[i]--;
    }
  }
  for (int i = 0;i < M;i++) {
    if (get[i].empty()) {
      cout << "NONE" << endl;
    } else {
      for (auto &x : get[i]) {
        cout << x+1 << " ";
      }
      cout << endl;
    }
  }
}
