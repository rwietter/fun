module Main where
import Lists
import Tuples
import ADTs

main :: IO ()
main = do
  print ("Lists: ", pipelineProcessorOperations)
  print ("Tuples: ", animalSounds)
  let shapesResult = map shapeArea shapes
  print ("Algebraic data types: ", shapesResult)

  -- Lists
  print ("reversedList: ", reversedList)

  -- Tuples
  let myTuple = (1, 2)
  let tupleFirstResult = tupleFirst myTuple
  putStrLn ("tupleFirst: " ++ show tupleFirstResult)

