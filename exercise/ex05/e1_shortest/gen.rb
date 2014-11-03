def genOneFile(filename, r, c, bar_size = 5, bar_count = r * c / bar_size / 2)
  File.open filename,'w' do |f|
    f.puts [r,c].join ' '
    maze = Array.new(r){ Array.new(c,'.') }
    bar_count.times do 
      y = rand(r)
      x = rand(c)
      l = rand(bar_size) + 1
      if (rand(2) == 0) then
        (x...[(x+l),c].min).each do |i|
          maze[y][i] = '#'
        end
      else
        (y...[y+l,r].min).each do |i|
          maze[i][x] = '#'
        end
      end
    end
    r.times do |r|
      f.puts maze[r].join
    end
  end
end

genOneFile 'data/1.in', 10, 10
genOneFile 'data/2.in', 10, 1, 0, 0
genOneFile 'data/3.in', 1, 10, 0, 0
genOneFile 'data/4.in', 20, 20
genOneFile 'data/5.in', 30, 20
genOneFile 'data/6.in', 40, 30
genOneFile 'data/7.in', 50, 80
genOneFile 'data/8.in', 60, 100
genOneFile 'data/9.in', 90, 80
genOneFile 'data/10.in', 100, 100
