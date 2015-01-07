/*****************
  LeetCode Compare Version Numbers

  Compare two version numbers version1 and version1.
  If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

  You may assume that the version strings are non-empty and contain only digits and the . character.
  The . character does not represent a decimal point and is used to separate number sequences.
  For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

  Here is an example of version numbers ordering:

  0.1 < 1.1 < 1.2 < 13.37


*******************/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        size_t start = 0;
        int val1, val2;
        size_t pos1 = version1.find('.');
        while (pos1 != string::npos) {
            val1 = atoi(version1.substr(start, pos1).c_str());
            ver1.push_back(val1);
            start = pos1 + 1;
            pos1 = version1.find('.', start);
        }
        val1 = atoi(version1.substr(start).c_str());
        ver1.push_back(val1);
        start = 0;
        size_t pos2 = version2.find('.');
        while (pos2 != string::npos) {
            val2 = atoi(version2.substr(start, pos2).c_str());
            ver2.push_back(val2);
            start = pos2 + 1;
            pos2 = version2.find('.', start);
        }
        val2 = atoi(version2.substr(start).c_str());
        ver2.push_back(val2);
        
        for (int i=0; i<max(ver1.size(),ver2.size()); i++) {
            if (i < ver1.size()) val1 = ver1[i];
            else val1 = 0;
            if (i < ver2.size()) val2 = ver2[i];
            else val2 = 0;
            if (val1 > val2) return 1;
            else if (val1 < val2) return -1;
            else continue;
        }
        return 0;
    }
};
