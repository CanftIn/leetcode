class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N = haystack.size() - needle.size() + 1;
        int M = needle.length();
        for (int i = 0; i < N; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                } 
            }
            if (j == M) return i;//匹配成功
        }
        return -1;//匹配失败
    }
};