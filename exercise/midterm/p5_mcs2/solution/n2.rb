n = gets.to_i
a = gets.split.map{ |x| x.to_i}

max = a[0]
all = a.inject(:+)
n.times do |i|
  a[i..n-1].inject(0) { |sum,i| max = [max,sum+i,all-(sum+i)].max; sum+i;}
end
tmp = a.max
max = tmp if max == 0 and tmp < 0
puts max
