N, K = [int(a) for a in raw_input().split()]
C = [[0 for j in range(K+1)] for i in range(N+1)]
for n in range(N+1):
	for k in range(min(n+1,K+1)):
		if n == k: 
			C[n][k] = 1
		elif k == 0:
			C[n][k] = 1
		else:
			C[n][k] = C[n-1][k-1] + C[n-1][k]
print C[N][K]


