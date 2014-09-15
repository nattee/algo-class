def fibo( n )
  @count += 1
  return @store[n] if @store[n] >-1
  puts "call with n = #{n}"
  return n if n <= 1
  @store[n] = fibo(n - 1) + fibo( n - 2)
  return @store[n]
end


n = gets.chomp.to_i


@count = 0
@store = Array.new(n+1,-1)
result = fibo( n )
puts "result = #{result} count = #{@count}"
