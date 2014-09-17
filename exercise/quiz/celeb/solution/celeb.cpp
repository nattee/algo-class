#include <iostream>
#include <stdio.h>

using namespace std;

int celeb_dq(int k[1000][1000],int p,int q) {
  if (p == q) return p;
  if (k[p][q] == 1) {
    int s = celeb_dq(k,p+1,q);
    if (s >= 0 && k[p][s] == 1 && k[s][p] == 0)
      return s;
    return -1;
  } else {
    int s = celeb_dq(k,p,q-1);
    if (s >= 0 && k[q][s] == 1 && k[s][q] == 0)
      return s;
    return -1;
  }
}

int main() {
  int n;
  int k[1000][1000];
  cin >> n;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < n;j++) {
      int a;
      cin >> a;
      k[i][j] = a;
      if (i == j && a == 1) {
        fprintf(stderr,"ERROR\n");
      }
    }
  }
  cout << celeb_dq(k,0,n-1)+1 << endl;
}
