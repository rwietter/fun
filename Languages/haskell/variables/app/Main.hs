{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant bracket" #-}
module Main where
import System.Info (os, arch, compilerName)

-- Variables are immutable in Haskell
-- Variables are declared with the `let` keyword
-- For global variables, use the `where` keyword

-- global variable
x :: Int
x = 1

-- Pars
osInfoList :: [(String, String)]
osInfoList =
  [ ("Operating system", os)
  , ("Architecture", arch)
  , ("Compiler name", compilerName)
  ]

-- global function
osInfo :: String
osInfo = do
  "The operating system is: " ++ os ++ "\n" ++ "The architecture is: " ++ arch ++ "\n" ++ "The compiler name is: " ++ compilerName ++ "\n"

-- Format
formatInfo :: [(String, String)] -> String
formatInfo [] = ""
formatInfo ((key, value):xs) = key ++ ": " ++ value ++ "\n" ++ formatInfo xs

main :: IO ()
main = putStrLn $ formatInfo osInfoList
