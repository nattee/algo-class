from heapq import *
N, M = map(int, raw_input().split())
time = map(int, raw_input().split())
time.sort()
workertime = [0]*N
ans = 0.
for t in time:
	mintime = heappop(workertime)
	ans += mintime+t
	heappush(workertime, mintime+t)
print ans/M
