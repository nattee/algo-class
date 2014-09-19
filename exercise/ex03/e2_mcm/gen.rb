def genOneFile(filename,n,max=100)
  File.open(filename,"w") do |file|
    file.puts n
    file.puts (n+1).times.map{ rand(max) + 1}.join " "
  end
end


genOneFile('data/1.in',5)
genOneFile('data/2.in',10)
genOneFile('data/3.in',15)
genOneFile('data/4.in',20)
genOneFile('data/5.in',25)
genOneFile('data/6.in',30)
genOneFile('data/7.in',35)
genOneFile('data/8.in',40)
genOneFile('data/9.in',45)
genOneFile('data/10.in',50)
