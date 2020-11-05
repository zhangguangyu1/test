#include <iostream>

int Strcpy(const char* org, char* des)
{
    if (sizeof(org) > sizeof(des))
    {
        return -1;
    }

    const char* a = org;
    char* b = des;
    while ( *a != '\0')
    {
        *b = *a;

        ++b;
        ++a;
    }
    return 0;
}

int main() {
    
    const char* str = "abcdef";
    
    char* des = new char[10];

    Strcpy(str, des);

    std::cout << des;

    return 0;

}
