
//
// Created by sajith on 8/21/22.
//

#include "base.h"

class Solution
{
public:
    bool is_match(const string &target, const string &stamp, int i)
    {
        for (int j = 0; j < stamp.size(); ++j)
        {
            if (target[i + j] != '?' && target[i + j] != stamp[j])
            {
                return false;
            }
        }
        return true;
    }

    int replace(string &target, int i, int stamp_size, int questions_mark)
    {
        for (int j = 0; j < stamp_size; ++j)
        {
            if (target[i + j] != '?')
            {
                ++questions_mark;
                target[i + j] = '?';
            }
        }
        return questions_mark;
    }

    vector<int> movesToStamp(string stamp, string target)
    {
        vector<bool> visited(target.size(), false);
        int question_marks = 0;
        int target_size = target.size();
        int stamp_size = stamp.size();

        vector<int> ans;

        while (question_marks < target_size)
        {
            bool did_stamp = false;
            for (int i = 0; i <= target_size - stamp_size; ++i)
            {
                if (!visited[i] && is_match(target, stamp, i))
                {
                    ans.push_back(i);
                    visited[i] = true;
                    did_stamp = true;
                    question_marks = replace(target, i, stamp_size, question_marks);
                }
            }

            if (!did_stamp)
            {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};