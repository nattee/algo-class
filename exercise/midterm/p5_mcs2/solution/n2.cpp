#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  vector<int> A(n);
  for (int i = 0;i < n;i++) {
    int a;
    scanf("%d",&a);
    A[i] = a;
  }

  //naive solve using n^3
  int max = A[0];
  for (int i = 0;i < n;i++) {
    int sum = 0;
    int idx = i;
    for (int j = 0;j < n;j++) {
      sum += A[idx++];
      if (idx == n) idx = 0;
      if (sum > max) max = sum;
    }
  }
  cout << max << endl;
}
