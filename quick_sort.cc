#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& vec, int left, int right) {
    
    if (left > right) {
        return;
    }

    int cur = vec[left];
    int a = left;
    int b = right;

    while (left < right) {
        
        while (vec[right] >= cur && left < right ) right--;
     
        while (vec[left] <= cur && left < right ) left++;

        if (left < right) {
            int tmp = vec[left];
            vec[left] = vec[right];
            vec[right] = tmp;
        }
    }

    vec[a] = vec[left];
    vec[left] = cur;

    QuickSort(vec, a, left - 1);
    QuickSort(vec, left+1, b);
}

int main()
{
    std::vector<int> vec = {5, 3, 2, 4, 7, 8};


    for (auto item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << "size: " << vec.size() << std::endl;

    QuickSort(vec, 0, vec.size() - 1);

    for (auto item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << "size: " << vec.size() << std::endl;
}