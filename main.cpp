#include <iostream>
#include <stdio.h>
class X
{
    public:
        X() : mX(101) {
        }
        virtual void vfunc1() {
            std::cout << "X::vfunc1()" << std::endl;
        }
        virtual void vfunc2() {
            std::cout << "X::vfunc2()" << std::endl;
        }
    private:
        int mX;
};
class XX : public X
{
    public:
        XX()
        : mXX(1001),
          mXXX(10001){
        }
        virtual void vfunc()
        {
            std::cout << "XX::vfunc()" << std::endl;
        }
        virtual void vfunc1()
        {
            std::cout << "XX::vfunc1()" << std::endl;
        }
        virtual void vfunc2()
        {
            std::cout << "XX::vfunc2()" << std::endl;
        }
        // void vfuncc()
        // {
        //     std::cout << "XX::vfuncc()" << std::endl;
        // }
    private:
        int mXX;
        int mXXX;
};

// void printTypeInfo(const X *px)
// {
//     std::cout << "typeid(px) -> " << typeid(px).name() << std::endl;
//     std::cout << "typeid(*px) -> " << typeid(*px).name() << std::endl;
// }
// int main()
// {
//     X x;
//     XX xx;
//     printTypeInfo(&x);
//     printTypeInfo(&xx);
//     return 0;
// }

int main()
{
    typedef void (*FuncPtr)();
    XX xx;
    FuncPtr func;
    std::cout << "xx size: " << sizeof(xx) << std::endl;
    char *p = (char*)&xx;
    printf("p: %p\n ", p);
    // 获得虚函数表的地址 
    int **vtbl = (int**)*(int**)p;
    //size_t **vtbl = (size_t**)*(size_t**)p;
    // 输出虚函数表的地址，即vptr的值
    std::cout << vtbl << std::endl;
    // 获得type_info对象的指针，并调用其name成员函数
    std::cout << "\t[-1]: " << (vtbl[-1]) << " -> "
        << ((std::type_info*)(vtbl[-1]))->name() << std::endl;
    //std::cout << "\t[-1]: " << (vtbl[-1]) << " -> "
    //    << ((std::type_info*)(vtbl[-1]))->hash_code() << std::endl;
    // 调用第一个virtual函数
    std::cout << "\t[0]: " << vtbl[0] << " -> ";
    func = (FuncPtr)vtbl[0];
    func();
    std::cout << "\t[1]: " << vtbl[1] << " -> ";
    func = (FuncPtr)vtbl[1];
    func();
    std::cout << "\t[2]: " << vtbl[2] << " -> ";
    func = (FuncPtr)vtbl[2];
    func();
    // 输出基类的成员变量的值
    p += sizeof(int**);
    printf("p: %p\n ", p);
    std::cout << *(int*)p << std::endl;
    // 输出派生类的成员变量的值
    p += sizeof(int);
    printf("p: %p\n ", p);
    std::cout << *(int*)p << std::endl;

    p += sizeof(int);
    printf("p: %p\n ", p);
    std::cout << *(int*)p << std::endl;

    p += sizeof(int);
    printf("p: %p\n ", p);
    std::cout << *(int*)p << std::endl;
    // // 输出派生类的成员变量的值
    // p += sizeof(int);
    // cout << *(int*)p << endl;

    std::cout << "........." << std::endl;
    X x;
    FuncPtr func1;
    char *p1 = (char*)&x;
    printf("p1: %p\n ", p1);
    // 获得虚函数表的地址 
    int **vtbl1 = (int**)*(int**)p1;
    //size_t **vtbl = (size_t**)*(size_t**)p;
    // 输出虚函数表的地址，即vptr的值
    std::cout << vtbl1 << std::endl;
    // 获得type_info对象的指针，并调用其name成员函数
    std::cout << "\t[-1]: " << (vtbl1[-1]) << " -> "
        << ((std::type_info*)(vtbl1[-1]))->name() << std::endl;
    //std::cout << "\t[-1]: " << (vtbl[-1]) << " -> "
    //    << ((std::type_info*)(vtbl[-1]))->hash_code() << std::endl;
    // 调用第一个virtual函数
    std::cout << "\t[0]: " << vtbl1[0] << " -> ";
    func1 = (FuncPtr)vtbl1[0];
    func1();
    // 输出基类的成员变量的值
    p1 += sizeof(int**);
    std::cout << *(int*)p1 << std::endl;
    printf("p1: %p\n ", p1);
    // 输出派生类的成员变量的值
    p1 += sizeof(int);
    std::cout << *(int*)p1 << std::endl;
     printf("p1: %p\n ", p1);
    return 0;
}