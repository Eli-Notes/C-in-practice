//
//  main.cpp
//  Week Final5
//
//  Created by Eli on 2017/7/10.
//  Copyright © 2017年 Eli. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    char str[14], substr[4];
    while(cin>>str>>substr){  //这里用while实现多行输入。而且，输入的时候没那么麻烦，直接一个空格就能区分str和substr两个数组了。同一数组里面不需要再加空格。
        int i=0, posBiggest=0;  //posBiggest表示位置。
        char strBiggest=0;  //strBiggest表示字符串的ASCII码。
        while(str[i]){  //这个用法很重要，表示当str[i]有意义时，也就是i在str的范围内时。
            if(str[i]>strBiggest){
                posBiggest=i;
                strBiggest=str[i];
            }
            i++;
        }
        for(int j=9;j>posBiggest;j--)str[j+3] = str[j];
        str[posBiggest+1] = substr[0];
        str[posBiggest+2] = substr[1];
        str[posBiggest+3] = substr[2];
        cout<<str<<endl;//这个用法很重要，可以直接免去循环来输出字符数组。
    }
    return 0;
}
