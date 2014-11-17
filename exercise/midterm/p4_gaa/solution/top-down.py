def lenG(k):
	if k < 0:
		return 0
	return lenG(k-1)*2 + k+3

def gaa(n,k):
	if n > lenG(k):
		return gaa(n,k+1)
	if n <= lenG(k-1):
		return gaa(n,k-1)
	n -= lenG(k-1)
	if n <= k+3:
		return 'g' if n==1 else 'a'
	return gaa(n-k-3,k-1)

N = int(raw_input())
print gaa(N,0)
