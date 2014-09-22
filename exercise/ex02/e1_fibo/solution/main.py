N = int(raw_input())
a, b = 0 ,1
for n in range(2,N+1):
	a, b = b, a+b
print b