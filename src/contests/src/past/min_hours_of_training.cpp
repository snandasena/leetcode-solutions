//
// Created by sajith on 8/21/22.
//

#include "../base.h"

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        auto total_engergy = accumulate(energy.begin(), energy.end(), 0);
        auto total_experience = accumulate(experience.begin(), experience.end(), 0);

        if (initialEnergy > total_engergy && initialExperience > total_experience)
        {
            return 0;
        }

        int ans = 0;
        if (total_engergy >= initialEnergy)
        {
            ans += total_engergy - initialEnergy + 1;
        }

        for (int i = 0; i < experience.size(); ++i)
        {
            if (initialExperience <= experience[i])
            {
                auto t = experience[i] - initialExperience + 1;
                initialExperience += t;

                ans+=t;
            }

            initialExperience += experience[i];
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    int initEgy = 1;
    int initExp = 1;
    vector<int> engy{1, 1, 1, 1};
    vector<int> exper{1, 1, 1, 50};

    cout << solution.minNumberOfHours(initEgy, initExp, engy, exper);
    return 0;
}