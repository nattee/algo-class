N, M = [int(a) for a in raw_input().split()]
A = [int(a) for a in raw_input().split()]
Q = [int(a) for a in raw_input().split()]
hasNum = [0]*1000001
for a in A:
	hasNum[a] = 1
for m in range(M):
	b = False;
	for a in A:
		if hasNum[Q[m]-a]:
			b = True
			break
	print 'YES' if b else 'NO'
