def genOneFile( filename, t, max_n )
  puts "generating #{filename}"
  File.open filename, 'w' do |f|
    f.puts t
    t.times do
      n = rand(max_n) + 1
      e = rand(n * 1.5)
      f.puts "#{n} #{e}"
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
end


genOneFile('data/1.in', 5, 10)
genOneFile('data/2.in', 10,20)
genOneFile('data/3.in', 10,50)
genOneFile('data/4.in', 10,60)
genOneFile('data/5.in', 10,90)
genOneFile('data/6.in', 10,100)
genOneFile('data/7.in', 10,300)
genOneFile('data/8.in', 10,500)
genOneFile('data/9.in', 10,800)
genOneFile('data/10.in', 10,1000)
