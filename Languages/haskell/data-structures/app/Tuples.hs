module Tuples where

-- Tuples (fixed-size collections)
animalSounds :: [(String, String)]
animalSounds = [("cat", "meow"), ("dog", "woof"), ("cow", "moo")]

-- Fundamental Operations on Tuples
-- 1. Get the first element of a tuple
tupleFirst :: (Int, Int) -> Int
tupleFirst (x, _) = x

-- 3. Get the second element of a tuple
tupleSecond :: (Int, Int) -> Int
tupleSecond (_, y) = y

-- 4. Get the nth element of a tuple (1-based index | Pattern matching)
tupleNth :: Int -> (Int, Int) -> Int
tupleNth 1 (x, _) = x
tupleNth 2 (_, y) = y
tupleNth _ _ = error "Invalid index"

-- 5. Get the last element of a tuple
tupleLast :: (Int, Int) -> Int
tupleLast (_, y) = y

-- 6. Get the length of a tuple
tupleLength :: (Int, Int) -> Int
tupleLength (_, _) = 2

-- 7. Reverse a tuple
tupleReverse :: (Int, Int) -> (Int, Int)
tupleReverse (x, y) = (y, x)

-- 8. Check if a tuple is empty
tupleIsEmpty :: (Int, Int) -> Bool
tupleIsEmpty (_, _) = False

-- 9. Check if a tuple is not empty
tupleIsNotEmpty :: (Int, Int) -> Bool
tupleIsNotEmpty (_, _) = True
