N = int(raw_input())
lenG = [3]
for k in xrange(1,N):
	l = lenG[-1] + k+3 + lenG[-1]
	lenG += [l]
	if lenG[-1] >= N:
		break
n = N
for i in range(1,len(lenG)):
	if n <= lenG[-i-1]:
		continue
	n -= lenG[-i-1]
	if n <= len(lenG)-i + 3:
		break
	n -= len(lenG)-i + 3
print "g" if n == 1 else "a"

