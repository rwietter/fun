local t = {
  { str = 42, dex = 10, wis = 100 },
  { str = 18, dex = 30, wis = 5 },
}

local first = t[1] -- arrays are 1-indexed
print("First: ", first.str, first.dex, first.wis) -- 42 10 100

-- #colors is the length of the array
for i = 1, #t do
  print("for lenth: ", t[i].str, t[i].dex, t[i].wis)
end

-- ipairs returns the index and value of each element
for i, v in ipairs(t) do
  print("Ipairs: ", i, v.str, v.dex, v.wis)
end

-- table.insert adds an element to the end of the array
table.insert(t, { str = 100, dex = 100, wis = 100 })

-- table.remove removes an element from the array
table.remove(t, 3)

-- table.concat concatenates the elements of an array
-- local table2 = table.concat(t, ",")

-- table.sort sorts the elements of an array
table.sort(t, function(k1, k2)
  return k1.str < k2.str
end)
print("Sorted by str:", t[1].str, t[2].str)

-- ignore the index by using _
for _, v in ipairs(t) do
  print("Ignore index", v.str)
end
