def genOneFile( filename, n, m, max = [1000,m].min)
  File.open(filename,"w") do |f|
    f.puts "#{n} #{m}"
    f.puts ((2..max).to_a.shuffle.slice(0,n-1) + [1]).sort.reverse.join " "
  end
end

genOneFile('data/3.in', 10, 200)
genOneFile('data/4.in', 10, 200)
genOneFile('data/5.in', 10, 1000)
genOneFile('data/6.in', 13, 2000)
genOneFile('data/7.in', 17, 5000)
genOneFile('data/8.in', 20, 1000)
genOneFile('data/9.in', 20, 5000)
genOneFile('data/10.in', 20, 10000)
