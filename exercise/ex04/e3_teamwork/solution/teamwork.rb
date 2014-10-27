#!/usr/bin/env ruby
n,m = gets.split.map{ |x| x.to_i }
j = gets.split.map{ |x| x.to_i}.sort
idx = 0
t = Array.new(n,0)
c = Array.new(n,0)

j.each do |v|
  t[idx] += v + c[idx]
  c[idx] += v
  idx+=1
  idx = 0 if idx == n
end


printf "%.3f\n",t.inject(:+).to_f / m
