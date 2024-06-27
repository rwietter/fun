module Lists where

-- Lists (collections of values)
pipelineProcessorOperations :: [String]
pipelineProcessorOperations = [
    "fetch",
    "decode",
    "execute",
    "memory",
    "writeback"
  ]


-- 1. Concatenation
concatenatedList :: [Int]
concatenatedList = [1, 2, 3] ++ [4, 5, 6]

-- 2. Indexing
firstElement :: Int
firstElement = head concatenatedList

-- 3. Length
listLength :: Int
listLength = length concatenatedList

-- 4. Reverse
reversedList :: [Int]
reversedList = reverse concatenatedList

-- 5. Check if empty
isEmpty :: Bool
isEmpty = null concatenatedList

-- 6. Get element by index
thirdElement :: Int
thirdElement = concatenatedList !! 2

-- 7. Take
firstThreeElements :: [Int]
firstThreeElements = take 3 concatenatedList

-- 8. Drop
droppedFirstThreeElements :: [Int]
droppedFirstThreeElements = drop 3 concatenatedList

-- 9. Maximum
maxElement :: Int
maxElement = maximum concatenatedList

-- 10. Minimum
minElement :: Int
minElement = minimum concatenatedList

-- 11. Sum
sumOfElements :: Int
sumOfElements = sum concatenatedList

-- 12. Product
productOfElements :: Int
productOfElements = product concatenatedList

-- 13. Check if element is in list
isElementInList :: Bool
isElementInList = 3 `elem` concatenatedList

-- 14. List comprehension (create a list of squares of numbers from 1 to 10)
squares :: [Int]
squares = [x * x | x <- [1..10]]

-- 15. List comprehension with condition (create a list of squares of even numbers from 1 to 10)
squaresOfEvenNumbers :: [Int]
squaresOfEvenNumbers = [x * x | x <- [1..10], even x]

-- 16. List comprehension with multiple lists (create a list of products of two lists)
productsOfLists :: [Int]
productsOfLists = [x * y | x <- [1..3], y <- [4..6]]

-- 17. List comprehension with multiple lists and condition (create a list of products of two lists where the product is greater than 10)
productsOfListsGreaterThanTen :: [Int]
productsOfListsGreaterThanTen = [x * y | x <- [1..3], y <- [4..6], x * y > 10]

-- 18. Filter and map
squaresOfEvenNumbers' :: [Int]
squaresOfEvenNumbers' = map (^2) (filter even [1..10])
