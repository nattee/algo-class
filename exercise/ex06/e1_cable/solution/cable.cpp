#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> cost(N, vector<int>(N,0) );
  for (int i = 0;i < N;i++) {
    for (int j = i+1;j < N;j++) {
      int a;
      cin >> a;
      cost[i][j] = cost[j][i] = a;
    }
  }

  // Prim's with V^2
  vector<int> D(N,INT_MAX);
  vector<bool> marked(N,false);
  D[0] = 0;
  int sum = 0;
  for (int i = 0;i < N;i++) {
    //find min node
    int min = INT_MAX;
    int idx;
    for (int i = 0;i < N;i++)
      if (!marked[i] && D[i] < min)  {
        min = D[i];
        idx = i;
      }

    marked[idx] = true;
    sum += D[idx];
    //update
    for (int j = 0;j < N;j++) {
      if (!marked[j] && D[j] > cost[idx][j]) D[j] = cost[idx][j];
    }
  }
  cout << sum << endl;
}
