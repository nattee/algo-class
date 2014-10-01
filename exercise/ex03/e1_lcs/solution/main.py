A = raw_input().strip()
B = raw_input().strip()
ans = [0]*(len(B)+1)
for i,a in enumerate(A):
	tmp = ans[:]
	for j,b in enumerate(B):
		if a == b:
			tmp[j+1] = max(ans[j+1],max(ans[:j+1])+1)
	ans = tmp
print max(ans)
