def genOneFile( filename, n, max_v = 100,max_w=100)
  File.open filename, 'w' do |f|
    w = rand( * n * max_w * 1000)/1000.0
    f.puts "#{w} #{n}"
    items = n.times.map{ [ rand(1000 * max_v) / 1000.0, rand(1000 * max_w) / 1000.0] };
    items.sort!{ |a,b| (a[0]/a[1]) <=> (b[0]/b[1])}
    f.puts items.map{ |x| x[0]}.join ' '
    f.puts items.map{ |x| x[1]}.join ' '
  end
end


genOneFile('data/1.in',  10);
genOneFile('data/2.in',  20);
genOneFile('data/3.in',  30);
genOneFile('data/4.in',  30);
genOneFile('data/5.in',  30);
genOneFile('data/6.in',  100);
genOneFile('data/7.in',  100);
genOneFile('data/8.in',  100);
genOneFile('data/9.in',  100);
genOneFile('data/10.in', 100);
