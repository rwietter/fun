module Main where

main :: IO ()
main = do
  putStrLn "What is your name?"
  name <- getLine
  putStrLn ("Hello, " ++ name ++ "!")

  createNewFile ("/IO.hs", "module IOStandard where\n\nmain :: IO ()\nmain = putStrLn " ++ "\"" ++ name ++ "\"")

  content <- readFileStorage "/home/rwietter/workspace/DataStructures/Languages/haskell/io/app/IO.hs"
  putStrLn content

-- Create a new file in the io directory called IO.hs
createNewFile :: (FilePath, String) -> IO ()
createNewFile (path, content) = do
  let directory = "/home/rwietter/workspace/DataStructures/Languages/haskell/io/app"
  let filePath = directory ++ path
  writeFile filePath content


-- Read a file
readFileStorage :: FilePath -> IO String
readFileStorage path = do
  content <- readFile path
  let fileContent = content ++ "\n\nThis is the new content"
  return fileContent
