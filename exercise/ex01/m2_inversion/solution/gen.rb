def genOneFile( filename, n, min = -100_000, max = 100_000)
  File.open(filename,"w") do |file|
    a = n.times.map{ min + rand(max - min) }
    file.puts n
    file.puts a.join(" ")
  end
end

genOneFile('../data/1.in',10,0,100)
genOneFile('../data/2.in',100,-100,100)
genOneFile('../data/3.in',1000,-10,10)
genOneFile('../data/4.in',10000)
genOneFile('../data/5.in',50000)

File.open('../data/6.in',"w") do |file|
  a = (0..49999).to_a.reverse
  file.puts 50000
  file.puts a.join(" ")
end
