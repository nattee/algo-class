def insertionSortDivideAndConquer( d )
  # recursion
  a = d[0..d.length-2]
  a = insertionSortDivideAndConquer( a )

  # insert
  t = d[-1]
  j = d.length-1;
  while (j >= 0)
    if (t > d[j]) break;

  end
  
end
