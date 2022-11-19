#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define null 0
struct Howliday{
    int year;//年
    int month;//月
    int day;//日
    int flag;//调休日期
};
// 统计节假日的天数
int tatol_h(){
    FILE *fp = fopen("test.txt","r");
    if(fp == null){
        printf("null");
        exit(0);
    }
    struct Howliday H[100];
    int i = 0,count = 0;
    while(!feof(fp)){
        fscanf(fp,"%d%d%d %d",&H[i].year,&H[i].month,&H[i].day,&H[i].flag);
        if(H[i].flag == 0){
            count++;
        }
        i++;
    }
    printf("节假日有%d天\n",count);
    fclose(fp);
    fp = null;
    return 0;
}

// 判断某天属于星期几
int panduan(){
    FILE *fp = fopen("test.txt","r");
    if(fp == null){
        printf("null");
        exit(0);
    }
    int i = 0;
    struct Howliday H[100];
    int y,m,d,T;
    scanf("%d%d%d",&y,&m,&d);
    int sum = 0;
    while(!feof(fp)){
        fscanf(fp,"%d%d%d %d",&H[i].year,&H[i].month,&H[i].day,&H[i].flag);
        // 判断信息是否在表中
        if(H[i].year == y && H[i].month == m && H[i].day == d){
            if(H[i].flag == 0){
                printf("该天是节假日");
            }else if(H[i].flag == 1){
                printf("改天是工作日");
            }
        i++;
        }

        else{
        //判断属于星期几
        if(m<3)
        {
            m+=12;
            y-=1;
        }
        T=((d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7+7)%7;
        if(T==0)
            printf("星期日,该天是休息日\n");
        if(T==1)
            printf("星期一,该天是工作日\n");
        if(T==2)
            printf("星期二,该天是工作日\n");
        if(T==3)
            printf("星期三,该天是工作日\n");
        if(T==4)
            printf("星期四,该天是工作日\n");
        if(T==5)
            printf("星期五,该天是工作日\n");
        if(T==6)
            printf("星期六,该天是休息日\n");
        }
    fclose(fp);
    fp = null;
    return 0;
}
}
int main(){
    tatol_h();//统计节假日的天数
    panduan();//判断星期几和是否是工作日/假节日/休息日
    return 0;
}