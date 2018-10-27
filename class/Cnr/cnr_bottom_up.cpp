#include <iostream>
#include <vector>

using namespace std;

  vector<vector<int>> storage(100,vector<int>(100,-1));
void print() {
  printf("---------------------\n");
  for (int i = 0;i <= 6;i++) {
    for (int j = 0;j <= 6;j++) {
      if (storage[i][j] != -1)
        printf("%3d",storage[i][j]);
      else
        printf("   ");
    }
    printf("\n");
  }
}

int cnr(int n,int r) {

  for (int i = 0;i <= n;i++) storage[i][0] = 1;
  for (int i = 0;i <= n;i++) storage[i][i] = 1;
  print();

  for (int i = 2;i <= n;i++) {
    for (int j = 1; j < std::min(i,r+1);j++) {
      storage[i][j] = storage[i-1][j-1] + storage[i-1][j];
    }

  }

  print();

  return 0;

}

int main() {
  int n = 6;
  int r = 3;

  cout << cnr(n,r);
}

