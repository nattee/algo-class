N = int(raw_input())
A = [int(a) for a in raw_input().split()]
B = [1]*len(A)
for ia, a in enumerate(A):
	B[ia] = max([0]+[B[j] for j in xrange(ia) if A[j]<=a])+1
print max(B)
