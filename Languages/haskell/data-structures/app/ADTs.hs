module ADTs where

-- Algebraic data types (ADTs) - custom data types
data Shape = Circle Float -- Radius
            | Rectangle Float Float -- Width and height
            | Triangle Float Float Float -- Sides
            deriving (Show)

shapes :: [Shape]
shapes = [Circle 10, Rectangle 5 10, Triangle 3 4 5]

-- Fundamental Operations on Algebraic Data Types
-- 1. Get the area of a shape
shapeArea :: Shape -> Float
shapeArea (Circle r) = pi * r * r
shapeArea (Rectangle w h) = w * h
shapeArea (Triangle a b c) = sqrt (s * (s - a) * (s - b) * (s - c))
  where s = (a + b + c) / 2

-- 2. Using ADTs with pattern matching
shapeName :: Shape -> String
shapeName (Circle _) = "Circle"
shapeName (Rectangle _ _) = "Rectangle"
shapeName (Triangle {}) = "Triangle"
