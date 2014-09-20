#!/usr/bin/env ruby

def lcs(s1,s2)
  return 0 if s1.length == 0 or s2.length == 0
  return lcs(s1.slice(0,s1.length-1),s2.slice(0,s2.length-1)) + 1 if s1.last == s2.last
  return [ lcs(s1.slice(0,s1.length-1),s2),lcs(s1,s2.slice(0,s2.length-1)) ].max
end

n = gets.to_i
s1 = gets.split.map{ |x| x.to_i }
s2 = s1.sort
puts lcs(s1,s2)

