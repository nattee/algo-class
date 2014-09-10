def genOneFile( filename, n, max = 1_999_999_999)
  File.open(filename,"w") do |file|
    file.puts n
    file.puts n.times.map{ rand(max) + 1 }.join("\n")
  end
end


genOneFile('data/1.in',3,20);
genOneFile('data/2.in',10,20);
genOneFile('data/3.in',100,2000);
genOneFile('data/4.in',20,2_000_000);
genOneFile('data/5.in',300,20_000_000);
genOneFile('data/6.in',500);
genOneFile('data/7.in',800);
genOneFile('data/8.in',1000);
genOneFile('data/9.in',1000);
genOneFile('data/10.in',1000);
