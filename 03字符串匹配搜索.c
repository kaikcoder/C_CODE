/* �ַ���ƥ������ */
#include<stdio.h>
#include<string.h>
int BF(char *p,char *q){
    int len1 = strlen(p);
    int len2 = strlen(q);
    int i = 0;//��������
    int j = 0;//�����Ӵ�
    while(i< len1 && j < len2){
        /* ƥ��ɹ� */
        if(p[i] == q[j]){
            i++;
            j++;
        }
        /* ƥ��ʧ�� */
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= len2){
        /* �������Ϊ�ִ��������� */
        /* ��Ϊ���ص��ǵڼ�λ������Ҫ�����±��1 */
        return i - j + 1;
    }
    else{
        return -1;
    }
}
int main(){
    char s[10] = {0};
    char sub[10] = {0};
    /* ��ʾ�û��������� */
    printf("����������\n");
    gets(s);
    printf("�������Ӵ�\n");
    gets(sub);
    int result = BF(s,sub);
    printf("%d",result);
    return 0;
}