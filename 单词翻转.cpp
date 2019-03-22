//  HW3-1
//  Created by Eli on 2017/7/15.
//  Copyright © 2017年 Eli. All rights reserved.
//关键点：函数的递归调用，函数设计，flag的设计。
#include <iostream>
using namespace std;
bool flag=false;//设置全局变量好一点，这样即便在recur里面，也可以做标记。一开始没注意，老是报错。设置flag的原因在下面有说明。
void recur();//main里面会用到，所以先声明一下。而且考虑了一下，用void更有把握一点，int的话应该也可以，没试。
int main(){
    recur(); // 直接交给函数来递归。
    // recur函数的设计需要考虑空格不逆序输出的情况，所以有下面的操作，
    while(flag){cout<<' ';flag=false;recur();} // 这里很重要
    cout<<endl;
    return 0;
}
void recur(){
    char c;
    c=cin.get();    // 这个语句的具体特性还不清楚，有待之后观察。
    if(c != '\n'){
        // 先判断是不是换行，是的话，就直接结束，不是的话，就递归。
        if(c==' ')flag=true;//对于空格的情况，直接标记true，结束递归，交给main处理。
        else{recur();cout<<c;}//这里进行递归，自己调用自己，也就是递归调用。
    }
}
