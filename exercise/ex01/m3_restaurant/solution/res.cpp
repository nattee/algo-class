#include <iostream>
#include <vector>

#define MAX_R 1000000000001ll //10^12+1

using namespace std;

long long served(vector<int> &T,long long v) {
  long long sum = 0;
  for (auto &x : T) {
    sum += v/x;
  }
  return sum;
}

long long check(vector<int> &T,long long v) {
  long long l = 0;
  long long r = MAX_R;
  while (l < r) {
    long long mid = (l+r) / 2;
    long long s = served(T,mid);
    //printf("l = %lld, r = %lld, at time %lld served = %lld\n",l,r,mid,s);
    if (s < v) l = mid+1;
    if (s >= v) r = mid;
  }
  return r;
}

int main() {
  int N,A;
  cin >> N >> A;
  vector<int> T(N);
  for (int i = 0;i < N;i++) cin >> T[i];
  while (A--) {
    long long v;
    cin >> v;
    if (v <= N) {
      cout << 0 << "\n";
    } else {
      cout << check(T,v-N) << "\n";
    }
  }
}
