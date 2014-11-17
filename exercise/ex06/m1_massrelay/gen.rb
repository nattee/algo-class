def genOneFile(filename,n,m = n*(n-1)/2,max = 999_999,q = n-1)
  puts "gen #{filename}"
  File.open filename,'w' do |f|
    m = [m,n*(n-1)/2,100_000].min
    q = [1,q].max

    f.puts [n,m,q].join ' '
    #edge
    e = []
    n.times do |i|
      ((i+1)...n).each do |j|
        e << [i,j]
      end
    end
    e.shuffle!
    m.times do |i|
      f.puts "#{e[i][0]} #{e[i][1]} #{rand(max)+1}"
    end
    #query
    f.puts (1...n).to_a.shuffle[0...q].join "\n"
  end
end

genOneFile('data/1.in',5,10,10)
genOneFile('data/2.in',100)
genOneFile('data/3.in',500)
genOneFile('data/4.in',750)
genOneFile('data/5.in',100)
genOneFile('data/6.in',1000,100_000,1000)
genOneFile('data/7.in',3000,100_000,30_000)
genOneFile('data/8.in',3000,100_000)
genOneFile('data/9.in',5000,100_000,30_000)
genOneFile('data/10.in',5000)
