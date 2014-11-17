n,k = gets.chomp.split.map{|x| x.to_i}

c = Array.new(n+1) { Array.new(k+1) }
n.times do |i|
  i+=1
  c[i][0] = c[i][i] = 1
  (1..i-1).each do |j|
    c[i][j] = c[i-1][j] + c[i-1][j-1]
  end
end
puts c[n][k]
