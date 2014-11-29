a = [5, 10, 15, 20, 25, 30, 35, 40, 50, 60]

10.times { |i| File.write("data/#{i+1}.in","#{a[i]}\n") }
