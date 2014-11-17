def genOneFile(filename,n,max = 1000)
  puts "gen #{filename}"
  File.open(filename,'w') do |f|
    f.puts n
    (n-1).times do |i|
      f.puts (n - i - 1).times.map{ rand(max) }.join ' '
    end
  end
end


genOneFile('data/1.in',10);
genOneFile('data/2.in',30);
genOneFile('data/3.in',50);
genOneFile('data/4.in',100);
genOneFile('data/5.in',200);
genOneFile('data/6.in',300);
genOneFile('data/7.in',400);
genOneFile('data/8.in',500, 2);
genOneFile('data/9.in',700, 1);
genOneFile('data/10.in',1000);
