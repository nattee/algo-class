#!/usr/bin/env ruby

def genOneFile(filename, n, max = 1000)
  File.open(filename,"w") do |file|
    file.puts n
    file.puts n.times.map{ rand(max)+1 }.join(" ")
  end
end

genOneFile('data/1.in',5)
genOneFile('data/2.in',10)
genOneFile('data/3.in',20)
genOneFile('data/4.in',50)
genOneFile('data/5.in',100)
genOneFile('data/6.in',1000)
genOneFile('data/7.in',3000)
genOneFile('data/8.in',5000)
genOneFile('data/9.in',10000)
genOneFile('data/10.in',10000)
