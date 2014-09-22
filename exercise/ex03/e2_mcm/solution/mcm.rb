n = gets.chomp.to_i
a = gets.split.map{ |x| x.to_i }

#init best array
m = Array.new(n){ Array.new(n,0) } #m[i][j] = the min cost of multiplying m[i]...m[j]
n.times { |i| m[i][i] = 0 }

(1..n-1).each do |i|
  (0..(n-i-1)).each do |j|
    #calculating best value for m[j][i+j]
    #print "calculating m[#{j}][#{j+i}]"
    min = m[j+1][i+j] + a[j] * a[j+1] * a[i+j+1]
    (j..(i+j-1)).each do |k|
      cost_here = m[j][k] + m[k+1][i+j] + a[j] * a[k+1] * a[i+j+1]
      min = cost_here if cost_here < min
    end
    m[j][i+j] = min
    #puts " = #{min}"
  end
end

#(0..n-1).each do |i|
#  (0..n-1).each do |j|
#    print "#{m[i][j]} "
#  end
#  puts
#end

puts m[0][n-1]

