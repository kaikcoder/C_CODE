#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define null 0
struct Howliday{
    int year;//��
    int month;//��
    int day;//��
    int flag;//��������
};
// ͳ�ƽڼ��յ�����
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
    printf("�ڼ�����%d��\n",count);
    fclose(fp);
    fp = null;
    return 0;
}

// �ж�ĳ���������ڼ�
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
        // �ж���Ϣ�Ƿ��ڱ���
        if(H[i].year == y && H[i].month == m && H[i].day == d){
            if(H[i].flag == 0){
                printf("�����ǽڼ���");
            }else if(H[i].flag == 1){
                printf("�����ǹ�����");
            }
        i++;
        }

        else{
        //�ж��������ڼ�
        if(m<3)
        {
            m+=12;
            y-=1;
        }
        T=((d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7+7)%7;
        if(T==0)
            printf("������,��������Ϣ��\n");
        if(T==1)
            printf("����һ,�����ǹ�����\n");
        if(T==2)
            printf("���ڶ�,�����ǹ�����\n");
        if(T==3)
            printf("������,�����ǹ�����\n");
        if(T==4)
            printf("������,�����ǹ�����\n");
        if(T==5)
            printf("������,�����ǹ�����\n");
        if(T==6)
            printf("������,��������Ϣ��\n");
        }
    fclose(fp);
    fp = null;
    return 0;
}
}
int main(){
    tatol_h();//ͳ�ƽڼ��յ�����
    panduan();//�ж����ڼ����Ƿ��ǹ�����/�ٽ���/��Ϣ��
    return 0;
}