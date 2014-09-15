def fibo( n )
  @store[0] = 0;
  @store[1] = 1;

  (2..n).each do |i|
    @store[i] = @store[i-1] + @store[i-2]
  end
end


n = gets.chomp.to_i


@count = 0
@store = Array.new(n+1,-1)
result = fibo( n )
puts "result = #{result} count = #{@count}"
