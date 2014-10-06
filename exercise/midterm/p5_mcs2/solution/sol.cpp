#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int solve(int *A,int n,int l,int r,int *sl, int *sr) {
  if (l == r) return A[l];
  int m = (l+r) / 2;
  int al = solve(A,n,l,m,sl,sr);
  int ar = solve(A,n,m+1,r,sl,sr);

  //find best inner
  int max_middle;
  int maxl,maxr;
  int sum;
  sum = maxl = A[m];
  for (int i = m-1;i >= l;i--) {
    sum += A[i];
    if (sum > maxl) maxl = sum;
  }
  sum = maxr = A[m+1];
  for (int i = m+2;i <= r;i++) {
    sum += A[i];
    if (sum > maxr) maxr = sum;
  }
  max_middle = maxl + maxr;

  //find best outer
  maxl = sl[l];
  for (int i = l+1;i<= m;i++)
    if (sl[i] > maxl) maxl = sl[i];
  maxr = sr[m+1];
  for (int i = m+2;i<= r;i++)
    if (sr[i] > maxr) maxr = sr[i];
  if (maxl + maxr > max_middle) max_middle = maxl + maxr;

  if (ar > max_middle) max_middle = ar;
  if (al > max_middle) max_middle = al;
  return max_middle;
}

int main() {
  int n;
  scanf("%d",&n);
  int A[n];
  int sl[n], sr[n];

  int max = 0;
  for (int i = 0;i < n;i++) {
    int a;
    scanf("%d",&a);
    A[i] = a;
    max += a;
  }

  sl[0] = A[0];
  sr[n-1] = A[n-1];
  for (int i = 1;i< n;i++) {
    sl[i] = sl[i-1] + A[i];
    sr[n-1-i] = sr[n-i]+A[n-1-i];
  }

  int r = solve(A,n,0,n-1,sl,sr);
  if (r > max) max = r;
  cout << max << endl;
}
