# MM + NM
import sys
N, M = map(int, raw_input().split())
seq = map(int, raw_input().split())
t = map(int, raw_input().split())
cost = [[sys.maxint]*M for i in xrange(M)]

for i in xrange(M):
	cost[i][i] = 0
	cost[i-1][i] = t[i-1]
	cost[i][i-1] = t[i-1]
for i in xrange(M):
	for j in xrange(1,M):
		jj = (i+j)%M
		cost[i][jj] = min(cost[i][jj], cost[i][(jj-1)%M]+cost[(jj-1)%M][jj])
		jj = (i-j)%M
		cost[i][jj] = min(cost[i][jj], cost[i][(jj+1)%M]+cost[(jj+1)%M][jj])

for n in xrange(N):
	A, B = map(int, raw_input().split())
	ans = 0
	for i in xrange(M-1):
		a, b = seq[i], seq[i+1]
		ans += min(cost[a][b], cost[a][A]+cost[B][b], cost[a][B]+cost[A][b])
	a, b = seq[-1], seq[0]
	ans += min(cost[a][b], cost[a][A]+cost[B][b], cost[a][B]+cost[A][b])
	print ans