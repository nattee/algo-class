def genOneFile( filename, n ) 
  File.open(filename,"w") do |file|
    file.puts n
    n.times do |i|
      file.puts (i+1).times.map{ rand(1000) }.join(" ")
    end
  end
end


genOneFile('data/1.in',3)
genOneFile('data/2.in',6)
genOneFile('data/3.in',10)
genOneFile('data/4.in',14)
genOneFile('data/5.in',20)
genOneFile('data/6.in',30)
genOneFile('data/7.in',50)
genOneFile('data/8.in',100)
genOneFile('data/9.in',100)
genOneFile('data/10.in',100)
