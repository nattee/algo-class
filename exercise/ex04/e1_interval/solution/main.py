from operator import itemgetter
N = int(raw_input())
time = [map(int, raw_input().split()),
		map(int, raw_input().split()), ]
time = zip(*time) #transpose
time.sort(key=itemgetter(1))
ans = 0
last = 0
for a in xrange(N):
	if time[a][0] >= last:
		ans += 1
		last = time[a][1]
print ans
