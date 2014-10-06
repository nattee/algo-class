N = int(raw_input())
A = [int(a) for a in raw_input().split()]

ans = A[0]
for i in xrange(N):
	s = 0
	idx = i
	for j in xrange(N):
		s += A[idx]
		idx += 1
		if idx == N:
			idx = 0
		if s > ans:
			ans = s
print ans