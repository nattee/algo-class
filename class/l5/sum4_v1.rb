

def gen_data(v1,v2,v3,v4, n ) 
  n.times do |i| # this mean loops n times, where i start from 0 to n-1
    v1[i] = rand(n * 10)
    v2[i] = rand(n * 10)
    v3[i] = rand(n * 10)
    v4[i] = rand(n * 10)
  end
end


n = 10
x = n*100

v1 = []  # this create v1 as an array
v2 = []
v3 = []
v4 = []
gen_data(v1,v2,v3,v4,n);


found = false
v1.each do |a|
  v2.each do |b|
    v3.each do |c|
      v4.each do |d|
        if a+b+c+d == x then
          found = true
          break
        end
      end
      break if found
    end
    break if found
  end 
  break if found
end

puts found ? "YES" : "NO"

