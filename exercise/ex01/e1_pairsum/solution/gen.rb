def genOneFile( filename, n, m,min = -100_000,max = 100_000 )
  File.open(filename,"w") do |file|
    a = n.times.map{ min + rand(max-min) }
    file.puts "#{n} #{m}"

    nq1 = m / 2;
    nq2 = m - nq1

    q1 = nq1.times.map{ a[rand(n)] + a[rand(n)]}
    q2 = nq2.times.map{ rand(max * 10) }
    q = q1 + q2
    q = q.shuffle

    file.puts a.join(" ")
    file.puts q.join(" ")
  end
end

genOneFile('../data/1.in',10,10,0,100)
genOneFile('../data/2.in',100,10,0,1000)
genOneFile('../data/3.in',1000,10,0,10000)
genOneFile('../data/4.in',1000,100,0,10000)
genOneFile('../data/5.in',10000,100,0)
genOneFile('../data/6.in',100000,100,0)
genOneFile('../data/7.in',100000,100,0)
genOneFile('../data/8.in',100000,100,0)
genOneFile('../data/9.in',100000,100,0)
genOneFile('../data/10.in',100000,100,0)
