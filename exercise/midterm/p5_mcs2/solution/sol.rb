def solve(a,n,sl,sr,l,r)
  return a[l] if (l == r)
  m = (l+r)/2;
  max_rin = a[m+1]
  max_lin = a[m]
  a[l..m].reverse.inject(0){|sum,i| max_lin = [max_lin,sum+i].max; sum + i;}
  a[m+1..r].inject(0){|sum,i| max_rin = [max_rin,sum+i].max; sum + i;}

  [ solve(a,n,sl,sr,l,m),
    solve(a,n,sl,sr,m+1,r),
    max_rin + max_lin,
    sl[l..m].max + sr[m+1..r].max
  ].max
end

n = gets.to_i
a = gets.split.map{ |x| x.to_i}

sl,sr = [],[]
a.inject(0){ |sum,i| sl << (sum+i); sum + i;}
a.reverse.inject(0){ |sum,i| sr << (sum + i); sum+i;}
sr.reverse!

puts [solve(a,n,sl,sr,0,n-1), a.reduce(:+)].max
