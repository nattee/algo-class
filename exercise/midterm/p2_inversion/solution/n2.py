N = int(raw_input())
A = [int(a) for a in raw_input().split()]
B = []
ans = 0
for a in A:
	B += [a]
	for i in xrange(1,len(B)):
		if a >= B[-i-1]:
			break
		B[-i] = B[-i-1]
		B[-i-1] = a
		ans += 1
print ans

