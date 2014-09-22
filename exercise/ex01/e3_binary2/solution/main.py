def bisect_right(A, x):
	begin = 0
	end = len(A)
	while begin < end:
		mid = (begin+end)/2
		if x < A[mid]:
			end = mid
		else:
			begin = mid+1
	return begin

N, M = [int(a) for a in raw_input().split()]
A = [int(a) for a in raw_input().split()]
X = [int(a) for a in raw_input().split()]
A.sort()
for x in X:
	i = bisect_right(A,x)
	print -1 if i==0 and x < A[i] else A[i-1]
