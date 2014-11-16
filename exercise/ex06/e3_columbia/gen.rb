def genOneFile( filename, r, c, max = 1000)
  puts "gen #{filename}"
  File.open(filename,'w') do |f|
    f.puts "#{r} #{c}"
    r.times do 
      f.puts c.times.map{ rand(max) }.join ' '
    end
  end
end

genOneFile('data/1.in',10,10)
genOneFile('data/2.in',50,50)
genOneFile('data/3.in',100,40)
genOneFile('data/4.in',30,100)
genOneFile('data/5.in',100,100)
genOneFile('data/6.in',200,200)
genOneFile('data/7.in',250,250)
genOneFile('data/8.in',300,300)
genOneFile('data/9.in',350,350)
genOneFile('data/10.in',400,400)
