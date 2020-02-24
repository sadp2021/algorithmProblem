#include <string>

using namespace std;

class Solution {
 public:
  string breakPalindrome(string palindrome) {
    if (palindrome.size() == 1 || palindrome.size() == 0) {
      return "";
    }
    int len = palindrome.size();
    if (len % 2 == 0) {
      len /= 2;
    } else {
      len = (len - 1) / 2;
    }

    for (int i = 0; i < len; ++i) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome[palindrome.size() - 1] = 'b';
    return palindrome;
  }
};