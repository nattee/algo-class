# M + N6M

N, M = map(int, raw_input().split())
seq = map(int, raw_input().split())
t = map(int, raw_input().split())
C = [sum(t[:i]) for i in xrange(1,M)]
C = [C[-1]+t[-1]]+C

for n in xrange(N):
	A, B = map(int, raw_input().split())
	ans = 0
	for i in xrange(M-1):
		x, y = seq[i], seq[i+1]
		minxy = min(C[y]-C[x], C[x]-C[y]+C[0]) if C[x] <= C[y] else min(C[y]-C[x]+C[0], C[x]-C[y])
		minxA = min(C[A]-C[x], C[x]-C[A]+C[0]) if C[x] <= C[A] else min(C[A]-C[x]+C[0], C[x]-C[A])
		minBy = min(C[y]-C[B], C[B]-C[y]+C[0]) if C[B] <= C[y] else min(C[y]-C[B]+C[0], C[B]-C[y])
		minxB = min(C[B]-C[x], C[x]-C[B]+C[0]) if C[x] <= C[B] else min(C[B]-C[x]+C[0], C[x]-C[B])
		minAy = min(C[y]-C[A], C[A]-C[y]+C[0]) if C[A] <= C[y] else min(C[y]-C[A]+C[0], C[A]-C[y])
		ans += min(minxy, 
			minxA+minBy,
			minxB+minAy,)
	x, y = seq[-1], seq[0]
	minxy = min(C[y]-C[x], C[x]-C[y]+C[0]) if C[x] <= C[y] else min(C[y]-C[x]+C[0], C[x]-C[y])
	minxA = min(C[A]-C[x], C[x]-C[A]+C[0]) if C[x] <= C[A] else min(C[A]-C[x]+C[0], C[x]-C[A])
	minBy = min(C[y]-C[B], C[B]-C[y]+C[0]) if C[B] <= C[y] else min(C[y]-C[B]+C[0], C[B]-C[y])
	minxB = min(C[B]-C[x], C[x]-C[B]+C[0]) if C[x] <= C[B] else min(C[B]-C[x]+C[0], C[x]-C[B])
	minAy = min(C[y]-C[A], C[A]-C[y]+C[0]) if C[A] <= C[y] else min(C[y]-C[A]+C[0], C[A]-C[y])
	ans += min(minxy, 
		minxA+minBy,
		minxB+minAy,)
	print ans