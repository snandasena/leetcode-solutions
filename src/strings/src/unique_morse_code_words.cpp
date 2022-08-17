//
// Created by sajith on 8/17/22.
//
#include "base.h"

static const vector<string> v{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                              "--",
                              "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                              "--.."};
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> st;
        for (const auto &word: words)
        {
            string m;
            for (const auto &ch: word)
            {
                m += v[ch - 'a'];
            }

            st.insert(m);
        }

        return st.size();
    }
};