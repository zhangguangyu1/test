#include <iostream>
#include <string>
#include <vector>

uint32_t ConverIP(const std::string& src)
{
    std::vector<uint32_t> nums;

    size_t left = 0;
    for (size_t i = 0; i < src.size(); ++i)
    {
        if (src[i] == '.')
        {
            std::string sub_num = src.substr(left, i - left);

            nums.push_back(static_cast<uint32_t>(atoi(sub_num.c_str())));

            left = i + 1;
        }
    }

    nums.push_back(static_cast<uint32_t>(atoi(src.substr(left).c_str())));

    uint32_t result = 0x0000;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        std::cout << (8 * (nums.size() - i - 1));
        result |= nums[i] << (8 * (nums.size() - i - 1));
    }

    return result;
}

int main()
{
    std::cout << ConverIP("1.1.1.1");

    return 0;
}