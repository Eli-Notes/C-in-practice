//
//main.cpp
//HW2-5
//
//Created by Eli on 2017/7/13.
//Copyright © 2017年 Eli. All rights reserved.
//关键：算法逻辑。以及，整型相除得到double型的办法。
#include <iostream>
using namespace std;
int main() {
    //设置变量
    int n; //n为细菌的数量
    int id[100]; //id记录细菌的编号
    double rate[100]; //rate记录细菌的繁殖率
    //给变量赋值
    cin>>n;
    for(int i=0;i<n;i++) {
        int initial,final;
        cin>>id[i]>>initial>>final;
        rate[i]=(double)final/initial;//这种处理非常妙，int相除得到double型
    }
    //对整个细菌排序，看起来是冒泡排序或者类似的
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rate[j + 1] > rate[j]) {
                int tmpId = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tmpId;
                double tmpRate = rate[j];
                rate[j] = rate[j + 1];
                rate[j + 1] = tmpRate;
            }
        }
    }
    //记录最大的差和相应的下标
    double maxDiff=0;//Maximum
    int maxDiffIndex=0;//Location
    for(int i=0;i<n-1;i++){
        double diff=rate[i]-rate[i+1];
        if (maxDiff<diff){
            maxDiff=diff;
            maxDiffIndex=i;
        }
    }
    //输出繁殖率较大的那组细菌
    cout << maxDiffIndex + 1 << endl;
    for (int i = maxDiffIndex; i >= 0; i--) {
        cout << id[i] << endl;
    }
    //输出繁殖率较小的那组细菌
    cout << n - maxDiffIndex - 1 << endl;
    for (int i = n - 1; i >= maxDiffIndex + 1; i--) {
        cout << id[i] << endl;
    }
    return 0;
}
