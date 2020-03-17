class Solution {
public:
  int hammingDistance(int x, int y) {
    int distance = 0;
    bool fx, fy;
    while (!(x == 0 && y == 0)) {
      fx = x & 1;
      fy = y & 1;
      x >>= 1;
      y >>= 1;
      distance += (fx != fy);
    }
    return distance;
  }
};
