# M + NM

N, M = map(int, raw_input().split())
seq = map(int, raw_input().split())
t = map(int, raw_input().split())
C = [sum(t[:i]) for i in xrange(1,M)]
C = [C[-1]+t[-1]]+C

def getC(a, b):
	CCW = (C[b]-C[a]+C[0])%C[0]
	CCCW = (C[a]-C[b]+C[0])%C[0]
	return min(CCW,CCCW)

for n in xrange(N):
	A, B = map(int, raw_input().split())
	ans = 0
	for i in xrange(M-1):
		a, b = seq[i], seq[i+1]
		ans += min(getC(a,b), 
			getC(a,A)+getC(B,b),
			getC(a,B)+getC(A,b),)
	a, b = seq[-1], seq[0]
	ans += min(getC(a,b), 
		getC(a,A)+getC(B,b),
		getC(a,B)+getC(A,b),)
	print ans