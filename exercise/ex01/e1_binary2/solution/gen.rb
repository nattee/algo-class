#!/usr/bin/env ruby

def genOneFile( filename, n, m, max=n*4)
  max = 100000 if max > 100000
  File.open(filename,"w") do |f|
    a = (1..max).to_a.shuffle
    a = a[0..n-1].sort
    q = m.times.map{ rand(max) }
    f.puts "#{n} #{m}"
    f.puts a.join(" ")
    f.puts q.join(" ")
  end
end

genOneFile("../data/1.in",10,20);
genOneFile("../data/2.in",100,200);
genOneFile("../data/3.in",1000,2000);
genOneFile("../data/4.in",10000,20000);
genOneFile("../data/5.in",90000,100000);
