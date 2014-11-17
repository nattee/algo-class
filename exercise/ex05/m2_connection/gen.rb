def genOneFile( filename, n, e = n * 2 )
  puts "generating #{filename}"
  File.open filename, 'w' do |f|
    k = rand(4) + 1
    f.puts "#{n} #{e} #{k}"
    edge = Array.new(n){ Array.new(n,false) }
    e.times do
      loop do
        a = rand(n)
        b = rand(n)
        a,b = [ [a,b].min , [a,b].max]
        next if a == b or edge[a][b]
        edge[a][b] = true
        f.puts "#{a} #{b}"
        break
      end
    end
  end
end


genOneFile('data/1.in',10)
genOneFile('data/2.in',20)
genOneFile('data/3.in',50)
genOneFile('data/4.in',60)
genOneFile('data/5.in',90)
genOneFile('data/6.in',100)
genOneFile('data/7.in',300)
genOneFile('data/8.in',500)
genOneFile('data/9.in',800)
genOneFile('data/10.in',1000)
