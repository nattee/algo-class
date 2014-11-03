W, N = raw_input().split()
W = float(W)
N = int(N)
vw = [	map(float, raw_input().split()),
		map(float, raw_input().split()),]
vw = zip(*vw)
vw = [[a[0]/a[1] if a[1] != 0 else a[0], a[1]] for a in vw]
vw.sort(reverse=True)
ans = 0.
for i in xrange(N):
	if W <= 0:
		break
	x = min(W, vw[i][1])
	ans += vw[i][0]*x if vw[i][1] != 0 else vw[i][0]
	W -= x
print ans
