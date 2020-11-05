#include <iostream>
using namespace std;
template<typename T1,typename T2>
void fun(T1 a,T2 b){
    cout<<"模板函数"<<endl;
}

template<>
void fun(int a,char b){
    cout<<"全特化"<<endl;
}

// 模版函数偏特化编译正常，无法匹配
template<typename T2>
void fun(char a,T2 b){
    cout<<"偏特化"<<endl;
}




int main()
{
    int a=0;
    char b='A';
    fun(a,a);
    fun(a,b);
    return 0;
}