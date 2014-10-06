#!/usr/bin/env ruby

#input
r,c = gets.split.map{ |x| x.to_i}
grid = Array.new(r)
r.times { |i| grid[i] = gets.chomp.each_char.map{ |x| x.to_i } }

#create store
store = Array.new(r)
r.times { |i| store[i] = grid[i].clone }

#process
max = 0
(1..r-1).each do |i|
  (1..c-1).each do |j|
    if grid[i][j] == 1
      store[i][j] = [ store[i-1][j], store[i-1][j-1], store[i][j-1] ].min + 1
    end
    max = store[i][j] if store[i][j] > max
  end
end

puts max
