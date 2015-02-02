/*******************************
  LeetCode Permutations II 
  
  Given a collection of numbers that might contain duplicates, return all 
  possible unique permutations.

  For example,
  [1,1,2] have the following unique permutations:
  [1,1,2], [1,2,1], and [2,1,1].

  Tags: Backtracking

  Discussion: calling nextPermutation(), see permutations I

  implement a recursive function. the length of intermediate result p can be 
  used to judge the convergence.

  time complexity O(n!), space complexity O(n);
***********************/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        unordered_map<int, int> count_map; // 记录每个元素的出现次数
        for_each(num.begin(), num.end(), [&count_map](int e) {
            if (count_map.find(e) != count_map.end())
                count_map[e]++;
            else
                count_map[e] = 1;
        });
        // 将 map 里的 pair 拷贝到一个 vector 里
        vector<pair<int, int> > elems;
        for_each(count_map.begin(), count_map.end(),
                [&elems](const pair<int, int> &e) {
            elems.push_back(e);
        });
        vector<vector<int>> result; // 最终结果
        vector<int> p; // 中间结果
        n = num.size();
        permute(elems.begin(), elems.end(), p, result);
        return result;
    }
private:
    size_t n;
    typedef vector<pair<int, int> >::const_iterator Iter;
    void permute(Iter first, Iter last, vector<int> &p,
                    vector<vector<int> > &result) {
        if (n == p.size()) { // 收敛条件
            result.push_back(p);
        }
        // 扩展状态
        for (auto i = first; i != last; i++) {
            int count = 0; // 统计 *i 在 p 中出现过多少次
            for (auto j = p.begin(); j != p.end(); j++) {
                if (i->first == *j) {
                    count ++;
                }
            }
            if (count < i->second) {
                p.push_back(i->first);
                permute(first, last, p, result);
                p.pop_back(); // 撤销动作,返回上一层
            }
        }
    }
};

