#!/usr/bin/env ruby


def genOneFile( name, n, repeat = false, out = false)
  a = (1..n).to_a
  n.times do |i|
    k = i + rand(n-i)
    a[i], a[k] = a[k], a[i]
  end

  if out
    (1 + rand(n)).times { a[rand(n)] = rand(n*10) - n*5 }
  end

  if repeat
    a[n/2] = a[rand(n/2)+n/2]
  end


  File.open(name,"w") do |f|
    f.write "#{n}\n"
    f.write a.join(" ")
  end
end


genOneFile("../data/1.in",10)
genOneFile("../data/2.in",10)
genOneFile("../data/3.in",10)
genOneFile("../data/4.in",10,true)
genOneFile("../data/5.in",10,true)
genOneFile("../data/6.in",10,true)
genOneFile("../data/7.in",10,false,true)
genOneFile("../data/8.in",10,false,true)
genOneFile("../data/9.in",10,false,true)
genOneFile("../data/10.in",10,true,true)
genOneFile("../data/11.in",100000)
genOneFile("../data/12.in",100000)
genOneFile("../data/13.in",100000,false,true)
genOneFile("../data/14.in",100000,false,true)
genOneFile("../data/15.in",100000,false,true)
genOneFile("../data/16.in",100000,true)
genOneFile("../data/17.in",100000,true)
genOneFile("../data/18.in",100000,true)
genOneFile("../data/19.in",100000,true,true)
genOneFile("../data/20.in",100000,true,true)
