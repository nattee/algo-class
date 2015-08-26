def genOneFile(filename,n,m,a) 
  puts "gen #{filename}"
  File.open(filename,'w') do |f|
    f.puts [n,m,a].join ' '
    f.puts n.times.to_a.map { rand(1..10) }.join ' '
    a.times do 
      if rand() < 0.1 
        f.puts "W #{rand(1..m)} #{rand(1..n)}"
      else
        f.puts "B #{rand(1..m)} #{rand(1..n)} #{rand(1..1000)}"
      end
    end
  end
end

genOneFile('1.in',10,10,100)
genOneFile('2.in',1000,1000,1000)
genOneFile('3.in',1000,1000,10000)
genOneFile('4.in',10,1000,10000)
genOneFile('5.in',1000,10,10000)
genOneFile('6.in',10000,100,100000)
genOneFile('7.in',100,10000,100000)
genOneFile('8.in',10000,10000,100000)
genOneFile('9.in',10000,10000,100000)
genOneFile('10.in',10000,10000,100000)
