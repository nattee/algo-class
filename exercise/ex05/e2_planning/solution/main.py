N = int(raw_input())
M = [map(int, raw_input().split())[1:] for i in xrange(N)]

visited = [0]*N
for i in xrange(N):
	if visited[i]:
		continue
	stk = [i]
	while len(stk) > 0:
		v = stk[-1]
		if visited[v]:
			del(stk[-1])
			continue
		if len(M[v]) == 0:
			print v,
			visited[v] = 1
			del(stk[-1])
		for req in M[v]:
			stk += [req]
		M[v] = []