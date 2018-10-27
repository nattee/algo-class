#include <iostream>
#include <vector>

using namespace std;

long long int cnr(long long int n) {
  if (n <= 1) return 1;
  int a = fibo(n-1);
  int b = fibo(n-2);
  return a+b;
}

int main() {
  long long int n =50;
  cout << fibo(n);
}

