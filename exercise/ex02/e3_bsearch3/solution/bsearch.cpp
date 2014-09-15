#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int> &v,int left,int right,int x,int ans) {
  if (left > right) return ans;
  int mid = (left+right)/2;
  if (v[mid] > x) return bs(v,left,mid-1,x,ans);
  if (mid > ans) ans = mid;
  return bs(v,mid+1,right,x,ans);
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> v;
  v.reserve(n+1);
  for (int i = 0;i < n;i++) {
    int a;
    cin >> a;
    v[i] = a;
  }

  for (int i = 0;i < m;i++) {
    int x;
    cin >> x;
    cout << bs(v,0,n-1,x,-1) << endl;
  }
}
