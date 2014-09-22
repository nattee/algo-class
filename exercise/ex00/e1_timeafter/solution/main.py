H, M = [int(a) for a in raw_input().split()]
X = int(raw_input())
m = (60*H + M + X) % (24*60)
print '%02d %02d' % (m/60, m%60)
