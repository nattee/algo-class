#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> storage(100,vector<int>(100,-1));

void print() {
  for (int i = 0;i <= 6;i++) {
    for (int j = 0;j <= 6;j++) {
      printf("%3d",storage[i][j]);
    }
    printf("\n");
  }
}

int cnr(int n,int r) {
  printf("calling n=%d, r=%d\n",n,r);
  print();
  if (n == r) return 1;
  if (r == 0) return 1;

  if (storage[n][r] != -1) return storage[n][r];
  int a = cnr(n-1,r-1);
  int b = cnr(n-1,r);

  int result = a+b;
  printf("calling n=%d, r=%d, returning %3d\n",n,r,result);
  print();
  storage[n][r] = result;
  return result;
}

int main() {
  int n = 6;
  int r = 3;

  cout << cnr(n,r);
  print();
}

