def genOneFile(filename,n,m)
  puts "gen " + filename
  File.open(filename,'w') do |f|
    f.puts [n,m].join ' '
    f.puts n.times.to_a.map { rand(1000) }.join ' '
  end
end

genOneFile('1.in',3,10)
genOneFile('2.in',20,100)
genOneFile('3.in',1000,1000)
genOneFile('4.in',2000,10000)
genOneFile('5.in',40000,10000)
genOneFile('6.in',50000,50000)
genOneFile('7.in',50000,70000)
genOneFile('8.in',50000,80000)
genOneFile('9.in',50000,90000)
genOneFile('10.in',50000,100000)
