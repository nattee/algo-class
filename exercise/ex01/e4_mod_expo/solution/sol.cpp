#include <iostream>
#include <vector>

using namespace std;

int expo(int x,int n,int k) {
  if (n == 1) return x % k;

  int tmp = expo(x,n/2,k) % k;
  tmp = tmp * tmp;
  tmp = tmp % k;
  if (n % 2 == 1) {
    tmp = tmp * (x % k);
    tmp = tmp % k;
  }
  return tmp;
}

int main() {
  int n,k,x;
  cin >> x >> n >> k;
  cout << expo(x,n,k) << endl;
}

