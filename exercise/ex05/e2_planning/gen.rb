def genOneFile( filename, n )
  puts "generating #{filename}"
  File.open filename, 'w' do |f|
    f.puts n
    #gen the graph
    req = Array.new(n){ [] }
    perm = (0...n).to_a.shuffle
    inv = Array.new(n){ 0 }
    (0...n).each { |i| inv[perm[i]] = i }
    (1...n).each do |i|
      rand(i).times do
        req[i] << rand(i)
      end
      req[i].uniq!
    end


    n.times do |i|
      f.puts "#{req[inv[i]].size} #{req[inv[i]].map{ |x| perm[x] }.join ' '}"
    end
  end
end


genOneFile('data/1.in', 10)
genOneFile('data/2.in', 20)
genOneFile('data/3.in', 50)
genOneFile('data/4.in', 60)
genOneFile('data/5.in', 90)
genOneFile('data/6.in', 100)
genOneFile('data/7.in', 300)
genOneFile('data/8.in', 500)
genOneFile('data/9.in', 800)
genOneFile('data/10.in', 1000)
