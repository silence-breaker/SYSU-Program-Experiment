#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

//Q4


int main(void)
{
    char** str = new char*[3];
    for(int i=0;i<3;i++)
    {
        str[i] = new char[100];
    }
    cout << "请输入三个字符串:" << endl;
    for(int i=0;i<3;i++)
    {
        cin >> str[i];
    }
    char** str_copy = str;
    // 排序
    for(int i=0;i<3;i++)
    {
        for(int j=i+1;j<3;j++)
        {
            if(strcmp(str[i],str[j])>0)
            {
                char* temp=str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
       if(str_copy[i]==str[2])
           {
               cout << "最大的字符串为:" << str_copy[i] << endl;
               cout << "下标为：" << i << endl;

           }
    }
    for(int i=0;i<3;i++)
    {
        delete[] str[i];
    }
    delete[] str;
    return 0;
}




//Q3
// char* find_and_delete(char* str, char* ch)
// {
//     int len_str = strlen(str);
//     int len_ch = strlen(ch);
//     int i = 0;
//     int j = 0;
//     int x = 0;
//     int del_index[100] = {0}; 
//     char* str_cmp = new char[len_ch+1];
//     for(i=0;i<=(len_str-len_ch);i++)
//     {
//         for(j=0;j<(len_ch);j++)
//         {
//             str_cmp[j] = str[j+i];
//         }
//         str_cmp[len_ch] = '\0';
//         int comp_result = strcmp(str_cmp,ch);
//         if(comp_result==0)
//         {
//             del_index[x] = i;

//             cout <<"重复索引" << i <<endl;
//             x++;
//         }

//     }
//     for(i=x-1;i>=0;i--)
//     {
//         for(j=del_index[i];j<=(len_str-len_ch);j++)
//         {
//             str[j] = str[j+len_ch];
//         }
//         len_str -= len_ch;
//     }
//     delete[] str_cmp;
//     return str;
// }

// int main(void)
// {
//     cout << "输入想要处理的字符串" <<endl;
    
//     const int STR_LEN = 100;
//     char* str = new char[STR_LEN];//字符串开辟空间
//     cin >> str;
//     cout << "输入想要删除的字符或单词" <<endl;
    
//     char* del = new char[STR_LEN-50];//字符串开辟空间
//     cin >> del;
//     char* (*pfn)(char*,char*) = &find_and_delete;
//     char* result = pfn(str, del);
//     cout << "处理后的字符串为:" << endl;
//     cout << result << endl;
//     delete[] str;
//     delete[] del;
//     return 0;

// }



//Q2
// char** sort(char *str[],int n)
// {
//     int i = 0;
//     int j = 0;
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<n-i-1;j++)
//         {
//             if(strcmp(str[j],str[j+1])>0)
//             {
//                 char* temp=str[j];
//                 str[j] = str[j+1];
//                 str[j+1] = temp;
//             }
//         }
//     }
//     return str;
// }

// int main(void)
// {
//     cout << "你要输入多少个字符串" <<endl;
//     int str_num = 0;
//     cin >> str_num;
//     char** str = new char*[str_num];//字符数组对应的地址是二级指针
//     int i = 0;
//     const int STR_LEN = 100;
//     for(i=0;i<str_num;i++)
//     {
//         str[i] = new char[STR_LEN];//每个字符串开辟空间
//     }
//     cout << "请输入字符串（长度不可超过100）"<<endl;
//     for(i=0;i<str_num;i++)
//     {
//         cin >> str[i];
//     }
//     sort(str,str_num);
//     cout << "排序后的字符串为"<<endl;
//     for(i=0;i<str_num;i++)
//     {
//         cout << str[i] << endl;
//     }
//     for (int i = 0; i < str_num; i++) {
//         delete[] str[i]; // 释放单个字符串
//     }
//     delete[] str;
//     return 0;
// }




//Q1
// char* cout_same_char(char* str1, char* str2)
// {
//     static char result[100];
//     int index = 0;
//     for(int i=0;str1[i]!='\0';i++)
//     {
//         for(int j=0;str2[j]!='\0';j++)
//         {
//             if(str1[i]==str2[j])
//             {
//                 result[index++] = str1[i];
//                 break;
//             }
//         }
//     }
//     result[index] = '\0';
//     return result;
// }

// int main(void)
// {
//     cout << "请输入第一个字符串:\n";
//     char str1[100];
//     cin >> str1;
//     cout << "请输入第二个字符串:\n";
//     char str2[100];
//     cin >> str2;
//     char* result = cout_same_char(str1, str2);
//     cout << "两个字符串中相同的字符有:\n";
//     cout << result << endl;
// }
