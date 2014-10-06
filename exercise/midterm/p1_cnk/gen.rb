def genOneFile(filename, n)
  File.open(filename,"w") do |file|
    k = rand(n-1)+1
    file.puts "#{n} #{k}"
  end
end

genOneFile('data/1.in',10);
genOneFile('data/2.in',10);
genOneFile('data/3.in',10);
genOneFile('data/4.in',20);
genOneFile('data/5.in',25);
genOneFile('data/6.in',30);
genOneFile('data/7.in',30);
genOneFile('data/8.in',30);
