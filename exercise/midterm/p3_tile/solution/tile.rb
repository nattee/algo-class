n,m = gets.split.map{ |x| x.to_i}
a = []
n.times { a << gets.chomp.to_i }

FIXNUM_MAX = (2**(0.size * 8 -2) -1)
best = Array.new(n+1) { Array.new(m+1,FIXNUM_MAX) }
best[0][0] = 0

(1..n).each do |i|
  (1..m).each do |j|
    k = 1
    while k*k <= j
      t1 = (a[i-1]-k)**2 + best[i-1][j-k*k] 
      best[i][j] = t1 if t1 < best[i][j]
      k+=1
    end
  end
end

puts best[n][m] == FIXNUM_MAX ? -1 : best[n][m];
