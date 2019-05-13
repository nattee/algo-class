N, D = map(int, raw_input().split())
H = [0]+map(int, raw_input().split())

def find_day(k):
	day = 1
	last = 0
	for i in xrange(1, N+1):
		if H[i] - H[last] > k:
			last = i-1
			day += 1
	return day

a = max([H[i+1]-H[i] for i in xrange(N)])
b = H[-1]
while a < b:
	mid = (a+b)/2
	day = find_day(mid)
	if day > D:
		a = mid+1
	else:
		b = mid

print b, find_day(b)