//
#include "../base.h"

class LUPrefix
{
    vector<int> v;
    set<int> st;

public:
    LUPrefix(int n)
    {
        v.resize(n + 1, 0);
    }

    void upload(int video)
    {
        v[video] = 1;
        for (int i = st.size() + 1; i < v.size(); ++i)
        {
            if (v[i] == 1)
            {
                st.insert(i);
            }
            else
            {
                break;
            }
        }
    }

    int longest()
    {
        return st.size();
    }
};

int main()
{

    LUPrefix server(4);   // Initialize a stream of 4 videos.
    server.upload(3);                    // Upload video 3.
    server.longest();                    // Since video 1 has not been uploaded yet, there is no prefix.
    // So, we return 0.
    server.upload(1);                    // Upload video 1.
    cout << server.longest();                    // The prefix [1] is the longest uploaded prefix, so we return 1.
    server.upload(2);                    // Upload video 2.
    server.longest();
}