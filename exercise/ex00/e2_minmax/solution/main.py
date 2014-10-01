N, M = [int(a) for a in raw_input().split()]
R = int(raw_input())
T = [[int(a) for a in raw_input().split()] for i in range(N)]
for r in range(R):
	r1, c1, r2, c2 = [int(a) for a in raw_input().split()]
	if r1 > r2 or c1 > c2:
		print 'INVALID'
		continue
	if r1 > N or c1 > M:
		print 'OUTSIDE'
		continue
	print '%d' % max([T[i][j] for i in range(r1-1,min(r2,N)) for j in range(c1-1,min(c2,M)) ])