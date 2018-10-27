#include <iostream>
#include <vector>

using namespace std;

long long int fibo(long long int n) {
  if (n <= 2) return 1;
  int a = fibo(n-1);
  int b = fibo(n-2);
  return a+b;
}

int main() {
  long long int n =50;
  cout << fibo(n);
}

