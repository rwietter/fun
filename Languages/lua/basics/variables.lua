local x = 10
local name = "sally"
local isActive = true
local age = nil

-- increment x by 1
x = x + 1

-- strings
local phrase = name .. " is " .. x .. " years old"
print(phrase)

-- booleans
if isActive then
  print(name .. " is active")
else
  print(name .. " is not active")
end

-- nil
if age == nil then
  print(name .. " does not have an age")
else
  print(name .. " is " .. age .. " years old")
end
