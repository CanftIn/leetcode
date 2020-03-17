twoSum :: [Int] -> Int -> (Int, Int)
twoSum numbers target = [(x, y) | x <- r, y <- r, x < y && numbers !! x + numbers !! y == target] !! 0
  where r = [0..length numbers - 1]
