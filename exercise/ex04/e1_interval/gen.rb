def genOneFile(filename, n, max = [n,10].max)
  File.open(filename,"w") do |file|
    file.puts n
    a = n.times.map{ s = rand(max-1); f = rand(max-s) + s; [s,f] }
    s = a.collect{ |x| x[0] }
    f = a.collect{ |x| x[1] }
    file.puts s.join ' '
    file.puts f.join ' '
  end
end

genOneFile('data/1.in',10)
genOneFile('data/2.in',100)
genOneFile('data/3.in',100)
genOneFile('data/4.in',1000)
genOneFile('data/5.in',1000)
genOneFile('data/6.in',10000)
genOneFile('data/7.in',100000)
genOneFile('data/8.in',100000)
genOneFile('data/9.in',100000)
genOneFile('data/10.in',100000)
