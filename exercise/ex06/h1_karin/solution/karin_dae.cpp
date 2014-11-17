#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

#define MAX_N 1001
#define MAX_K 30
#define MAX_LONG_LONG 100000000000000LL

typedef long long dtype;

void solve(int n,int k,dtype dist[MAX_K][MAX_K] ,dtype one[MAX_K][MAX_K]) {
  if (n == 1) {
      for (int i = 0;i < k;++i) {
        for (int j = 0;j < k;++j) {
          dist[i][j] = one[i][j];
        }
      }
  } else {
    dtype tmp[MAX_K][MAX_K];
    solve(n/2,k,tmp,one);

    if (n % 2 == 0) {
      for (int i = 0;i < k;++i) {
        for (int j = 0;j < k;++j) {
          dist[i][j] = MAX_LONG_LONG;
          for (int r = 0;r < k;++r) {
            if (dist[i][j] > tmp[i][r] + tmp[r][j]) dist[i][j] = tmp[i][r] + tmp[r][j];
          }
        }
      }
    } else {
      //if odd, do one more level
      dtype res[MAX_K][MAX_K];
      for (int i = 0;i < k;++i) {
        for (int j = 0;j < k;++j) {
          res[i][j] = MAX_LONG_LONG;
          for (int r = 0;r < k;++r) {
            if (res[i][j] > tmp[i][r] + tmp[r][j]) res[i][j] = tmp[i][r] + tmp[r][j];
          }
        }
      }
      for (int i = 0;i < k;++i) {
        for (int j = 0;j < k;++j) {
          dist[i][j] = MAX_LONG_LONG;
          for (int r = 0;r < k;++r) {
            if (dist[i][j] > res[i][r] + one[r][j]) dist[i][j] = res[i][r] + one[r][j];
          }
        }
      }

    }

  }
}


void getTargetRoom(int fromFloor,int fromRoom,int dir,int k,int &toFloor,int &toRoom) {
  switch (dir) {
    case 0:
      toFloor = fromFloor;
      toRoom = (fromRoom + (k-1)) % k;
      break;
    case 1:
      toFloor = fromFloor;
      toRoom = (fromRoom + 1) % k;
      break;
    case 2:
      toFloor = fromFloor+1;
      toRoom = (fromRoom + (k-1)) % k;
      break;
    case 3:
      toFloor = fromFloor+1;
      toRoom = fromRoom;
      break;
    case 4:
      toFloor = fromFloor+1;
      toRoom = (fromRoom + 1) % k;
      break;
  }
}


int main() {
  //freopen("Karin_sample_in.txt","r",stdin);
  //freopen("Karin_in.txt","r",stdin);
  //freopen("Karin_out2.txt","w",stdout);

  int n,k,p;
  int a[MAX_K][5]; //left, right, left-up, up , right-up


  //read input
  scanf("%d %d %d",&n,&k,&p);
  n--;
  for (int i = 0;i < k;++i) {
    for (int j = 0;j < 5;++j) {
      scanf("%d",&a[i][j]);
    }
  }

  //solve
  dtype dist[MAX_K][MAX_K];
  dtype one[MAX_K][MAX_K];  // one[a][b] = shortest path from a-th room to b-th room on the next floor
  dtype first[2][MAX_K];  // first[a][b] = shortest path from (0,0) to (a,b)
  dtype min = 0;  // the solution


  //gen first level by bellman-ford

  //init tmp
  for (int i = 0;i < k;i++) {
    first[0][i] = INT_MAX;
    first[1][i] = INT_MAX;
  }
  first[0][0] = 0;


  for (int i = 0;i < 2*k;++i) {
    //for every edge on first floor
    for (int j = 0;j < k;++j) {
      for (int dir = 0;dir < 5;++dir) {
        int tof,tor;
        getTargetRoom(0,j,dir,k,tof,tor);
        if (first[0][j] + a[j][dir] < first[tof][tor])
          first[tof][tor] = first[0][j] + a[j][dir];
      }
    }

    //for every left, right edge on second floor
    for (int j = 0;j < k;++j) {
      for (int dir = 0;dir < 2;++dir) {
        int tof,tor;
        getTargetRoom(1,j,dir,k,tof,tor);
        if (first[1][j] + a[j][dir] < first[tof][tor])
          first[tof][tor] = first[1][j] + a[j][dir];
      }
    }
  }



  //special case
  if (n == 1) {
    min = first[1][p];
    //printf("yeah!\n");
  } else {

    //gen one level by k times of bellman-ford (i am too lazy)

    dtype tmp[2][MAX_K];  // one[a][b] = shortest path from a-th room to b-th room on the next floor

    for (int r = 0;r < k;++r) {
      //init tmp
      for (int i = 0;i < k;i++) {
        tmp[0][i] = INT_MAX;
        tmp[1][i] = INT_MAX;
      }
      tmp[0][r] = 0;


      for (int i = 0;i < 2*k;++i) {
        //for every edge on first floor
        for (int j = 0;j < k;++j) {
          for (int dir = 0;dir < 5;++dir) {
            int tof,tor;
            getTargetRoom(0,j,dir,k,tof,tor);
            if (tmp[0][j] + a[j][dir] < tmp[tof][tor])
              tmp[tof][tor] = tmp[0][j] + a[j][dir];
          }
        }

        //for every left, right edge on second floor
        for (int j = 0;j < k;++j) {
          for (int dir = 0;dir < 2;++dir) {
            int tof,tor;
            getTargetRoom(1,j,dir,k,tof,tor);
            if (tmp[1][j] + a[j][dir] < tmp[tof][tor])
              tmp[tof][tor] = tmp[1][j] + a[j][dir];
          }
        }
      }

      for (int i = 0;i < k;++i) {
        one[r][i] = tmp[1][i];
      }

    }

    //solve for dist;
    solve(n-1,k,dist,one);

    min = first[1][0] + dist[0][p];
    for (int r = 1;r < k;++r) {
      if (min > first[1][r] + dist[r][p])
        min = first[1][r] + dist[r][p];
    }
  }

  std::cout << min << std::endl;
}
