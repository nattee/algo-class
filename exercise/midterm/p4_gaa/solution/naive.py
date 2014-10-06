N = int(raw_input())
G = ''
midG = 'gaa'
while len(G) < N:
	G += midG + G
	midG += 'a'
print G[N-1]