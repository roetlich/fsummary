print("hi! :)")
print(file_path)

for line in io.lines(file_path) do 
    lines[#lines + 1] = line
  end