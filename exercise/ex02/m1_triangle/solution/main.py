N = int(raw_input())
T = [[int(a) for a in raw_input().split()] for n in xrange(N)]
S = T[:]
for i in xrange(1,N):
	S[i][0] += S[i-1][0]
	for j in xrange(1,i):
		S[i][j] += max(S[i-1][j-1],S[i-1][j])
	S[i][i] += S[i-1][i-1]
print max(S[N-1])



