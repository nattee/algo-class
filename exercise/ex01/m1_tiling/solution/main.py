def tiling(a, b, c, x, y):
	if c == 2:
		p = (y-b)*2+(x-a)
		print '%d %d %d' %(p,a,b)
		return
	mid = c/2
	if x < a+mid and y < b+mid:
		print '0 %d %d' %(a+mid-1, b+mid-1)
		tiling(a, b, mid, x, y)
		tiling(a, b+mid, mid, a+mid-1, b+mid)
		tiling(a+mid, b, mid, a+mid, b+mid-1)
		tiling(a+mid, b+mid, mid, a+mid, b+mid)	
	elif x < a+mid and y >= b+mid:
		print '2 %d %d' %(a+mid-1, b+mid-1)
		tiling(a, b, mid, a+mid-1, b+mid-1)
		tiling(a, b+mid, mid, x, y)
		tiling(a+mid, b, mid, a+mid, b+mid-1)
		tiling(a+mid, b+mid, mid, a+mid, b+mid)
	elif x >= a+mid and y < b+mid:
		print '1 %d %d' %(a+mid-1, b+mid-1)
		tiling(a, b, mid, a+mid-1, b+mid-1)
		tiling(a, b+mid, mid, a+mid-1, b+mid)
		tiling(a+mid, b, mid, x, y)
		tiling(a+mid, b+mid, mid, a+mid, b+mid)
	elif x >= a+mid and y >= b+mid:
		print '3 %d %d' %(a+mid-1, b+mid-1)
		tiling(a, b, mid, a+mid-1, b+mid-1)
		tiling(a, b+mid, mid, a+mid-1, b+mid)
		tiling(a+mid, b, mid, a+mid, b+mid-1)
		tiling(a+mid, b+mid, mid, x, y)

L, X, Y = [int(a) for a in raw_input().split()]
print (L*L)/3
tiling(0,0,L,X,Y)

