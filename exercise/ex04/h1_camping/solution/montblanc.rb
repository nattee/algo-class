VERY_LARGE = 4000_000_000
n,d = gets.split.map{ |x| x.to_i}
camp = gets.split.map{ |x| x.to_i}
#d = 3
#camp = [10,30,50,70,90,110,140,170,180]

max_dist = 0
(0...camp.size-1).each do |i|
  max_dist = [max_dist,camp[i+1]-camp[i]].max
end

def days(k,camp,max_dist)
  return VERY_LARGE if k < max_dist
  sum = 0
  last = 0
  day = 0
  prev = 0
  camp.each do |c|
    if (c - last >= k) then
      day += 1
      prev = c if (c - last == k) 
      #puts "stop at #{prev}"
      last = prev
    end
    prev = c
  end
  day += 1 if last != camp.last
  return day
end

#binary search
min = max_dist
max = VERY_LARGE
loop do
  k = (max + min) / 2
  ans = days(k,camp,max_dist)
  #puts "at k = #{k} ans = #{ans} minmax = #{[min,max]}"
  min = k+1 if ans > d
  max = k if ans <= d
  break if min >= max
end
puts "#{max} #{days(max,camp,max_dist)}"
