#include <iostream>
#include <string>
#include <map>
using namespace std;
string GetNumStr(const string &str)
{
    unordered_map<string, vector<string>> state_table = {
        // ' ', +/-, 0, num, other
        "start" : [ "start", "signed", "start", "num", "end" ],
        "signed" : [ "signed", "end", "signed", "num", "end" ],
        "num" : [ "end", "end", "num", "num", "end" ],
    };

    string state = "start";

    string new_str;
    int i = 0;
    while (state != "end")
    {
        state = state_table[state](getNext(str[i]));
        if ((state = "signed" && str[i] != '0') || state == "num")
        {
            new_str.push_back(str[i]);
        }

        ++i;
    }

    return new_str;
}

int myAtoi(string str)
{
    string num_str = findNumStr(str);

    if (num_str.empty())
    {
        return 0;
    }

    std::cout << num_str << std::endl;

    string big = to_string((1 << 31) - 1);
    string min = to_string(1 << 31);

    std::cout << big << endl
              << min << endl;

    int base = 1;
    if (num_str[0] == '-')
    {
        base *= -1;

        if (num_str.substr(1, num_str.size() - 1) > min)
        {
            return static_cast<unsigned int>((1 << 31) * -1);
        }
    }
    else
    {
        if (num_str > big)
        {
            return (1 << 31) - 1;
        }
    }

    int num = 0;

    std::cout << num_str;
    for (int i = num_str.size() - 1; i >= 0; --i)
    {

        num += base * (num_str[i] - '0');
    }

    return num;
}

int main()
{
    std::string a = "42";
    std::cout << GetNumStr(a);
}
