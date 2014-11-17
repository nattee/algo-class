def genOneFile(filename,n,min = -1000,max = 1000,force = true)
  loop do
    File.open(filename,"w") do |f|
      f.puts n
      f.puts n.times.map{ rand(max - min + 1) + min }.join(" ")
    end

    system('ruby sol.rb',in:filename,out:'ver2.out')
    system('./main',in:filename,out:'ver1.out')
    a2 = File.readlines('ver2.out')
    a1 = File.readlines('ver1.out')
    puts "#{filename} a1 = #{a1[0].chomp} a2 = #{a2[0].chomp}"
    break unless force
    break if a1 != a2
    puts " not working..."
  end
end

genOneFile('data/1.in',10)
genOneFile('data/2.in',100,-1000,0,false)
genOneFile('data/3.in',500,0,100,false)
genOneFile('data/4.in',1000)
genOneFile('data/5.in',5000)
genOneFile('data/6.in',5000)
genOneFile('data/7.in',6000)
genOneFile('data/8.in',10000)
genOneFile('data/9.in',15000)
genOneFile('data/10.in',15000)
genOneFile('data/11.in',30000)
genOneFile('data/12.in',40010)
genOneFile('data/13.in',50000)
genOneFile('data/14.in',70000)
genOneFile('data/15.in',90000)
genOneFile('data/16.in',100000)
genOneFile('data/17.in',100000)
genOneFile('data/18.in',100000)
genOneFile('data/19.in',100000)
genOneFile('data/20.in',100000,0,1000,false)
