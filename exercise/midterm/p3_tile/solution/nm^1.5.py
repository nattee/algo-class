maxInt = 1000000000
N, M = [int(a) for a in raw_input().split()]
A = [0]
for n in xrange(N):
	A += [int(raw_input())]
cost = [[maxInt]*(N+1) for m in xrange(M+1)]
cost[0][0] = 0
for i in xrange(1,N+1):
	for j in xrange(0,M+1):
		# sqrtI = int(j**0.5)
		# for k in xrange(1,sqrtI+1):
		for k in xrange(1,int(j**0.5)+1):
			# aa = (A[i]-k)*(A[i]-k) + cost[j-k*k][i-1]
			# aa = (A[i]-k)**2 + cost[j-k**2][i-1]
			# if aa < cost[j][i]:
			# 		cost[j][i] = aa
			# if (A[i]-k)**2 + cost[j-k**2][i-1] < cost[j][i]:
			# 		cost[j][i] = (A[i]-k)**2 + cost[j-k**2][i-1]
			if (A[i]-k)*(A[i]-k) + cost[j-k*k][i-1] < cost[j][i]:
					cost[j][i] = (A[i]-k)*(A[i]-k) + cost[j-k*k][i-1]
if cost[M][N] == maxInt:
	print "-1"
else:
	print cost[M][N]
