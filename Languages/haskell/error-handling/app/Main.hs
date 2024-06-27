module Main where

-- 1. Maybe Monad (Just, Nothing)
data User = User { name :: String, age :: Int } deriving Show
findUser :: String -> Maybe User
findUser "Alice" = Just $ User "Alice's name" 25
findUser _ = Nothing

-- 2. Either Monad (Left, Right)
data Error = NotFound | InvalidInput deriving Show
findUser' :: String -> Either Error User
findUser' "Alice" = Right $ User "Alice's name" 25
findUser' _ = Left NotFound


main :: IO ()
main = do
  putStrLn "Error handling in Haskell"

  -- 1. Maybe Monad
  let user = findUser "Alice"
  case user of
    Just u -> putStrLn $ "User found: " ++ show u
    Nothing -> putStrLn "User not found"

  -- 2. Either Monad
  let user' = findUser' "Alice"
  case user' of
    Right u -> putStrLn $ "User found: " ++ show u
    Left NotFound -> putStrLn "User not found"
    Left InvalidInput -> putStrLn "Invalid input"
