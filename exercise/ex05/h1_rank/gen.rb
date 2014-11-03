def genOneFile( filename, n, e) 
  puts filename
  File.open(filename,"w") do |file|
    file.puts [n,e].join ' '
    e.times do
      a = rand(n)
      b = rand(n)
      while b == a
        b = rand(n)
      end
      file.puts [a,b].join ' '
    end
  end
end


genOneFile('data/1.in',10,20)
genOneFile('data/2.in',10,30)
genOneFile('data/3.in',10,40)
genOneFile('data/4.in',100,10)
genOneFile('data/5.in',100,100)
genOneFile('data/6.in',100,200)
genOneFile('data/7.in',5000,100)
genOneFile('data/8.in',5000,10000)
genOneFile('data/9.in',5000,10000)
genOneFile('data/10.in',5000,20000)
