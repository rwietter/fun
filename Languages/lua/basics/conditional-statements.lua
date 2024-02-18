--[[
  - == equals
  - ~= not equals
  - < less than
  - > greater than
  - <= less than or equal to
  - >= greater than or equal to
  - and
  - or
  - not
]]

local age = 18

-- if statement
if age > 18 then
  print("You are an adult")
end

-- if else statement
if age > 18 then
  print("You are an adult")
else
  print("You are a child")
end

-- if elseif else statement
if age > 18 then
  print("You are a young adult")
elseif age <= 30 then
  print("You are a adult")
else
  print("You are a child")
end

-- Boolean logic
local isMale = true

-- And operator
if age > 18 and isMale then
  print("You are a adult")
end

-- Or operator
if age > 18 or isMale then
  print("You are a adult")
end

-- String comparison
local name = "John"

if name ~= "John" then
  print("You are not John")
elseif name == "John" then
  print("You are John")
end
