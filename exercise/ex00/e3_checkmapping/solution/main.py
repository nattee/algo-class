N = int(raw_input())
S = [int(a) for a in raw_input().split()]
S.sort()
S += [S[-1]+1]
print 'YES' if len([0 for i in range(N) if S[i+1] !=  S[i]+1]) == 0 else 'NO'