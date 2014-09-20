#!/usr/bin/env ruby

def lcs(s1,s2,store)
  s1l = s1.length
  s2l = s2.length
  return 0 if s1l == 0 or s2l == 0
  return store[s1l][s2l] if store[s1l][s2l] > -1
  return store[s1l][s2l] = lcs(s1.slice(0,s1l-1),s2.slice(0,s2l-1),store) + 1 if s1.last == s2.last
  return store[s1l][s2l] = [ lcs(s1.slice(0,s1l-1),s2,store),lcs(s1,s2.slice(0,s2l-1),store) ].max
end

n = gets.to_i
s1 = gets.split.map{ |x| x.to_i }
s2 = s1.sort
store = Array.new(n+1) { Array.new(n+1,-1) }
puts lcs(s1,s2,store)

