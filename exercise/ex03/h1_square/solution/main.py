R, C = [int(a) for a in raw_input().split()]
T = [[int(a) for a in raw_input().strip()] for r in xrange(R)]
sumRow = [T[r][:] for r in xrange(R)]
sumCol = [T[r][:] for r in xrange(R)]
sumSquare = [T[r][:] for r in xrange(R)]
for r in xrange(R):
	for c in xrange(1,C):
		sumRow[r][c] = 0 if T[r][c]==0 else sumRow[r][c-1]+1
for r in xrange(1,R):
	for c in xrange(C):
		sumCol[r][c] = 0 if T[r][c]==0 else sumCol[r-1][c]+1
for r in xrange(1,R):
	for c in xrange(1,C):
		sumSquare[r][c] = 0 if T[r][c]==0 else min(sumSquare[r-1][c-1], sumRow[r][c-1], sumCol[r-1][c])+1
print max(sumSquare[r][c] for r in xrange(R) for c in xrange(C))
