#!/usr/bin/env ruby

n = gets.to_i
s1 = gets.split.map{ |x| x.to_i }
s2 = s1.sort
store = Array.new(n+1) { Array.new(n+1,0) }

(1..n).each do |i|
  (1..n).each do |j|
    if s1[i-1] == s2[j-1] then
      store[i][j] = store[i-1][j-1]+1
    else
      store[i][j] = [ store[i-1][j],store[i][j-1] ].max
    end
  end
end

puts store[n][n]

