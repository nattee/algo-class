#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  float w,v;
} ItemType;

vector<ItemType> items;
vector<vector<ItemType>> sorted; // sorted[i] = items that are sorted from i to n-1
vector<float> sum_remain;
float max_v;
float W;

bool compare1(const ItemType& a,const ItemType& b) {
  return a.w > b.w;
}

bool compare2(const ItemType& a,const ItemType& b) {
  return a.v/a.w > b.v/b.w;
}

float fractional(int m,float w) {
  float sum = 0;
  int idx = m;
  while (w > 0 && idx < (int)items.size()) {
    if (w >= sorted[m][idx].w) {
      sum += sorted[m][idx].v;
      w -= sorted[m][idx].w;
      idx++;
    } else {
      float ratio = w/sorted[m][idx].w;
      sum += ratio * sorted[m][idx].v;
      break;
    }
  }
  return sum;
}

void search(vector<int> &x,int m,float sum_w,float sum_v) {
  //backtracking
  if (sum_w > W) return ;
  if (m == (int)items.size()) {
    if (sum_v > max_v) max_v = sum_v;
  } else {
    //bound
    //float heuristic = sum_remain[m];                       //bounding 1, using remaining value
    float heuristic = fractional(m,W-sum_w);             //bounding 2 (better), using fracktional knapsack of the remaining
    if (sum_v + heuristic < max_v) return ;

    //recursive
    x[m] = 1; search(x,m+1,sum_w + items[m].w, sum_v + items[m].v);
    x[m] = 0; search(x,m+1,sum_w,sum_v);
  }
}

int main() {
  int n;
  //read input
  cin >> W >> n;
  items.resize(n);
  sorted.resize(n);
  sum_remain.resize(n);
  for (int i = 0;i < n;i++) cin >> items[i].v;
  for (int i = 0;i < n;i++) cin >> items[i].w;

  //sort by weight (for better backtracking)
  sort(items.begin(),items.end(),compare1);

  //make cache for fractional knapsack
  for (int i = 0;i < n;i++) {
    sorted[i] = items;
    sort(sorted[i].begin() + i,sorted[i].end(),compare2);
  }

  ///make cache for sum remaining weight
  sum_remain[n-1] = items[n-1].v;
  for (int i = n-2;i >= 0;i--)
    sum_remain[i] = items[i].v + sum_remain[i+1];

  vector<int> x(n,0);

  search(x,0,0,0);
  printf("%.4f\n",max_v);
}
