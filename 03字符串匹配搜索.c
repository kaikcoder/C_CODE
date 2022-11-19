/* 字符串匹配搜索 */
#include<stdio.h>
#include<string.h>
int BF(char *p,char *q){
    int len1 = strlen(p);
    int len2 = strlen(q);
    int i = 0;//遍历主串
    int j = 0;//遍历子串
    while(i< len1 && j < len2){
        /* 匹配成功 */
        if(p[i] == q[j]){
            i++;
            j++;
        }
        /* 匹配失败 */
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= len2){
        /* 如果是因为字串遍历结束 */
        /* 因为返回的是第几位，所有要数组下标加1 */
        return i - j + 1;
    }
    else{
        return -1;
    }
}
int main(){
    char s[10] = {0};
    char sub[10] = {0};
    /* 提示用户输入主串 */
    printf("请输入主串\n");
    gets(s);
    printf("请输入子串\n");
    gets(sub);
    int result = BF(s,sub);
    printf("%d",result);
    return 0;
}