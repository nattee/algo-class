def gaa(n,size,idx)
  return n == 0 ? 'g' : 'a' if idx == 0
  return gaa(n,size,idx-1) if n < size[idx-1]
  n -= size[idx-1]
  mid_size = idx+3
  return n == 0 ? 'g' : 'a' if n < mid_size
  return gaa(n-mid_size,size,idx-1)

end


n = gets.chomp.to_i - 1


size = []
size << 3
idx = 0
while size.last < n
  idx+=1
  size << size.last * 2 + idx  + 3
end

puts gaa(n,size,idx)

