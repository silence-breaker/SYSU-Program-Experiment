#include <iostream>
using namespace std;
#include <math.h>

//Q1
// double calculate(int n)
// {
//     double result = 0.0;
//     for(int i = 1; i <= n; i++)
//     {
//         result += pow(-1, i-1) * 1.0 / i;
//     }
//     return result;
// }

// int main(void)
// {
//     int n = 0;
//     double result = 0.0;
//     while (true)
//     {
//         result = calculate(n);
//         if(fabs(result - 0.693) < 0.0001)
//             break;
//         n++;
        
//     }
//     cout << "n = " << n << ", result = " << result << endl;
// }

//Q2
//应用二分法在区间(a,b)求解多项式方程的根
// double f(double x)
// {
//     return 2*pow(x,3)-2*pow(x,2)-6*x-3;
// }

// double bisection(double a,double b)
// {
//     double mid = 0.0;
    
//     if(f(a)*f(b)>0)
//     {
//         cout << "该函数在此区间可能没有根，或者有偶数个根"<<endl;
//         return -1;
//     }
//     else
//     {
//         while(fabs(a-b)>0.0001)
//         {
//             mid = (a+b)/2.0;
//             if(f(a)*f(mid)<0)
//             {
//                 b = mid;
//             }
                
//             else if(f(b)*f(mid)<0)
//             {
//                 a = mid;
//             }

//             else if(f(mid)==0)
//             {
//                 return mid;
//             }
                

//         }
//         return a;
//     }
// }

// int main(void)
// {
//     double result = bisection(-10,10);
//     cout << "f(x)=2*pow(x,3)-2*pow(x,2)-6*x-3在(-10,10)的根为" << result <<endl;
// }

//Q3
//输入一批字符，统计大写字母、小写字母、数字和其他字符的个数
class CharacterCounter
{
    private:
        int upper_count;
        int lower_count;
        int digit_count;
        int other_count;
    public:
        CharacterCounter(): upper_count(0), lower_count(0), digit_count(0), other_count(0) {}
        void count(char c)
        {
            if(c >= 'A' && c <= 'Z')
                upper_count++;
            else if(c >= 'a' && c <= 'z')
                lower_count++;
            else if(c >= '0' && c <= '9')
                digit_count++;
            else
                other_count++;
        
            }
        void display()
        {
            cout << "大写字母个数：" << upper_count << endl;
            cout << "小写字母个数：" << lower_count << endl;
            cout << "数字个数：" << digit_count << endl;
            cout << "其他字符个数：" << other_count << endl;
        }
};


int main(void)
{
    CharacterCounter counter;
    char c;
    cout << "请输入一批字符，输入'#'结束：" << endl;
    while(true)
    {
        cin.get(c);
        if(c == '#')
            break;
        counter.count(c);
    }
    counter.display();
    return 0;
}