/*�ö������ļ���ȡ��Ʒ��Ϣ */
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
}s;//ʹ�ýṹ�������ʾ
/* ������Ʒ��Ϣ */
int write_g(){
    FILE *fp = fopen("good.text","wb");
    if(fp == Null){
        printf("�ļ���ʧ��");
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
/* ������Ʒ��Ϣ */
int seek_g(){
    FILE *fp = fopen("good.text","rb");
    if(fp == Null){
        printf("�ļ���ʧ��");
        exit(0);
    }
    char id[10] = {0};
    scanf("%s",id);
    int flag = 1;//���ұ�־
    int i = 0;
    while(feof(fp)!=1){
        fscanf(fp,"%s %s %f %d",s.id,s.name,&s.p,&s.num);
        if((strcmp(s.id,id)) == 0){
            flag = 0;//��ʾ���ҵ�
            printf("%s\n%s\n",s.id,s.name);
            printf("%f\n%d\n",s.p,s.num);
            break;
        }
        i++;
    } 
    fclose(fp);
    fp = Null;
    if(flag!=0){
        printf("δ�ҵ�");
    } 
    return 0;
}
int main(){
    write_g();
    seek_g();
    return 0;
}