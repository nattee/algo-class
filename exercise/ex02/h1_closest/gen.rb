def genOneFile( filename,n, parallel = false, mid = 1000)
  p = Hash.new

  unless parallel then
    while p.size < n do
      x = rand(30000)
      y = rand(30000)
      p[ [x,y] ] = true
    end
  else
    #left side
    ln = n/2
    rn = n - ln;
    left_y = (0..30000).to_a.shuffle()[0..ln-1]
    right_y = (0..30000).to_a.shuffle()[0..rn-1]
    left_y.each { |y| p [ [mid - 10,y] ] = true }
    right_y.each { |y| p [ [mid + 10,y] ] = true }
  end

  File.open(filename,"w") do |file|
    file.puts n
    k = p.keys.to_a.shuffle
    k.each do |key|
      file.puts "#{key[0]} #{key[1]}"
    end
  end
end

genOneFile('data/1.in',10)
genOneFile('data/2.in',10,true)
genOneFile('data/3.in',100)
genOneFile('data/4.in',100,true)
genOneFile('data/5.in',30000)
genOneFile('data/6.in',30000,true)
genOneFile('data/7.in',40000)
genOneFile('data/8.in',40000,true)
genOneFile('data/9.in',50000)
genOneFile('data/10.in',50000,true)
