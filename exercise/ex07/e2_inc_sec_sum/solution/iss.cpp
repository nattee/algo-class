#include <iostream>
#include <string>

using namespace std;

int count;

void search(int n,int last) {
  if (n == 0) {
    count++;
  } else {
    for (int i = last;i <= n;i++) {
      search(n-i,i);
    }
  }
}

int main() {
  int n;
  cin >> n;
  count = 0;
  search(n,1);
  cout << count << endl;
}
