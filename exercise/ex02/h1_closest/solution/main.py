N = int(raw_input())
P = []
for n in xrange(N):
	P.append([int(a) for a in raw_input().split()])
Px = sorted(P, key = lambda x: (x[0]))
Py = sorted(P, key = lambda x: (x[1]))

def distance(a,b):
	return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1])

def ClosestPairMid(PyMid,minDist):
	minDist2 = minDist**0.5
	count = 0
	for i in xrange(len(PyMid)):
		for j in xrange(i+1,len(PyMid)):
			if PyMid[j][1] - PyMid[i][1] > minDist2:
				break
			dist = distance(PyMid[i],PyMid[j]) 
			minDist = min(minDist,dist)
			count += 1
	return minDist

def ClosestPair(Px, Py, begin ,end):
	if end-begin < 2:
		return 2000000000
	if end-begin == 2:
		return distance(Px[begin],Px[begin+1])
	if Px[begin][0] == Px[end-1][0]:
		return min([distance(Py[i],Py[i+1]) for i in xrange(len(Py)-1) ])
	mid = ((begin+end)/2)
	midX = Px[mid-1][0]
	PyL = [p for p in Py if p[0] <= midX]
	PyR = [p for p in Py if p[0] >= midX]
	distL = ClosestPair(Px,PyL,begin,mid)
	distR = ClosestPair(Px,PyR,mid,end)
	minDist = min(distL,distR)
	minDist2 = minDist**0.5
	PyMid = [p for p in Py if abs(p[0]-midX) < minDist2]
	minDist = ClosestPairMid(PyMid,minDist)
	return minDist

print ClosestPair(Px,Py,0,len(Px))



	