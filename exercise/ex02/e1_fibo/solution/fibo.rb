#!/usr/bin/env ruby
#!/usr/bin/env ruby

def fibo(n)
  return n unless n >= 2
  a = 0
  b = 1
  n.downto(2) { |i|
    #puts i
    c = a + b
    a = b
    b = c
  }
  return b
end

a = gets.to_i
puts fibo a
