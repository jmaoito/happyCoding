/*************
  LeetCode anagrams

  Given an array of strings, return all groups of strings that are anagrams.

  Note: All inputs will be in lower-case.

  Discussion:
  
  Anagram means rearranging the letters of a word to produce a new word, using
  all the original letters exactly once.

  Sort each of the strings and use the sorted string as the key of a Hash map
  if one key has multiple values, they belong to one group of anagram.

  time complexity O(nmlogm) space compexity O(nm)
 *************/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > group;
        for (auto const &s : strs) {    // auto const & to avoid copy the string and does not change the original string.
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        vector<string> result;
        for (auto it = group.cbegin(); it != group.cend(); it++) {
            if (it->second.size() > 1)
                result.insert(result.end(), it->second.begin(), it->second.end());
        }
        return result;
    }
};
