#include <iostream>
#include <map>
#include <vector>

class FreqStack
{
public:
    std::vector<int> stack = {};

    std::map<int, int> dict = {};

    FreqStack()
    {
    }

    void push(int val)
    {
        stack.push_back(val);
        if (dict.find(val) != dict.end())
        {
            dict[val] = dict[val] + 1;
        }
        else
        {
            dict[val] = 1;
        }
    }

    int pop()
    {
        int to_be_del = -1;
        int count = -1;
        int steps = 0;
        int numsteps = 0;
        for (auto it = stack.rbegin(); it != stack.rend(); it++)
        {
            steps++;
            int num = *it;
            if (dict[num] > count)
            {
                numsteps = steps;
                count = dict[num];
                to_be_del = num;
            }
        }

        std::cout << "to_be_del: " << to_be_del << ", count: " << count << std::endl;
        auto begin = stack.begin();
        for (int i = 0; i < stack.size() - numsteps; i++)
        {
            begin++;
        }

        stack.erase(begin);

        dict[to_be_del] = dict[to_be_del] - 1;

        return to_be_del;
    }

    void print()
    {
        for (auto &val : stack)
        {
            std::cout << val << std::endl;
        }

        std::cout << "Dict:" << std::endl;
        for (auto &val : dict)
        {
            std::cout << val.first << ": " << val.second << std::endl;
        }
    }
};

int main()
{
    FreqStack fqs;
    fqs.push(33);
    fqs.push(34);
    fqs.push(34);
    fqs.push(34);
    fqs.push(33);

    fqs.print();

    fqs.pop();

    fqs.print();

    fqs.pop();

    fqs.print();

    fqs.pop();

    fqs.print();
}
