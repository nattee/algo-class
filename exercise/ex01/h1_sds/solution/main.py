#from bisect import bisect_left

def bisect_left(A, x):
	begin = 0
	end = len(A)
	while begin < end:
		mid = (begin+end)/2
		if x <= A[mid]:
			end = mid
		else:
			begin = mid+1
	return begin

A = [0,1,2,4,6,9]
i = 9
j = 3
while i < 2000000000:
	i += j
	A += [i]
	if len(A)-1 >= A[j+1]:
		j += 1
# print A
N = int(raw_input())
for n in range(N):
	x = int(raw_input())
	b = bisect_left(A,x)
	print b if A[b] == x else b-1