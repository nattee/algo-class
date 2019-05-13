N = int(raw_input())
C = [int(a) for a in raw_input().split()]
B = [0]*len(C)
B[:2] = C[:2]
for i in xrange(2,len(C)):
	B[i] = max(B[i-1], max(B[:i-1])+C[i])
print B[-1]
