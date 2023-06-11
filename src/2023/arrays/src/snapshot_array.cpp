//
// Created by sajit on 11/06/2023.
//

#include <bits/stdc++.h>

using namespace std;

/*
class SnapshotArray
{
    int id = 0;
    unordered_map<int, unordered_map<int, int>> snapshot;
public:
    SnapshotArray(int length)
    {

    }

    void set(int index, int val)
    {
        snapshot[id][index] = val;
    }

    int snap()
    {
        int temp = id;
        if (id > 0)
            snapshot[id] = snapshot[id - 1];

        ++id;
        return temp;
    }

    int get(int index, int snap_id)
    {
        auto res = snapshot[snap_id-1].find(index);
        if (res == snapshot[snap_id].end())
            return 0;
        return res->second;
    }
};
*/

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

class SnapshotArray
{
public:
    int snapId;
    vector<vector<pair<int, int>>> historyRecords;

    SnapshotArray(int length)
    {
        snapId = 0;
        historyRecords.resize(length);
        for (int i = 0; i < length; ++i)
        {
            historyRecords[i].push_back(make_pair(0, 0));
        }
    }

    void set(int index, int val)
    {
        historyRecords[index].push_back(make_pair(snapId, val));
    }

    int snap()
    {
        return snapId++;
    }

    int get(int index, int snap_id)
    {
        auto it = upper_bound(historyRecords[index].begin(), historyRecords[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};


int main()
{
    SnapshotArray arr{1};

    arr.set(0, 15);
    cout << arr.snap() << '\n';
    cout << arr.snap() << '\n';
    cout << arr.snap() << '\n';
    cout << arr.get(0, 2) << '\n';
    cout << arr.snap() << '\n';
    cout << arr.snap() << '\n';
    cout << arr.get(0, 0) << '\n';

    return 0;
}