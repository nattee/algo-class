#!/usr/bin/env ruby
w_bag,n = gets.split.map{ |x| x.to_f }
n = n.to_i

v  = gets.split.map{ |x| x.to_f }
w  = gets.split.map{ |x| x.to_f }


items = Array.new(n)
n.times do |i|
  items[i] = [v[i]/w[i],v[i],w[i]]
end

items.sort!{ |a,b| b[0] <=> a[0] }
#n.times {|i| puts items[i][0] }
sum = 0
idx = 0
while (w_bag > 0) do
  if w_bag >= items[idx][2] then
    sum += items[idx][1]
    w_bag -= items[idx][2]
  else
    x = w_bag / items[idx][2]
    sum += x * items[idx][1]
    w_bag = 0
  end
  idx+=1
  break if idx >= n
end

printf "%.4f\n",sum
