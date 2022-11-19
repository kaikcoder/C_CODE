/*用二进制文件存取商品信息 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Null 0
#define N 2
struct good{
    char id[10];
    char name[10];
    float p;
    int num;
}s;//使用结构体数组表示
/* 输入商品信息 */
int write_g(){
    FILE *fp = fopen("good.text","wb");
    if(fp == Null){
        printf("文件打开失败");
        exit(0);
    }
    int i = 0;
    for(i=0; i<N; i++){
        scanf("%s %s %f %d",s.id,s.name,&s.p,&s.num);
        fprintf(fp,"%s %s %f %d\n",s.id,s.name,s.p,s.num);
    }
    fclose(fp);
    fp = Null;
    return 0;
}
/* 查找商品信息 */
int seek_g(){
    FILE *fp = fopen("good.text","rb");
    if(fp == Null){
        printf("文件打开失败");
        exit(0);
    }
    char id[10] = {0};
    scanf("%s",id);
    int flag = 1;//查找标志
    int i = 0;
    while(feof(fp)!=1){
        fscanf(fp,"%s %s %f %d",s.id,s.name,&s.p,&s.num);
        if((strcmp(s.id,id)) == 0){
            flag = 0;//表示查找到
            printf("%s\n%s\n",s.id,s.name);
            printf("%f\n%d\n",s.p,s.num);
            break;
        }
        i++;
    } 
    fclose(fp);
    fp = Null;
    if(flag!=0){
        printf("未找到");
    } 
    return 0;
}
int main(){
    write_g();
    seek_g();
    return 0;
}