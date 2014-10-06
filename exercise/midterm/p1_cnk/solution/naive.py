def cnk(n,k):
	return 1 if n==k or k==0 else cnk(n-1,k-1)+cnk(n-1,k)
N, K = [int(a) for a in raw_input().split()]
print cnk(N,K)


