#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define MAX_RC 100
#define VERY_LARGE MAX_RC * MAX_RC + 1


using namespace std;

int main() {
  int R,C;
  cin >> R >> C;
  char maze[MAX_RC+2][MAX_RC+2];
  int dist[MAX_RC+2][MAX_RC+2];
  //read input
  for (int i = 0;i < R;i++) {
    string st;
    cin >> st;
    for (int j = 0;j < C;j++) {
      maze[i+1][j+1] = st[j];
    }
  }
  //set up sentinel, so we will never walk outside the boundary
  for (int i = 0;i < R;i++) { maze[i][0] = maze[i][C+1] = '#'; }
  for (int i = 0;i < C;i++) { maze[0][i] = maze[R+1][i] = '#'; }
  //set up distance matrix
  for (int i = 1;i <= R;i++)
    for (int j = 1;j <= C;j++)
      dist[i][j] = VERY_LARGE;

  //bfs
  queue<pair<int,int> > q;
  q.push(make_pair(1,1));
  dist[1][1] = 0;
  int dr[4] = { 0, -1, 0, 1};
  int dc[4] = {-1,  0, 1, 0};
  while (q.empty() == false) {
    pair<int,int> p = q.front();
    q.pop();
    if (p.first == R && p.second == C) {
      //we have reach the exit
      break;
    }
    for (int i = 0;i < 4;i++) {
      int new_r = p.first  + dr[i];
      int new_c = p.second + dc[i];
      if (maze[new_r][new_c] == '.' && dist[new_r][new_c] == VERY_LARGE) {
        dist[new_r][new_c] = dist[p.first][p.second] + 1;
        q.push(make_pair(new_r,new_c));
      }
    }
  }
  if (dist[R][C] == VERY_LARGE) {
    cout << "-1" << endl;
  } else {
    cout << dist[R][C] << endl;
  }
}
