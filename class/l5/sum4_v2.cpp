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
  
  set<int> s4(v4.begin(),v4.end());

  bool found = false;
  for (auto &a : v1) {
    for (auto &b : v2) {
      for (auto &c : v3) {
        int req = x - a - b - c;
        if (s4.find(req) != s4.end()) {  // Question 2; What is the time complexity of this line
          found = true;
          break;
        }
      }
      if (found) break;
    } 
    if (found) break;
  }
  
  // Question 3: What is the time complexity of the entire algorithm?

  if (found) 
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
