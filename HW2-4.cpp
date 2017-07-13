//
//  main.cpp
//  HW2-4
//
//  Created by Eli on 2017/7/12.
//  Copyright © 2017年 Eli. All rights reserved.
//实现的功能：输入一个日期，比如2011-01-01（一行），然后输出它的下一天，也就是2011-01-02。要考虑的最重要因素是闰年的处理
//关键的重点：（1）函数的设置和使用；（2）字符数组的cin与cout语法；（3）字符数组一开始的长度设置；（4）字符与数值的转化，atoi与itoa。
#include <iostream>
#include <stdlib.h>     /* atoi & itoa */
#include <string>       /* strcat */
using namespace std;
int match(int leap_year,int month);
int main(){
    //先输入日期
    int year,month,day;//输入
    char date[11];//这里非常重要，定义的数组的长度必须大于实际长度，这里有后面可知，实际长度为10，则定义的时候必须定义大于10个，这样才能留出空间给\0。这种情况下，用string库的strlen函数可以知道，date的长度是10，不是11.
    cin>>date;//这种输入是可以的。
    char year1[5]={date[0],date[1],date[2],date[3]};//这里的5也可以是4，不会报错，但是还是有风险，所以还是用5吧，更大的时候也行。
    char month1[3]={date[5],date[6]};//这里必须用3，不能为2，会报错。
    char day1[3]={date[8],date[9]};//这里必须用3，不能为2，会报错。
    
    //将日期转化为数值
    //atoi函数可以自动识别字符数组中的第一个非零元素为起点，然后遍历到\0处，同时可以忽略所有的无关元素（只是猜测，没有证实）。
    year=atoi(year1);//年数值
    month=atoi(month1);//月数值
    day=atoi(day1);//日数值
    
    //首先判断是不是闰年
    int leap_year=((year%4==0&&year%100!=0)||year%400==0);//为1时，为闰年
    
    //然后判断现在所在月多少天，用一个函数来做吧
    int length_month=match(leap_year,month);
    
    //得出数值结果
    int y=0,m=0,d=0;
    if(length_month==day){
        d=1;
        m=(month+1)%12;
        if(month==12)y=year+1;
        else y=year;
    }
    else y=year,m=month,d=day+1;
    
    //得出字符结果并输出
    cout<<y<<'-';
    if(m<10)cout<<'0'<<m<<'-';
    else cout<<m<<'-';
    if(d<10)cout<<'0'<<d<<endl;
    else cout<<d<<endl;
    return 0;
}

int match(int leap_year,int month){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)return 31;
    else if(month==4||month==6||month==9||month==11)return 30;
    else if(month==2&&leap_year==1)return 29;
    else if(month==2&&leap_year==0)return 28;
    else return 0;
}
