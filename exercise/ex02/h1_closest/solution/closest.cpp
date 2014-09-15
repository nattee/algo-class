#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>


using namespace std;

int distance(pair<int,int> a,pair<int,int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}

int closest(vector<pair<int,int> > &points_x,vector<int> &points_idx_y,int l,int r) {
  // points_idx_y contains exactly r-l+1 integer
  // points_idx_y[i] is the index of points_x such that its y coordinate is sorted ascendingly
  // i.e., points_x[ points_idx_y[i] ].second <= points_x[ points_idx_y[i+1] ].second
  if (l >= r) return INT_MAX;
  if (l+1 == r) return distance(points_x[l], points_x[r]);
  //printf("l = %d, r = %d\n",l,r);
  int m = (l+r)/2;
  int mid_x = points_x[m].first;

  vector<int> p_left_y,p_right_y;

  //divide into two subproblem by x-coordinate
  //we need to generate a new list of point sorted by y
  for (int i = 0;i < (r-l+1);i++) {
    if (points_idx_y[i] <= m) {
      p_left_y.push_back(points_idx_y[i]);
    } else {
      p_right_y.push_back(points_idx_y[i]);
    }
  }

  // recursive
  int ans_left = closest(points_x,p_left_y,l,m);
  int ans_right = closest(points_x,p_right_y,m+1,r);
  int min_ans = min(ans_left,ans_right);
  //printf("ans_left = %d\nans_right = %d\n",ans_left,ans_right);

  // solve the middle
  // first, find all points in the middle band, sorted by y
  vector<pair<int,int> > p_middle_y;
  for (auto &idx : points_idx_y) {
    if (points_x[idx].first >= mid_x - min_ans || points_x[idx].first <= mid_x + min_ans) {
      p_middle_y.push_back(points_x[idx]);
    }
  }

  // then, iterate every pair whose y different does not exceeding min_ans
  int ans_middle = min_ans;
  for (size_t i = 0;i < p_middle_y.size();i++) {
    size_t j = i+1;
    while (j < p_middle_y.size() && p_middle_y[j].second - p_middle_y[i].second <= min_ans) {
      //this loops takes at most 8 iterations
      int dis = distance(p_middle_y[i],p_middle_y[j]);
      if (dis < ans_middle) ans_middle = dis;
      j++;
    }
  }

  if (ans_middle < min_ans) return ans_middle; else return min_ans;
}

bool comparator_x(const pair<int,int> &a,const pair<int,int> &b) {
  if (a.first < b.first) return true;
  if (a.first == b.first)
    return (a.second < b.second);
  return false;
}


// too lazy, i am making this global
vector<pair<int,int> > points_x;

bool comparator_y(const int &a,const int &b) {
  if (points_x[a].second < points_x[b].second) return true;
  if (points_x[a].second == points_x[b].second)
    return (points_x[a].first < points_x[b].first);
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> y_idx;
  points_x.reserve(n);
  y_idx.reserve(n);
  for (int i = 0;i < n;i++) {
    int a,b;
    cin >> a >> b;
    points_x.push_back(make_pair(a,b));
    y_idx.push_back(i);
  }

  sort(points_x.begin(),points_x.end(),comparator_x);
  sort(y_idx.begin(),y_idx.end(),comparator_y);

  cout << closest(points_x,y_idx,0,n-1) << endl;
}
