#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


typedef struct block {
  int r,c; // the index
  int D;  // the current shortest cost
} Block;

//-------------------- heap
vector<Block> heap;
vector<vector<int>> link;
int N;  //num in heap

void swap_entry(int i,int j) {
  swap(heap[i],heap[j]);
  link[heap[i].r][heap[i].c] = i;
  link[heap[j].r][heap[j].c] = j;
}

void fixup(int pos) {
  while (pos > 0) {
    int p = (pos-1) / 2;
    if (heap[pos].D < heap[p].D) {
      swap_entry(pos,p);
      pos = p;
    } else {
      break;
    }
  }
}

void fixdown(int pos) {
  while ((pos * 2) + 1 < N) {
    int c = pos * 2 + 1;
    if ((c+1) < N && heap[c+1].D < heap[c].D) c++;
    if (heap[c].D < heap[pos].D) {
      swap_entry(pos,c);
      pos = c;
    } else {
      break;
    }
  }
}

Block& top() {
  return heap[0];
}

void pop() {
  swap_entry(0,N-1);
  N--;
  fixdown(0);
}


int main() {
  int R,C;
  cin >> R >> C;
  vector<vector<int>> fee(R, vector<int>(C,0) );
  link = vector<vector<int>>(R, vector<int>(C,0) );
  for (int i = 0;i < R;i++) {
    for (int j = 0;j < C;j++) {
      int a;
      cin >> a;
      fee[i][j] = a;
    }
  }

  // Dijkstra with e log v
  //set up block & heap
  N = 0;
  heap.resize(R*C);
  for (int i = 0;i < R;i++)
    for (int j = 0;j < C;j++) {
      heap[N] = {i,j,R*C*1000+10};
      link[i][j] = N;
      N++;
    }
  heap[0].D = 0;
  //dijkstra loop
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,-1,0,1};
  while (N > 0) {
    Block b = top();
    pop();
    for (int i = 0;i < 4;i++) {
      int nx = b.c + dx[i];
      int ny = b.r + dy[i];
      if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
        int b1,b2;
        b1 = link[ny][nx];
        b2 = link[b.r][b.c];
        //printf("i am at (%d,%d)[%d], checking (%d,%d)[%d]\n",b.r,b.c,b2,ny,nx,b1);
        if (heap[b1].D > heap[b2].D + fee[ny][nx]) {
          heap[b1].D = heap[b2].D + fee[ny][nx];
          fixup(b1);
        }
      }
    }
  }
  //output
  for (int i = 0;i < R;i++) {
    for (int j = 0;j < C;j++) {
      cout << heap[link[i][j]].D << " ";
    }
    cout << endl;
  }
}
