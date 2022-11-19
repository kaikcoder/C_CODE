/* 求利润 */
#include<stdio.h>
int main(){
    float profit = 0.0;//利润
    float bonus = 0.0;//奖金
    float bonus1 = 100000*0.1;
    float bonus2 = bonus1 + 100000*0.075;
    float bonus3 = bonus2 + 200000*0.05;
    float bonus4 = bonus3 + 200000*0.03;
    float bonus5 = bonus4 + 400000*0.15;
    scanf("%f",&profit);
    // 利润低于或等于10万时，奖金可以10%
    if(profit <= 100000.0){
        bonus = profit*0.1;
    }else if(profit <= 200000.0){
        bonus = bonus1 + (profit-100000)*0.075;
    }else if(profit <= 400000){
        bonus = bonus2 + (profit-200000)*0.05;
    }else if(profit <= 600000){
        bonus = bonus3 + (profit-400000)*0.03;
    }else if(profit <= 100000){
        bonus = bonus4 + (profit-600000)*0.15;
    }else{
        bonus = bonus5 + (profit-1000000)*0.1;
    }
    printf("%.1f",bonus);
    return 0;
}