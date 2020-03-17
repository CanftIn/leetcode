#include <iostream>

/*
int sqrt(int x) {

    if (x <=0 ) return 0;
    
    //the sqrt is not greater than x/2+1
    int e = x/2+1;
    int s = 0;
    // binary search
    while ( s <= e ) {
        int mid = s + (e-s)/2;
        long long sq = (long long)mid*(long long)mid;
        if (sq == x ) return mid;
        if (sq < x) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return e; 
        
}

*/

class Solution {
public:
	//http://en.wikipedia.org/wiki/Newton%27s_method
	int mySqrt(int x) {
		if (x <= 0)
		{
			return -1;
		}
		else
		{
			long long a = x;
			while (a * a > x)
			{
				a = (a + x / a) / 2;
			}
			return a;
		}
	}
};

int main()
{
	Solution solution;
	std::cout << solution.mySqrt(16) << std::endl;
	std::cout << solution.mySqrt(8) << std::endl;
	std::cout << solution.mySqrt(9) << std::endl;
	std::cout << solution.mySqrt(4) << std::endl;
	std::cout << solution.mySqrt(1) << std::endl;
	std::cout << solution.mySqrt(-3) << std::endl;
	std::cout << solution.mySqrt(6) << std::endl;
	std::cout << solution.mySqrt(12) << std::endl; 
	std::cout << solution.mySqrt(25) << std::endl;
	std::cout << solution.mySqrt(46339) << std::endl;
	std::cout << solution.mySqrt(65530) << std::endl;
	return 0;
}