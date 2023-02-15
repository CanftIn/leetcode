public class test {
	public static void main(String[] args) {
        System.out.println(longestPalindrome1("cbba"));
    }
    public static String longestPalindrome1(String s) {
        int maxPalinLength = 0;
        String longestPalindrome = null;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                int len = j - i;
                String curr = s.substring(i, j+1);
                if (isRalindrome(curr)) {
                    if (len > maxPalinLength) {
                        longestPalindrome = curr;
                        maxPalinLength = len;
                    }
                }
            }
        }
        return longestPalindrome;
    }
    public static boolean isRalindrome(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}