def genOneFile(filename,n,a,max_a = 10e9)
  puts "gen "+filename
  File.open(filename,'w') do |f|
    f.puts [n,a].join ' '
    f.puts n.times.to_a.map{ rand(1..1000) }.join ' '
    f.puts a.times.to_a.map{ rand(1..max_a) }.join ' '
  end
end

genOneFile('1.in',3,10,10)
genOneFile('2.in',3,10,1000)
genOneFile('3.in',500,100,1000)
genOneFile('4.in',500,100,1000)
genOneFile('5.in',1000,100,1000)
genOneFile('6.in',1000,200,1000000)
genOneFile('7.in',1000,200,1000000000000)
genOneFile('8.in',1000,200,1000000000000)
genOneFile('9.in',1000,200,1000000000000)
genOneFile('10.in',1000,200,1000000000000)
