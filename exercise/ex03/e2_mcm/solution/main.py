def mcm(A,l,r,MCM):
	if r-l <= 1:
		return 0
	if MCM[l][r] > 0:
		return MCM[l][r]
	ans = 1000000000
	for i in xrange(l+1,r):
		mcmL = mcm(A,l,i,MCM)
		mcmR = mcm(A,i,r,MCM)
		mulC = A[l]*A[i]*A[r]
		ans = min(ans, mcmL+mcmR+mulC)
	MCM[l][r] = ans
	return ans
N = int(raw_input())
A = [int(a) for a in raw_input().split()]
MCM = [[0]*len(A) for i in xrange(len(A))]
print mcm(A, 0, len(A)-1, MCM)

