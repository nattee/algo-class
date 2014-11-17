#!/usr/bin/env ruby

def denom( m, idx, d, store)
  if (idx == 0)
    return m / d[0] if  m % d[0] == 0
    puts "ERROR, the smallest denominator is not 1"
  end
  orig = m
  return store[orig][idx] if store[orig][idx] > -1
  min = denom(m,idx-1,d,store)
  count = 1
  while (m >= d[idx])
    result = denom(m - d[idx],idx-1,d,store) + count
    min = result if result < min
    m -= d[idx]
    count += 1
  end
  return store[orig][idx] = min
end


n,m = gets.chomp.split.map{ |x| x.to_i }
d = gets.chomp.split.map{ |x| x.to_i }
d.reverse!
store = Array.new(m+1) { Array.new(n,-1) }
puts denom(m,n-1,d, store)
