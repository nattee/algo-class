#!/usr/bin/env ruby


def genOneFile(filename,n,m)
  File.open(filename,'w') do |f|
    f.puts "#{n} #{m}"
    f.puts m.times.map{ rand(1000) + 1 }.join ' '
  end
end

genOneFile('data/1.in',1,10)
genOneFile('data/2.in',3,100)
genOneFile('data/3.in',3,1000)
genOneFile('data/4.in',4,3000)
genOneFile('data/5.in',97,5000)
genOneFile('data/6.in',99,10000)
genOneFile('data/7.in',1,20000)
genOneFile('data/8.in',17,50000)
genOneFile('data/9.in',11,80000)
genOneFile('data/10.in',100,100000)
