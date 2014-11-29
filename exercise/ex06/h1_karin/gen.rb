def genOneFile( filename, n, k, max = 1000)
  puts "gen #{filename}"
  File.open filename,'w' do |f|
    f.puts "#{n} #{k} #{rand(k)}"
    k.times do
      f.puts [1+rand(max/10),1+rand(max/10),max/2 + rand(max/2),max/2 + rand(max/2),max/2 + rand(max/2)].join ' '
    end
  end
end


genOneFile('data/1.in' ,10               , 5)
genOneFile('data/2.in' ,100              , 30)
genOneFile('data/3.in' ,1000             , 5)
genOneFile('data/4.in' ,10000            , 30)
genOneFile('data/5.in' ,100000           , 5)
genOneFile('data/6.in' ,1000000          , 30)
genOneFile('data/7.in' ,10000000         , 5)
genOneFile('data/8.in' ,100000000        , 30)
genOneFile('data/9.in' ,1000000000       , 5)
genOneFile('data/10.in',1000000000       , 30)
