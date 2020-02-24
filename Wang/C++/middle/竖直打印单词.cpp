#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> printVertically(string s) {
    vector<string> res;
    if (s.size() == 0) {
      return res;
    }

    stringstream in(s);
    vector<string> words;
    string _word;
    int maxlen = 0;
    // 空格分词操作可以使用字符流
    while (in >> _word) {
      words.push_back(_word);
      maxlen = max(maxlen, (int)_word.size());
    }
    for (int i = 0; i < maxlen; ++i) {
      string concat;
      for (string& word : words) {
        concat += (i < word.size() ? word[i] : ' ');
      }
      while (concat.back() == ' ') {
        concat.pop_back();
      }
      res.push_back(concat);
    }
    return res;
  }
};