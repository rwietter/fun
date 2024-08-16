module Main where

size :: Integer
size = 12 + 12

square :: Integer -> Integer
square n = n * n

double :: Integer -> Integer
double n = 2* n

example :: Integer
example = double (size - square(2+2))

main :: IO ()
main = do
  print example
