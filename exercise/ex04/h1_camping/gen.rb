def genOneFile(filename,n,d, max = n * 10)
  File.open(filename,'w') do |f|
    f.puts "#{n} #{d}"
    max = [max,n].max
    f.puts (1..max).to_a.shuffle[0..n-1].sort.join ' '
  end
end

genOneFile 'data/1.in',10,4
genOneFile 'data/2.in',10,10
genOneFile 'data/3.in',10,1
genOneFile 'data/4.in',100,20
genOneFile 'data/5.in',100,100
genOneFile 'data/6.in',100,1
genOneFile 'data/7.in',10000,20
genOneFile 'data/8.in',30000,20
genOneFile 'data/9.in',50000,100
genOneFile 'data/10.in',100000,200
