#!/usr/bin/env ruby

a = [1,2,3,4,5]
b = [6,3,5,1,2]
x = 10

#debug: print the input
print "a = "
a.each { |i| print "#{i} " }
print "\nb = "
b.each { |i| print "#{i} " }
puts 

#instruction count
count = 0;

#we want to find i,j such that a[i] + b[j] = x
puts "Solutions:"
a.length.times do |i|
  b.length.times do |j|
    count = count + 1
    puts "a[#{i}] + b[#{j}] = #{x}" if a[i] + b[j] == x
  end
end


puts "Count = #{count}"
