#!/usr/bin/env ruby

#read input
n = gets.to_i
c = gets.split.map{ |x| x.to_i }

#create store
store = Array.new(n) { Array.new(2) } #store[i][0] = max customer from 0..i without using billboard #i
                                      #store[i][1] = max customer from 0..i using billboard #i

#process
store[0][0] = 0
store[0][1] = c[0]
(1..n-1).each do |i|
  store[i][0] = [ store[i-1][0], store[i-1][1] ].max
  store[i][1] = store[i-1][0] + c[i]
end
puts [ store[n-1][0], store[n-1][1] ].max


