//C++里面的指针的笔记
//Part1 输出一个int变量的值的两种方法。
#include <iostream>
using namespace std;
int main(){
    int a=3;
    //前两个输出的都是a的值
    cout<<a<<endl;
    cout<<*&a<<endl;
    cout<<&a<<endl;//输出的是a的地址，不是a的值
    //cout<<*a<<endl;这种输出语法不行！
    //cout<<&*a<<endl;这种输出语法不行！
    return 0;
}

/*Part2 初始化指针变量的最简单方式（面对数组）；输出数组的两种方式。
#include <iostream>
using namespace std;
int main(){
    char a[]="abc";
    char *p=a;
    cout<<*p<<endl;//output a
    cout<<a<<endl;//output abc，这就是C++数组输出的便捷方式。
    cout<<p<<endl;//output abc，这里说明指针变量可以一定程度上代替原来的数组变量，尤其是在输出的时候。
    return 0;
}*/

/*Part3 用指针变量修改字符数组的元素的三种办法
#include <iostream>
using namespace std;
int main(){
    //方法一：用中括号引用，最简单的两种方法之一
    char a[]="hollo,world";
    a[1]='e';
    cout<<a<<endl;
    /*方法二：用新定义的指针变量
    char a[]="hollo,world";
    char *p=a;
    p++;
    *p='e';
    cout<<a<<endl;*/
    /*方法三：直接用a的地址含义，最简单的两种方法之一
    char a[]="hollo,world";
    *(a+1)='e';
    cout<<a<<endl;*/
    /*错误的方法：a不能直接充当指针变量
    char a[]="hollo,world";
    a++;
    *a='e';
    cout<<a<<endl;
    return 0;*/
}*/

/*Part4 修改双精度变量的数值
#include <iostream>
using namespace std;
int main(){
    double num=3.14;
    double *pi=&num;
    *pi=3.14159;//这个是肯定可以的
    pi[0]=3.14159;//这个也可以！！！？？？【待更新】
    cout<<num<<endl;
    return 0;
}*/

/*Part5 输出字符数组的后半段
#include <iostream>
using namespace std;
int main(){
    char str[]="hello,world";
    //cout<<str[5:10]<<endl;//错误，冒号是识别不了的
    //cout<<*(str+5)<<endl;//错误，只能输出一个字符
    //cout<<str[5]<<endl;//错误，同上
    //for(int i=5;i<=10;i++)cout<<*(str+i);cout<<endl;//正确
    //for(int i=5;i<=10;i++)cout<<str[i];cout<<endl;//正确，同上
    cout<<str+5<<endl;//正确！！！！为什么！！？？
    return 0;
}
