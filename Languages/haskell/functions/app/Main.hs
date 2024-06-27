{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use print" #-}
{-# HLINT ignore "Eta reduce" #-}
module Main where

-- ==================================== --
-- Functions as First-Class Citizens
-- ==================================== --
-- functions are teated like any other value
add :: Int -> Int -> Int
add x y = x + y

multiply :: Int -> Int -> Int
multiply x y = x * y

compose :: (Int -> Int -> Int) -> (Int -> Int -> Int) -> Int -> Int -> Int
compose f g x y = f x (g x y)

-- ==================================== --
-- Pipeline
-- ==================================== --

double :: Int -> Int
double x = x * 2

addOne :: Int -> Int
addOne x = x + 1

square :: Int -> Int
square x = x * x

pipeline :: Int -> Int
pipeline = square . addOne . double

-- ==================================== --
-- Recursion
-- ==================================== --
fact :: Int -> Int
fact 0 = 1
fact n = n * fact (n - 1)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

-- ==================================== --
-- Higher-Order Functions
-- ==================================== --
-- functions that take functions as arguments or return functions
-- map, filter, foldr, foldl, etc.
doubleAll :: [Int] -> [Int]
doubleAll x = map(*2) x -- map (* 2)


main :: IO ()
main = do
  let result = compose add multiply 2 2
  putStrLn $ show result

  let pipelineResult = pipeline 2
  putStrLn $ show pipelineResult

  let factResult = fact 5
  putStrLn $ show factResult

  let fibResult = fib 15
  putStrLn $ show fibResult

  let doubleAllResult = doubleAll [1, 2, 3, 4, 5]
  putStrLn $ show doubleAllResult

