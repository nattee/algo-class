def cnk(n,k):
	if C[n][k] < 0:
		C[n][k] = 1 if n==k or k==0 else cnk(n-1,k-1)+cnk(n-1,k)
	return C[n][k]
N, K = [int(a) for a in raw_input().split()]
C = [[-1 for j in range(K+1)] for i in range(N+1)]
print cnk(N,K)


