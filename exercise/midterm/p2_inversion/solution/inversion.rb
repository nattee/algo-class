n = gets.chomp.to_i
a = gets.split.map{ |x| x.to_i}

def merge(a,l,r)
  return 0 if l == r
  mid = (l+r)/2
  res = merge(a,l,mid) + merge(a,mid+1,r)
  sorted = []
  #merge
  li = l
  ri = mid+1

  until li > mid or ri > r
    if a[li] <= a[ri]
      sorted << a[li]
      li+=1
    else
      sorted << a[ri]
      ri+=1
      res += (mid - li + 1)
    end
  end
  (li..mid).each {|i| sorted << a[i]}
  (ri..r).each {|i| sorted << a[i]}
  a[l..r] = sorted

  return res
end



puts merge(a,0,n-1)
