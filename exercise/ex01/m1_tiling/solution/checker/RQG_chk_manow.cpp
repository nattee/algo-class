#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>

int full_score;
char inputFile[100];
char studentFile[100];

typedef struct _BLOCK {
	int sx, sy;	// top left corner
	int gx, gy;	// gap location relative to the top left corner
} BLOCK;

int check(int n, int gx, int gy){
	FILE* f = NULL;
	//static const int FULL_SCORE = 1;
	int score = 0;
	int wn = 0;

	char *board=new char[n*n];
	{	// clean up board
		for (int i = 0; i < n*n; i++) {
			board[i] = 0;
		}
	}

	try {

		f = fopen(studentFile, "rt");
		if (!f) {
			throw 1;
		}
	
		if (feof(f)) { throw 6; }	// unexpected eof
		fscanf(f, "%d", &wn);		// count # wedges

		if (wn != (n*n-1)/3) {
			throw 2;
		}

		for (int i = 0; i < wn; i++) {
			BLOCK b;
			int dir=0;	

			if (feof(f)) { throw 6; }	// unexpected eof

			fscanf(f, "%d %d %d", &dir, &b.sx, &b.sy);
			if (dir < 0 || dir > 3) {
				throw 3;
			}
			//printf("%d %d %d\n", dir, b.sx, b.sy);
			{
				b.gx = dir%2;
				b.gy = dir/2;
			}
			//fscanf(f, "%d %d %d %d", &b.sx, &b.sy, &b.gx, &b.gy);

			// check for valid wedge rotation
			if (b.gx < 0 || b.gy < 0 || b.gx > 1 || b.gy > 1) {
				throw 3;
			}

			// check for valid wedge starting point
			if (b.sx < 0 || b.sy < 0 || b.sx > n-2 || b.sy > n-2) {
				throw 4;
			}

			for (int y=0; y < 2; y++) {
				for (int x=0; x < 2; x++) {

					if (y == b.gy && x == b.gx) {
						// do nothing
					} else {
						int ix = (b.sx+x) + (b.sy+y)*n;
						if (board[ix] > 0)
							throw 5;	// overlapping placement
						else {			// mark placed
							board[ix] = 1;
						}
					}

				}
			}
			
		}

		{// check for #empty tile
			int n_empty = 0;
			for (int y =0; y < n; y++)
			for (int x =0; x < n; x++) {
				if (board[x+y*n]==0) {
					if (x != gx || y != gy) {
						// wrong missing block
						throw 8;
					}
					++n_empty;
				}
			}
			if (n_empty != 1) {	// must be 1 or wrong
				throw 7;		// too many empty space
			}
		}

		// no error!
		score = full_score;

		printf("Correct\n\n");

	} 
	catch (int errno) {	// some error in the code!
		//printf("WRONG!, Reason: %d\n", errno);	
		printf("Incorrect\n0\n");
	}

	delete [] board;
	if (f) fclose(f);
	
	return 1;
}

int main(int argc,char **argv) {
	int n=0, gx=0, gy = 0;

	FILE * f = fopen(argv[3], "rt");
	strcpy(studentFile,argv[4]);
	full_score = atoi(argv[6]);
	if (!f) {
		return -1;
	}
	fscanf(f, "%d %d %d", &n, &gx, &gy);
	//printf("n = %d, gx = %d, gy = %d: ", n, gx, gy);
	fclose(f);

	check(n, gx, gy);
	return 0;
}