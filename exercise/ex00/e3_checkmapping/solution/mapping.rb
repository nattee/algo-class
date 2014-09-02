n = gets.chomp.to_i
s = gets.split.map { |x| x.to_i }

num = Array.new(n+1,0)
n.times do |i|
  if s[i] < 1 or s[i] > n or num[s[i]] == 1
    puts "NO"
    exit
  end
  num[s[i]] += 1
end


puts "YES"
