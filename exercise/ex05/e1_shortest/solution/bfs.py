R, C = map(int, raw_input().split())
maze = [list(raw_input()) for i in xrange(R)]

start = (0, 0)
goal = (R-1, C-1)
moves = [(0,1), (0,-1), (1,0), (-1,0),]
step = [[-1]*C for i in xrange(R)]
step[start[1]][start[0]] = 0
q = [start]
i = 0
while i < len(q) and step[goal[0]][goal[1]] == -1:
	for move in moves:
		y = q[i][0] + move[0]
		x = q[i][1] + move[1]
		if x >= 0 and x < C and y >= 0 and y < R and maze[y][x] == '.' and step[y][x] == -1 :
			step[y][x] = step[q[i][0]][q[i][1]] + 1
			q += [(y,x)]
	i += 1
print step[goal[0]][goal[1]]

