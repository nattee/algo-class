#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int,int> &a,const pair<int,int> &b) {
  return a.second < b.second;
}

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "0" << endl;
    return 0;
  }
  vector<pair<int,int>> intv;
  intv.resize(n);
  for (int i = 0;i < n;i++)
    cin >> intv[i].first;
  for (int i = 0;i < n;i++)
    cin >> intv[i].second;

  sort(intv.begin(),intv.end(),comp);
  int count = 1;
  int last = 0;
  for (int i = 1;i < n;i++) {
    if (intv[i].first >= intv[last].second) {
      last = i;
      count++;
    }
  }
  cout << count << endl;
}
