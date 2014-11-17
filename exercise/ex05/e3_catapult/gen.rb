def genOneFile( filename, n, m = n/100)
  puts "gen #{filename}"
  m = [m,n*n - n].min
  File.open filename,'w' do |f|
    f.puts n
    edge = Array.new(n){ Array.new(n,false) }
    m.times do 
      loop do
        a = rand(n)
        b = rand(n)
        next if a == b or edge[a][b]
        edge[a][b] = true
        break
      end
    end
    #randomly gen cycle
    count = n
    idx = 0
    perm = (0...n).to_a.shuffle
    perm << perm[0]
    while (idx < n) do
      remain = n - idx
      size = rand(remain/3+1) + 1
      #puts "gen #{idx} with size #{size}"

      if size > 1 then
        (idx...(idx+size-1)).each do |i|
          a = perm[i]
          b = perm[i+1]
          edge[a][b] = true
        end
        edge[perm[idx+size-1]][perm[idx]] = true
      end
      idx += size
    end
    #print
    edge.each do |e|
      v = Array.new
      n.times do |j|
        v << j if e[j]
      end
      f.puts "#{v.size} #{v.join ' '}"
    end
  end
end


genOneFile('data/1.in',10,20)
genOneFile('data/2.in',10,20)
genOneFile('data/3.in',50,10)
genOneFile('data/4.in',100,10)
genOneFile('data/5.in',300)
genOneFile('data/6.in',500)
genOneFile('data/7.in',500)
genOneFile('data/8.in',800)
genOneFile('data/9.in',1000)
genOneFile('data/10.in',1000,50000)
