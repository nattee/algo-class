R, C = map(int, raw_input().split())
T = [map(int, raw_input().strip()) for r in xrange(R)]
sumRow = [T[r][:] for r in xrange(R)]
sumCol = [T[r][:] for r in xrange(R)]
sumSquare = [T[r][:] for r in xrange(R)]
sumRow[0][1] = 0 if T[0][1]==0 else sumRow[0][0]+1
sumCol[1][0] = 0 if T[1][0]==0 else sumCol[0][0]+1
for r in xrange(1,R):
	for c in xrange(1,C):
		sumRow[r][c] = 0 if T[r][c]==0 else sumRow[r][c-1]+1
		sumCol[r][c] = 0 if T[r][c]==0 else sumCol[r-1][c]+1
		sumSquare[r][c] = 0 if T[r][c]==0 else min(sumSquare[r-1][c-1], sumRow[r][c-1], sumCol[r-1][c])+1
print max(sumSquare[r][c] for r in xrange(R) for c in xrange(C))