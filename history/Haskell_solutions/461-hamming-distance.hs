module HammingDistance where

toBin :: Int -> [Int]
toBin 0 = []
toBin n = (n `mod` 2) : toBin (n `div` 2)

hammingDistance :: Int -> Int -> Int
hammingDistance x y = sum $ zipWith diff (rpad maxLen x') (rpad maxLen y')
  where
    diff x y = abs (x - y)
    x' = toBin x
    y' = toBin y
    maxLen = max (length x') (length y')

rpad :: Int -> [Int] -> [Int]
rpad n xs
  | n <= length xs = xs
  | otherwise      = take n . (++ repeat 0) $ xs
