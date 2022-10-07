//
// Created by sajith on 10/6/22.
//

#include "base.h"


class TimeMap
{
    unordered_map<string, map<int, string>> mp;
public:
    TimeMap()
    {

    }

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (mp.count(key) == 0)
        {
            return {};
        }

        for (int i = timestamp; i >= 1; --i)
        {
            if (mp[key].count(i) > 0)
            {
                return mp[key][i];
            }
        }
        return {};
    }
};


int main()
{
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    timeMap.get("foo", 1);         // return "bar"
    timeMap.get("foo",
                3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    timeMap.get("foo", 4);         // return "bar2"
    timeMap.get("foo", 5);

    map<int, int> mp;

    mp[4] = 10;
    mp[5] = 15;
    mp[9] = 17;
    mp[10] = 110;
    mp[20] = 200;

    auto res = mp.lower_bound(1);
    cout << res->first << endl;

    return 0;
}