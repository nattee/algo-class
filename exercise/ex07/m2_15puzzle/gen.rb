def move(board,last)
  y,x = -1,-1
  4.times do |i|
    4.times do |j|
      y,x = i,j if board[i][j] == 0
    end
  end

  dx = [1,0,-1,0]
  dy = [0,-1,0,1]
  reverse = [2,3,0,1]
  dir = nx = ny = 0
  loop do
    dir = rand(4)
    next if dir == last
    nx = x + dx[dir]
    ny = y + dy[dir]
    break if nx.between?(0,3) and ny.between?(0,3)
  end
  board[ny][nx],board[y][x] = board[y][x],board[ny][nx]
  return board,reverse[dir]
end

def genOneFile( filename, move )
  File.open filename,'w' do |f|
    b = [ [1,2,3,4], [5,6,7,8], [9,10,11,12], [13,14,15,0] ]
    last = -1
    move.times do
      b,last = move(b,last)
    end
    4.times { |i| f.puts b[i].join ' ' }
  end
end


genOneFile('data/1.in',5)
genOneFile('data/2.in',10)
genOneFile('data/3.in',15)
genOneFile('data/4.in',30)
genOneFile('data/5.in',40)
genOneFile('data/6.in',45)
genOneFile('data/7.in',45)
genOneFile('data/8.in',45)
genOneFile('data/9.in',45)
genOneFile('data/10.in',45)
