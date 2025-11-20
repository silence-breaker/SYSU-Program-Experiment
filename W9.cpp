#include <iostream>
using namespace std;

// //Q1
// //输入两个字符串，统计两个字符串中相同的单词个数
// #include <unordered_set>
// #include <sstream>

// int countCommonWords(const string& str1, const string& str2) {
//     unordered_set<string> words1;
//     istringstream stream1(str1);
//     string word;
    
//     while (stream1 >> word) {
//         words1.insert(word);
//     }
    
//     int commonCount = 0;
//     istringstream stream2(str2);
    
//     while (stream2 >> word) {
//         if (words1.find(word) != words1.end()) {
//             commonCount++;
//             words1.erase(word); // To avoid counting duplicates
//         }
//     }
    
//     return commonCount;
// }

// int main(void)
// {
//     cout << "请输入两个字符串" << endl;
//     string str1, str2;
//     getline(cin, str1);
//     getline(cin, str2);
//     int commonWords = countCommonWords(str1, str2);
//     cout << "两个字符串中相同的单词个数为: " << commonWords << endl;
//     return 0;
// }

//Q2
//判断该字符串是否是回文
// int isPalindrome(const string& str) {
//     int left = 0;
//     int right = str.length() - 1;
    
//     while (left < right) {
//         if (str[left] != str[right]) {
//             return 0; // 不是回文
//         }
//         left++;
//         right--;
//     }
//     return 1; // 是回文
// }

// int main(void)
// {
//     cout << "请输入一个字符串" << endl;
//     string str;
//     getline(cin, str);
//     if (isPalindrome(str)) {
//         cout << "该字符串是回文" << endl;
//     } else {
//         cout << "该字符串不是回文" << endl;
//     }
//     return 0;
// }

//Q3
//输入抽签的起始与结束数字、抽出的数字个数，让计算机自动抽签，并将抽出的数字由小到大排序

#include <cstdlib>
#include <ctime>

int main(void)
{
    srand(time(0));
    cout << "请输入抽签的起始与结束数字" << endl;
    int start, end;
    cin >> start >> end;
    cout << "请输入抽出的数字个数" << endl;
    int count;
    cin >> count;
    int i = 0;
    int* list = new int[count];
    while(i < count)
    {
        
        int num = rand() % (end - start + 1) + start;
        list[i] = num;
        // 检查是否重复
        bool isDuplicate = false;
        if(i > 0)
        {
            for(int j = 0; j < i; j++)
            {
                if(list[j] == num)
                {
                    isDuplicate = true;
                    break;
                }
            }
        }
        if(!isDuplicate)
            i++;
    }
    //把list数组中的数字从小到大排列
    for(int m = 0; m < count - 1; m++)
    {
        for(int n = 0; n < count - m - 1; n++)
        {
            if(list[n] > list[n + 1])
            {
                int temp = list[n];
                list[n] = list[n + 1];
                list[n + 1] = temp;
            }
        }
    }
    cout << "抽出的数字为:" << endl;
    for(int k = 0; k < count; k++)
    {
        cout << list[k] << " ";
    }
    cout << endl;
    delete[] list;
    return 0;
}