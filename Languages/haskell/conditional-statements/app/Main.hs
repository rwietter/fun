{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant if" #-}
module Main where

-- Pattern matching
isEven :: Int -> Bool
isEven 0 = True
isEven n = isEven (n - 2)

-- Guards
isEven' :: Int -> Bool
isEven' n
  | n == 0 = True
  | otherwise = isEven' (n - 2)

describeNumber :: Int -> String
describeNumber n
  | n < 0 = "Negative"
  | n == 0 = "Zero"
  | otherwise = "Positive"

-- if-then-else
isOdd :: Int -> Bool
isOdd 0 = False
isOdd n = if n == 0 then False else isOdd (n - 1)

-- case
linuxOs :: String -> String
linuxOs os = case os of
  "ubuntu" -> "Debian"
  "fedora" -> "Red Hat"
  "arch" -> "Arch Linux"
  _ -> "Unknown"


main :: IO ()
main = do
  print $ isEven 4
  print $ isEven' 4
  print $ describeNumber 4
  print $ isOdd 4
  print $ linuxOs "ubuntu"
  print $ linuxOs "windows"
