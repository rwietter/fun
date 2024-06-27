{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use print" #-}
module Main where

-- Numbers
x :: Int
x = 1
intis :: Int -> Int
intis x = x + 1

y :: Double
y = 1.0
doubles :: Double -> Double
doubles x = x + 1.0

-- Characters
a :: Char
a = 'a'
chars :: Char -> Char
chars x = x

-- Strings
s :: String
s = "I'm a string"
strings :: String -> String
strings x = x ++ "!"

-- Booleans
b :: Bool
b = True
bools :: Bool -> Bool
bools x = do
  not x

main :: IO ()
main = do
  putStrLn $ show $ intis x
  putStrLn $ show $ doubles y
  putStrLn $ show $ chars a
  putStrLn $ show $ strings s
  putStrLn $ show $ bools b

