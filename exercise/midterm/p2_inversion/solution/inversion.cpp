#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &a,int l,int m,int r,vector<int> &tmp) {
  int i = l;
  int j = m+1;
  int sum = 0;
  for (int k = l;k <= r;k++) {
    if (i>m) {tmp[k] = a[j++]; continue;}
    if (j>r) {tmp[k] = a[i++]; continue;}
    if (a[i] > a[j]) {
      sum += m-i+1;
    }
    tmp[k] = (a[i] > a[j]) ? a[j++] : a[i++];
  }
  for (int k = l;k <= r;k++) a[k] = tmp[k];

  return sum;
}

int inversion(vector<int> &a,int l,int r,vector<int> &tmp) {
  if (l >= r) return 0;
  int mid = (l+r)/2;
  int num_l = inversion(a,l,mid,tmp);
  int num_r = inversion(a,mid+1,r,tmp);
  return merge(a,l,mid,r,tmp) + num_l + num_r;
}


int main() {
  int n;
  cin >> n;
  vector<int> a;
  vector<int> tmp;
  a.resize(n);
  tmp.resize(n);
  for (int i = 0;i < n;i++) {
    cin >> a[i];
  }
  cout << inversion(a,0,n-1,tmp) << endl;
}
