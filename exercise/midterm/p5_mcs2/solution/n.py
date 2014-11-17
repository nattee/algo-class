def mcs(A):
	ans = A[0]
	tmp = 0
	for a in A:
		tmp = a if tmp < 0 else tmp + a
		ans = max(ans,tmp)
	return ans

N = int(raw_input())
A = [int(a) for a in raw_input().split()]
B = [-a for a in A]
mcsA = mcs(A)
mcsB = mcs(B)
sumA = sum(A)
print max(mcsA,sumA+mcsB) if mcsB!=-sumA else mcsA
