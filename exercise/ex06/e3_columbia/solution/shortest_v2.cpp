#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;



int main() {
  int R,C;
  cin >> R >> C;
  vector<vector<int>> fee(R, vector<int>(C,0) );
  vector<vector<int>> D(R, vector<int>(C,R*C*1000+10) );
  vector<vector<bool>> marked(R, vector<bool>(C,false) );
  for (int i = 0;i < R;i++) {
    for (int j = 0;j < C;j++) {
      int a;
      cin >> a;
      fee[i][j] = a;
    }
  }

  // Dijkstra with v^2
  D[0][0] = 0;
  int dr[4] = {1,0,-1,0};
  int dc[4] = {0,-1,0,1};
  for (int i = 0;i < R * C;i++) {
    //find min node
    int min = INT_MAX;
    int r1,c1;
    for (int r = 0;r < R;r++)
      for (int c = 0;c < C;c++)
      if (!marked[r][c] && D[r][c] < min)  {
        min = D[r][c];
        r1 = r;c1 = c;
      }

    //update
    marked[r1][c1] = true;
    for (int i = 0;i < 4;i++) {
      int nr = r1 + dr[i];
      int nc = c1 + dc[i];
      if (nc >= 0 && nc < C && nr >= 0 && nr < R) {
        if (D[nr][nc] > D[r1][c1] + fee[nr][nc]) {
          D[nr][nc] = D[r1][c1] + fee[nr][nc];
        }
      }
    }
  }
  //output
  for (int i = 0;i < R;i++) {
    for (int j = 0;j < C;j++) {
      cout << D[i][j] << " ";
    }
    cout << endl;
  }
}
