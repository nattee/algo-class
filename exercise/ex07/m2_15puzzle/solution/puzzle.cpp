#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

typedef struct BT {
  int b[4][4];   //b[i][j] is the tile, a value of 0 means zero
  int step;       //the number of move we have performed
  int bound;      // the bound
  int x,y;        //position of the empty tile

  bool operator==(const struct BT& other) const {
    for (int i = 0;i < 4;i++) {
      for (int j = 0;j < 4;j++) {
        if (other.b[i][j] != b[i][j]) return false;
      }
    }
    return true;
  }

  void print() {
    printf("======board bound = %d =========\n",bound);
    for (int i = 0;i < 4;i++) {
      for (int j = 0;j < 4;j++) {
        printf("%3d",b[i][j]);
      }
      printf("\n");
    }

  }

} Board;

//calculate heuristic from the distance of the tile and its target position
int heuristic(const Board& a) { 
  int sum = 0;
  for (int i = 0;i < 4;i++) {
    for (int j = 0;j < 4;j++) {
      if (a.b[i][j] == 0) continue;
      int tx = (a.b[i][j]-1) % 4;
      int ty = (a.b[i][j]-1) / 4;
      sum += abs(ty - i) + abs(tx - j);
    }
  }
  return sum;
}

class CompareClass {
  public:
  bool operator() (const Board& a,const Board & b) {
    return (a.bound > b.bound);
  }
};

//hash function for board
namespace std {

  template <>
  struct hash<Board>
  {
    std::size_t operator()(const Board& b) const
    {
      using std::size_t;
      using std::hash;
      using std::string;

      size_t x;
      long long int sum;
      long long int digit = 1;

      for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
          sum += b.b[i][j] * digit;
          digit = digit * 15;
        }
      }

      x = sum;
      return x;

    }
  };

}

int main() {
  Board a;
  for (int i = 0;i < 4;i++)
    for (int j = 0;j < 4;j++) {
      cin >> a.b[i][j];
      if (a.b[i][j] == 0) {
        a.x = j;
        a.y = i;
      }
    }
  a.step = 0;
  a.bound = heuristic(a);

  priority_queue<Board,vector<Board>,CompareClass> q;
  unordered_set<Board> set;
  q.push(a);
  set.insert(a);
  vector<int> dx = {1,0,-1,0};
  vector<int> dy = {0,1,0,-1};
  while (q.empty() == false) {
    Board b = q.top();
    q.pop();
    //debug
//    printf("----------pop----------------\n");
//    b.print();
    Board n;
    //move up
    for (int i = 0;i < 4;i++) {
      n = b;
      n.x = b.x + dx[i];
      n.y = b.y + dy[i];
      if (n.x >= 0 && n.x < 4 && n.y >= 0 && n.y < 4) {
        n.b[b.y][b.x] = n.b[n.y][n.x];
        n.b[n.y][n.x] = 0;
        n.step++;
        int heu = heuristic(n);
        if (heu == 0) {
          //found!
          cout << n.step << endl;
          exit(0);
        }
        if (set.find(n) == set.end()) {

          n.bound = n.step + heu;
          q.push(n);
          set.insert(n);
          //debug
//          printf("----------  add ----------------\n");
//          n.print();
//          int x;
//          cin >> x;
        }
      }
    }
  }

  cout << "ERORR: CANNOT SOLVE" << endl;
}


