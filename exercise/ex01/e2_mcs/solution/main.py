N = int(raw_input())
A = [int(a) for a in raw_input().split()]
ans = A[0]
tmp = 0
for a in A:
	tmp = a if tmp < 0 else tmp + a
	ans = max(ans,tmp)
print ans
