def genOneFile( filename, n, e = n * 10,max = 1000) 
  puts "gen #{filename}"
  File.open filename, 'w' do |f|
    e = [n*n-n, e].min
    f.puts "#{n} #{e} #{rand(n)}"
    edge = []
    n.times do |i|
      n.times do |j|
        next if (i == j)
        c = rand(1000) + 1
        c = -c/100 if rand(20) == 0
        c = -1 if c == 0
        edge << [i,j,c]
      end
    end
    edge.shuffle[0...e].each do |e1|
      f.puts e1.join ' '
    end
  end
end


genOneFile('data/1.in',5)
genOneFile('data/2.in',15)
genOneFile('data/3.in',25)
genOneFile('data/4.in',35)
genOneFile('data/5.in',45)
genOneFile('data/6.in',55)
genOneFile('data/7.in',65)
genOneFile('data/8.in',75)
genOneFile('data/9.in',85)
genOneFile('data/10.in',100)
