#include <iostream>
#include <vector>

using namespace std;
bool Merge2(float a, float b, float c);
bool Merge(float a, float b);
bool Is24(float a);

bool Merge3(float a, float b, float c, float d)
{
    return Merge2(a + b, c, d) ||
           Merge2(a * b, c, d) ||
           Merge2(a - b, c, d) ||
           Merge2(b - a, c, d) ||
           Merge2(a / b, c, d) ||
           Merge2(b / a, c, d) ||
           Merge2(a + c, b, d) ||
           Merge2(a * c, b, d) ||
           Merge2(a - c, b, d) ||
           Merge2(c - a, b, d) ||
           Merge2(a / c, b, d) ||
           Merge2(c / a, b, d) ||
           Merge2(a + d, b, c) ||
           Merge2(a * d, b, c) ||
           Merge2(a - d, b, c) ||
           Merge2(d - a, b, c) ||
           Merge2(a / d, b, c) ||
           Merge2(d / a, b, c) ||
           Merge2(b + c, a, d) ||
           Merge2(b * c, a, d) ||
           Merge2(b - c, a, d) ||
           Merge2(c - b, a, d) ||
           Merge2(b / c, a, d) ||
           Merge2(c / b, a, d) ||
           Merge2(b + d, a, c) ||
           Merge2(b * d, a, c) ||
           Merge2(b - d, a, c) ||
           Merge2(d - b, a, c) ||
           Merge2(b / d, a, c) ||
           Merge2(d / b, a, c) ||
           Merge2(c + d, a, b) ||
           Merge2(c * d, a, b) ||
           Merge2(c - d, a, b) ||
           Merge2(d - c, a, b) ||
           Merge2(c / d, a, b) ||
           Merge2(d / c, a, b);
}

bool Merge2(float a, float b, float c)
{
    return Merge(a + b, c) ||
           Merge(a * b, c) ||
           Merge(a - b, c) ||
           Merge(b - a, c) ||
           Merge(a / b, c) ||
           Merge(b / a, c) ||
           Merge(a + c, b) ||
           Merge(a * c, b) ||
           Merge(a - c, b) ||
           Merge(c - a, b) ||
           Merge(a / c, b) ||
           Merge(c / a, b) ||
           Merge(b + c, a) ||
           Merge(b * c, a) ||
           Merge(b - c, a) ||
           Merge(c - b, a) ||
           Merge(b / c, a) ||
           Merge(c / b, a);
}

bool Merge(float a, float b)
{
    return Is24(a + b) || Is24(a * b) || Is24(a - b) || Is24(b - a) || Is24(a / b) || Is24(b / a);
}

bool Is24(float a)
{
    return (a > 23.99 && a < 24.01);
}

int main()
{
    std::cout << Merge3(3, 3, 8, 8);
};
