class Solution {
 public:
  void replaceSpace(char* str, int length) {
    int i = 0;
    char* s = str;
    int l = 0;
    while (*s != '\0') {
      l++;
      if (*s == ' ')
        i++;
      s += 1;
    }
    int maxl = l + i * 2;
    char* p = str + maxl;
    while (p != s) {
      if (*s == ' ') {
        *p-- = '0';
        *p-- = '2';
        *p-- = '%';
        s--;
      } else {
        *p-- = *s--;
      }
    }
  }
};
