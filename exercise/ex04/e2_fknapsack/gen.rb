def genOneFile( filename, n, w = rand * n * 1000)
  File.open( filename,'w') do |file|
    file.puts "#{w} #{n}"
    file.puts n.times.map{ '%.2f' % (rand * 1000.0) }.join ' '
    file.puts n.times.map{ '%.2f' % (rand * 1000.0) }.join ' '
  end
end


genOneFile 'data/1.in',10,1000
genOneFile 'data/2.in',10,22.435
genOneFile 'data/3.in',100,1000
genOneFile 'data/4.in',100
genOneFile 'data/5.in',100000
genOneFile 'data/6.in',100000,1023824.123
