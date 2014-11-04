N, M = map(int, raw_input().split())
time = map(int, raw_input().split())
time.sort()
workertime = [0]*N
ans = 0.
for i,t in enumerate(time):
	mintime = workertime[i]
	ans += mintime+t
	workertime += [mintime+t]
print ans/M
