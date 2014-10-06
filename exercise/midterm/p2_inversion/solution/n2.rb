n = gets.chomp.to_i
a = gets.split.map{ |x| x.to_i}

count = 0
n.times do |i|
  (i+1..n-1).each do |j|
    count += 1 if a[i] > a[j] 
  end
end
puts count

