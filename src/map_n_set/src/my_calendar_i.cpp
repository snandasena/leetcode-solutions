//
// Created by sajith on 8/3/22.
//


#include "base.h"

class MyCalendar
{
    set<pair<int, int>> st;
public:
    MyCalendar()
    {

    }

    bool book(int start, int end)
    {
        if (st.empty())
        {
            st.emplace(start, end);
            return true;
        }

        auto it = st.lower_bound({start, end});
        if (it == st.begin())
        {
            if (end <= it->first)
            {
                st.emplace(start, end);
                return true;
            }
            else
            {
                return false;
            }
        }

        if (it != st.end() && end > it->first)
        {
            return false;
        }

        --it;
        if (it->second <= start)
        {
            st.emplace(start, end);
            return true;
        }
        return false;
    }
};

int main()
{

    MyCalendar cal;
    cout << boolalpha;
    cout << cal.book(10, 20) << endl;
    cout << cal.book(15, 25) << endl;
    cout << cal.book(20, 30) << endl;
}