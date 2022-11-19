/* 图书文件 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3
#define Null 0
struct book{
    char name[5];//书名
    int id;//书号
    float f;//单价
    int num;//数量
}s[N];//使用结构体数组表示
/* 输入所有图书信息 */
int write_B(){
    int i = 0;
    for(i=0; i<N; i++){
        scanf("%s %d %f %d",s[i].name,&s[i].id,&s[i].f,&s[i].num);
    }
    return 0;
}
/* 对数据进行排序 */
int sort_B(){
    int i = 0,j = 0;
    struct book temp;
    for(i=0; i<N-1; i++){
        for(j=0; j<N-1-i; j++){
            if(strcmp(s[j].name,s[j+1].name)>0){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
            // 如果书名相同，则按照单价降序排序
            if(strcmp(s[j].name,s[j+1].name)==0){
                if(s[j].f<s[j+1].f){
                    temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
    }
    return 0;
}
/* 写入二进制文件 */
int write_a(){
    FILE *fp = fopen("test.txt","wb");
    if(fp == Null){
        printf("文件打开失败");
        exit(0);
    }
    int i = 0;
    for(i=0; i<N; i++){
        fprintf(fp,"%s %1d %.1f %1d\n",s[i].name,s[i].id,s[i].f,s[i].num);
    }
    fclose(fp);
    fp = Null;
    return 0;
}
int main(){
    write_B();
    sort_B();
    write_a();
    return 0;
}