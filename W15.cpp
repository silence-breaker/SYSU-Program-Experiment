#include <iostream>
using namespace std;
//Q1
// double ave(int* arr,int n)
// {
//     int i = 0;
//     double sum = 0;
//     double ave = 0;
//     for(i=0;i<n;i++)
//     {
//         sum = sum + arr[i];
//     }
//     ave = sum/n;
//     return ave;
// }

// double mea(int*arr,int n)
// {
//     if(n%2!=0)
//     {
//         int index = (n/2)+1;
//         return arr[index];
//     }
//     else
//     {
//         int index1 = n/2;
//         int index2 = index1 - 1;
//         double mea = (arr[index1]+arr[index2])/2.0;
//         return mea;
//     }
// }

// double max(int* arr,int n)
// {
//     int max = arr[0];
//     int i = 0;
//     for(i=0;i<n;i++)
//     {
//         if(arr[i]>max)
//             max = arr[i];
//     }
//     return max;
// }


// int main(void)
// {
//     cout << "你想输入多少个整数" <<endl;
//     int n = 0;
//     cin >> n;
//     int* arr = new int[n];
//     int i = 0;
//     cout << "请依次输入数字" <<endl;
//     for(i=0;i<n;i++)
//     {
//         cin >> arr[i];
//     }
//     double aveVal = ave(arr,n);
//     double meaVal = mea(arr,n);
//     double maxVal = max(arr,n);
//     cout << "平均数为" << aveVal <<endl;
//     cout << "中位数为" << meaVal <<endl;
//     cout << "最大值为" << maxVal <<endl;
//     return 0;

// }


// 模板函数：接收任意大小的字符数组引用，升序排序
template <int N>  // N为数组大小，由编译器自动推导
void sort(char (&arr)[N]) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // 测试1：大小为5的数组
    char chars1[5] = {'d', 'a', 'c', 'e', 'b'};
    cout << "排序前（数组1）：";
    for (int i = 0; i < 5; ++i) cout << chars1[i] << " ";
    cout << endl;
    sort(chars1);  // 编译器自动推导N=5
    cout << "排序后（数组1）：";
    for (int i = 0; i < 5; ++i) cout << chars1[i] << " ";
    cout << endl;

    // 测试2：大小为3的数组（验证通用性）
    char chars2[3] = {'z', 'a', 'm'};
    cout << "\n排序前（数组2）：";
    for (int i = 0; i < 3; ++i) cout << chars2[i] << " ";
    cout << endl;
    sort(chars2);  // 编译器自动推导N=3
    cout << "排序后（数组2）：";
    for (int i = 0; i < 3; ++i) cout << chars2[i] << " ";
    cout << endl;

    return 0;
}