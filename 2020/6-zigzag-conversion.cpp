string convert(string s, int numRows) {
  if (numRows == 1)
    return s;

  int oneCycle = 2 * numRows - 2;
  int stringSize = s.length();
  int midLineDistance = 0;
  int index = 0;
  string ret;

  for (int i = 0; i < numRows; i++)
  {
    index = i;
    midLineDistance = i * 2;
    while (index < stringSize)
    {
      ret += s[index];
      midLineDistance = oneCycle - midLineDistance;
      index += (i == 0 || i == numRows-1) ? oneCycle : midLineDistance;
    }
  }
  return ret;
}
