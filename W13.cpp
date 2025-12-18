#include <iostream>
#include <cmath>
using namespace std;

//Q1

// enum summit {Mount_Everest, Aconcagua, Denali, Kilimanjaro, Mount_Elbrus,Mount_Vinson, Puncak_Jaya};

// int main(void)
// {
//     summit mount;
//     cout << "请输入一个山峰的编号（0-6）：";
//     int input;
//     cin >> input;
//     mount = static_cast<summit>(input); 
//     switch(mount)
//     {
//         case Mount_Everest:
//             cout << "珠穆朗玛峰，高度8848米" << endl;
//             break;
//         case Aconcagua:
//             cout << "阿空加瓜山，高度6960米" << endl;
//             break;
//         case Denali:
//             cout << "迪纳利山，高度6190米" << endl;
//             break;
//         case Kilimanjaro:
//             cout << "乞力马扎罗山，高度5895米" << endl;
//             break;
//         case Mount_Elbrus:
//             cout << "厄尔布鲁士山，高度5642米" << endl;
//             break;
//         case Mount_Vinson:
//             cout << "文森山，高度4892米" << endl;
//             break;
//         case Puncak_Jaya:
//             cout << "查亚峰，高度4884米" << endl;
//             break;
//         default:
//             cout << "无效的编号" << endl;
//             break;
//     }
// }

//Q2
//  int sum(int n)
//  {
//     if(n==1)
//         return 1;
//     else
//     {
//         return (n+sum(n-1));
//     }
//  }

//  int main(void)
//  {
//     cout << "请输入一个数字" <<endl;
//     int n = 0;
//     cin >> n;
//     int result = sum(n);
//     cout << "计算结果为" << result << endl;
//  }

//Q3

int cal(int n)
{
    if(n==0 || n==1)
        return 1;
    else
    {
        return(n*cal(n-1));
    }
}

double talar(int n,double x)
{
    if(n==1)
        return 1;
    else
    {
        return ((pow(x,n-1)/cal(n-1))+talar(n-1,x));
    }
}

int main(void)
{
  
    double x = 0;

    double result = 0;
    cout << "请输入e的x次方" <<endl;
    cin >> x;
    cout << "测试泰勒级数的精度有项数之间的关系" <<endl;
    result = talar(5,x);
    cout << "5项展开结果为 " << result << endl;
    result = talar(5,x);
    cout << "20项展开结果为 " << result << endl;
    result = talar(20,x);
    cout << "100项展开结果为 " << result << endl;
    result = talar(100,x);
 
}
