N, M = [int(a) for a in raw_input().split()]
C = [int(a) for a in raw_input().split()]
ans = [0]*(M+1)
for i, a in enumerate(ans):
	minC = 1000000000
	for c in C:
		if i - c >= 0:
			minC = min(minC,ans[i-c]+1)
	if minC != 1000000000:
		ans[i] = minC
print ans[M]