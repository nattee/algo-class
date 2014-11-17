N = int(raw_input())
K = [[int(i) for i in raw_input().split()] for i in range(N)]
R = [sum(K[i]) for i in range(N)] #sum each row
C = [sum([K[i][j] for i in range(N)]) for j in range(N)] #sum each column
ans = [i+1 for i in range(N) if R[i]==0 and C[i]==N-1]
print ans[0] if len(ans)>0 else 0