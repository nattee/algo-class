N, M, K = [int(a) for a in raw_input().split()]
count = [[0]*(K+1) for i in xrange(N)]
count[0][0] = 1
for k in xrange(K):
	for n in xrange(N):
		for m in xrange(1,M+1):
			if n + m >= N:
				break
			count[n+m][k+1] += count[n][k]
print sum([count[-i][K] for i in xrange(1,min(M+1,N+1))])