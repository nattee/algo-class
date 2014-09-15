#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>


using namespace std;

int distance(pair<int,int> a,pair<int,int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}


// too lazy, i am making this global
vector<pair<int,int> > points_x;

int main() {
  int n;
  cin >> n;
  points_x.reserve(n);
  for (int i = 0;i < n;i++) {
    int a,b;
    cin >> a >> b;
    points_x.push_back(make_pair(a,b));
  }

  int min_dist = distance(points_x[0],points_x[1]);
  for (int i = 0;i < n;i++) {
    for (int j = i+1;j < n;j++) {
      int dist = distance(points_x[i],points_x[j]);
      if (dist < min_dist) min_dist = dist;
    }
  }

  cout << min_dist << endl;
}
