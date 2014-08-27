
def gen_data(v1,v2,v3,v4, n ) 
  n.times do |i|
    v1[i], v2[i] ,v3[i], v4[i] = rand(n*10),rand(n*10),rand(n*10),rand(n*10)

    #or we can be shorter, using map 
    #v1[i], v2[i], v3[i], v4[i] = 4.times.map { rand(n * 10) }
  end

  #or much much shorter
  #v1, v2, v3, v4 = 4.times.map{ n.times.map{ rand(n*10) } }
end


n = 10
x = rand(n*10)

#we can use parallel assignment. This is easier to write
v1,v2,v3,v4 = [],[],[],[]
gen_data(v1,v2,v3,v4,n);


found = false

v12 = { } #hash is built-in data structure of ruby
v1.each do |a|
  v2.each do |b|
    v12[a+b] = true
  end
end

v3.each do |a|
  v4.each do |b|
    req = x - a - b
    if v12.has_key?(req) then
      found = true
      break
    end
  end
  break if found
end

puts found ? "YES" : "NO"

