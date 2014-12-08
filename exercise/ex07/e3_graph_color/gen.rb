def genOneFile(filename, n, e = rand(n*(n-1)/2) )
  File.open filename,'w' do |f|
    f.puts "#{n} #{e}"
    edge = []
    n.times do |i|
      ((i+1)...n).each do |j|
        edge << [i,j]
      end
    end
    edge.shuffle[0...e].each do |x|
      f.puts x.join ' '
    end
  end
end


genOneFile 'data/1.in',4,6
genOneFile 'data/2.in',15,0
genOneFile 'data/3.in',15
genOneFile 'data/4.in',15
genOneFile 'data/5.in',15
genOneFile 'data/6.in',15
genOneFile 'data/7.in',15
genOneFile 'data/8.in',15
genOneFile 'data/9.in',15
genOneFile 'data/10.in',15
