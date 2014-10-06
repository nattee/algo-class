def mcs2(A,l,r,sumL,sumR):
	if l == r:
		return A[l]
	mid = (l+r)/2
	ansL = mcs2(A,l,mid,sumL,sumR)
	ansR = mcs2(A,mid+1,r,sumL,sumR)
	s = A[mid] 
	maxL = s
	for i in xrange(mid-1,l-1,-1):
		s += A[i]
		maxL = max(s,maxL)
	s = A[mid+1] 
	maxR = s
	for i in xrange(mid+2,r+1):
		s += A[i]
		maxR = max(s,maxR)
	ans = maxL + maxR
	maxL = sumL[l]
	for i in xrange(l+1,mid+1):
		maxL = max(sumL[i],maxL)
	maxR = sumR[r]
	for i in xrange(r-1,mid,-1):
		maxR = max(sumR[i],maxR)
	ans = max([ans, maxL+maxR, ansL, ansR])
	return ans

N = int(raw_input())
A = [int(a) for a in raw_input().split()]
sumL = A[:]
sumR = A[:]
for i in xrange(1,len(A)):
	sumL[i] += sumL[i-1]
	sumR[-i-1] += sumR[-i] 
print mcs2(A,0,len(A)-1,sumL,sumR)