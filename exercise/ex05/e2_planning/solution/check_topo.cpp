#include <vector>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream input_file;      //problem's input file
ifstream solution_file;   //problem's output file
ifstream submit_file;     //file generated from submitter's program
string language;
int full_score;

void report(bool correct,int score) {
  if (correct)
    cout << "Correct" << endl;
  else
    cout << "Incorrect" << endl;
  cout << score << endl;
}


int main(int argc,char **argv) {
  /* process param */
  input_file.open(argv[3]);
  solution_file.open(argv[4]);
  submit_file.open(argv[5]);
  full_score = (argc > 6?  atoi(argv[6]) : 10);

  /*  grading section  */
  vector<vector<bool> > edge;
  vector<int> indeg;
  int N;
  input_file >> N;
  edge.clear(); edge.resize(N);
  indeg.clear(); indeg.resize(N);
  for (int i = 0;i < N;i++) edge[i].resize(N);

  for (int i = 0;i < N;i++) {
    int M;
    input_file >> M;
    while(M--) {
      int x;
      input_file >> x;
      edge[x][i] = true;
      indeg[i]++;
    }
  }

  for (int i = 0;i < N;i++) {
    int x;
    submit_file >> x;
    if (indeg[x] != 0) {
      report(false,0);
      exit(0);
    }
    for (int j = 0;j < N;j++) {
      if (edge[x][j])
        indeg[j]--;
    }
  }
  report(true,full_score);

}
