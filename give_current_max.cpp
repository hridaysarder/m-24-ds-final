#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks < b.marks)
            return true;
        else if (a.marks == b.marks)
            return a.roll > b.roll;
        else
            return false;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    set<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
        st.insert({marks, roll});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            st.insert({marks, roll});
            auto it = pq.top();
            cout << it.name << " " << it.roll << " " << it.marks << endl;
        }
        else if (cmd == 1)
        {
            if (!pq.empty())
            {
                while (!pq.empty() && !st.count({pq.top().marks, pq.top().roll}))
                {
                    pq.pop();
                }
                if (!pq.empty())
                {
                    auto top = pq.top();
                    cout << top.name << " " << top.roll << " " << top.marks << endl;
                }
                else
                    cout << "Empty" << endl;
            }
            else

                cout << "Empty" << endl;
        }
        else if (cmd == 2)
        {
            if (!pq.empty())
            {
                while (!pq.empty() && !st.count({pq.top().marks, pq.top().roll}))
                {
                    pq.pop();
                }
                if (!pq.empty())
                {
                    st.erase({pq.top().marks, pq.top().roll});
                    pq.pop();
                }
                if (!pq.empty())
                {
                    while (!pq.empty() && !st.count({pq.top().marks, pq.top().roll}))
                    {
                        pq.pop();
                    }
                    if (!pq.empty())
                    {
                        auto top = pq.top();
                        cout << top.name << " " << top.roll << " " << top.marks << endl;
                    }
                    else
                        cout << "Empty" << endl;
                }
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
        }
    }

    return 0;
}
