#!/usr/bin/evn ruby

def genOneFile( filename, n, force_celeb = false )
  k = Array.new(n) { Array.new(n,0) }
  rand(n*n).times do 
    a = rand(n)
    b = rand(n)
    k[a][b] = 1 unless a == b
  end
  if force_celeb then
    x = rand(n)
    n.times{ |i| k[i][x] = 1}
    k[x] = Array.new(n,0)
  end
  File.open(filename,"w") do |file|
    file.puts n
    n.times do |i|
      file.puts k[i].join(" ")
    end
  end
end


genOneFile('data/1.in',3)
genOneFile('data/2.in',3,true)
genOneFile('data/3.in',10)
genOneFile('data/4.in',10,true)
genOneFile('data/5.in',100)
genOneFile('data/6.in',100,true)
genOneFile('data/7.in',500)
genOneFile('data/8.in',500,true)
genOneFile('data/9.in',1000)
genOneFile('data/10.in',1000,true)
