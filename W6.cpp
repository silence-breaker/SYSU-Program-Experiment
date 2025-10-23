#include <iostream>
using namespace std;
//Q1
/*
double calculate_area(double r)
{
    return 3.14*r*r;
}

double calculate_circumference(double r)
{
    return 2*3.14*r;
}

double calculate_diameter(double r)
{
    return 2*r;
}

int main(void)
{
    double radius = 0;
    cout << "请输入圆的半径:\n";
    cin >> radius;

    double area = calculate_area(radius);
    double circumference = calculate_circumference(radius);
    double diameter = calculate_diameter(radius);

    cout << "圆的面积是: " << area << endl;
    cout << "圆的周长是: " << circumference << endl;
    cout << "圆的直径是: " << diameter << endl;

    return 0;
}
*/

//Q2
/*
double Max(double a, double b,double c)
{
    if(a>b && a>c)
        return a;
    else if(b>c)
        return b;
    else
        return c;
}

int main(void)
{
    double a, b, c;
    cout << "请输入三个数:\n";
    cin >> a >> b >> c;

    double max = Max(a, b, c);
    cout << "最大值是: " << max << endl;

    return 0;
}
*/

//Q3
/*
#include <cmath>
double calculate_function(double x, int n)
{
    if(n == 1)
    {
        return sqrt(x);
    }
    else
    {
        double y = sqrt(x + calculate_function(x, n - 1));
        return y;
    }
}

double calculate_circle_function(double x, int n)
{
    int i = 0;
    double y = sqrt(x);
    
    for(i=1;i<n;i++)
    {
        y = sqrt(x + y);
    }
    return y;
}

int main(void)
{
    double x;
    int n;
    cout << "请输入x的值:\n";
    cin >> x;
    cout << "请输入n的值:\n";
    cin >> n;

    double result_recursive = calculate_function(x, n);
    double result_iterative = calculate_circle_function(x, n);

    cout << "递归计算结果: " << result_recursive << endl;
    cout << "迭代计算结果: " << result_iterative << endl;

    return 0;
}
*/

//Q4
/*
int isLeap(int year)
{
    if((year%4==0 && year%100!=0) || (year%400==0))
        return 1;
    else
        return 0;
}

int main(void)
{
    int year1, year2;
    cout << "请输入起始年份和结束年份（每个年份在1000年到3000年之间:\n";
    cin >> year1 >> year2;
    int count = 0;
    int i = 0;
    for (i = year1; i <= year2; i++)
    {
        if(isLeap(i))
        {
            
            count++;
        }
    }
    cout << "闰年总数: " << count << endl;
}
*/

//Q5
/*
#include <cmath>
int isPrime(int n)
{
    if(n<=1)
        return 0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int m, n;
    cout << "请输入两个正整数m和n（m<n):\n";
    cin >> m >> n;
    
    int count = 0;
    for(int i=m;i<=n;i++)
    {
        if(isPrime(i))
        {
            
            count++;
        }
    }
    cout << "范围内的素数总数: " << count << endl;
    return 0;
}
*/

//Q6
#include <cmath>
int isPrime(int n)
{
    if(n<=1)
        return 0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int count_twinPrime(int m,int n)
{
    int i = 0;
    int count = 0;
    int Max = 0;
    int temp = 0;
    for(i=m;i<=n-2;i++)
    {
        if(isPrime(i) && isPrime(i+2))
        {
            count++;
            if(Max<(i-temp))
                Max = i - temp;
            
            temp = i;
        }
    }
    cout << "最大距离为: " << Max << endl;
    return count;
}

int main(void)
{
    cout << "请输入两个正整数m和n（m<n):\n";
    int m, n;
    cin >> m >> n;
    int total = count_twinPrime(m, n);
    cout << "范围内的孪生素数对总数: " << total << endl;
    return 0;
}