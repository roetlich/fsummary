MakeCommands = {}

for line in io.lines(file_path) do
    local command = string.match(line, "^(%a[%a|%p]*):")
    if command ~= nil then
        MakeCommands[#MakeCommands + 1] = command
    end
end

if #MakeCommands > 0 then
    io.write("Found ", #MakeCommands, " build make_commands:\n")
    for i = 1, #MakeCommands do
        io.write(MakeCommands[i], "\t")
    end
    io.write("\n")
else
    io.write("Couldn't find any build commands.\n")
end
