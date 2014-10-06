def genOneFile( filename, r, c = r, chance = 0.99) 
  File.open(filename,"w") do |file|
    file.puts "#{r} #{c}"
    r.times do
      a = c.times.map{ rand() <= chance ? 1 : 0 }
      file.puts a.join
    end
  end
end

genOneFile('data/1.in',5,5,0.8)
genOneFile('data/2.in',10,10,0.5)
genOneFile('data/3.in',30,30,0.8)
genOneFile('data/4.in',50,50)
genOneFile('data/5.in',300,300)
genOneFile('data/6.in',500,500)
genOneFile('data/7.in',800,800)
genOneFile('data/8.in',900,1000,0.9)
genOneFile('data/9.in',1000,900,0.05)
genOneFile('data/10.in',1000,1000)
