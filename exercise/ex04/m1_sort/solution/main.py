N = int(raw_input())
T = map(int, raw_input().split())

n = [sum([1 for t in T if t <= i]) for i in xrange(4)]
ans, now = 0, 1
for i in xrange(len(T)):
	if i == n[now]:
		now += 1
	if T[i] != now:
		try:
			iswap = n[T[i]-1] + T[n[T[i]-1]:n[T[i]]].index(now)
		except ValueError:
			continue
		T[i], T[iswap] = T[iswap], T[i]
		ans += 1
for i in xrange(n[1]):
	if T[i] != 1:
		ans += 2
print ans

