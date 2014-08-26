#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> v1,v2,v3,v4;

int rand(int a,int b) {
  int d = b - a;
  return a + rand() / (RAND_MAX + 1.0) * d;
}

void gen_data(int n) {
  v1.resize(n);v2.resize(n);v3.resize(n);v4.resize(n);
  for (int i = 0;i < n;i++) {
    v1[i] = rand(0,n*10);
    v2[i] = rand(0,n*10);
    v3[i] = rand(0,n*10);
    v4[i] = rand(0,n*10);
  }
}


int main() {
  int n = 10;
  int x = n*100;  // we won't be able to find it
  gen_data(n);
  unordered_set<int> sum12(1000000),sum34(1000000);
  for (auto &a : v1) 
    for (auto &b : v2) 
      sum12.insert(a + b);

  for (auto &a : v3) 
    for (auto &b : v4) 
      sum34.insert(a + b);

  bool found = false;
  for (auto &a : sum12) {
    int req =  x - a;
    auto it = sum34.find(req);
    if (it != sum34.end()) {
      found = true;
      break;
    }
  }

  //what is the time complexity of this algorithm?

  if (found) 
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
