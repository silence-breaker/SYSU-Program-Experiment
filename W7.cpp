#include <iostream>
#include <cmath>
using namespace std;

//Q1
/*
double function(double x)
{
    double y = 2*(pow(x,2.0))+3*x+1;
    return y;
}

double inte_function(double x)
{
    return ((2/3.0)*pow(x,3.0)+(3/2.0)*pow(x,2.0)+x);
}
double calculate_integral_rectan()
{
    double x = 1;
    double dx = 0.001;
    double integral = 0;
    while(x<=3)
    {
        integral += function(x) * dx;
        x += dx;
    }
    return integral;
}

double calculate_integral_norm()
{
    
    return (inte_function(3)-inte_function(1));
}

int main(void)
{
    double result = 0;
    cout<<"计算函数y=2x^2+3x+1在[1,3]区间上的定积分"<<endl;
    cout <<"梯形法"<<endl;
    result = calculate_integral_rectan();
    cout << result << endl;
    cout <<"解析法"<<endl;
    result = calculate_integral_norm();
    cout << result << endl;
    return 0;
}
*/

//Q2
/*
double calculate_root(double a, double b, double c)
{
    double dis = b*b - 4*a*c;
    if(dis<0)
    {
        double real_part = -b/(2*a);
        double ima_part_1 = sqrt(-dis)/(2*a);
       

        cout << "此方程根为"<< real_part << " + " << ima_part_1 << "i 和 " << real_part << " - " << ima_part_1 << "i" << endl;
        return -1;
    }
    else if(dis==0)
    {
        double result = -b/(2*a);
        cout <<"此方程的根为"<< result <<endl;
        return 1;
    }
    else
    {
        double result_1 = (-b+sqrt(dis))/(2*a);
        double result_2 = (-b-sqrt(dis))/(2*a);
        cout <<"此方程的根为"<<result_1<<"和"<<result_2<<endl;
        return 0;
    }
}

int main(void)
{
    double a, b, c;
    cout << "请输入方程的系数a, b, c: ";
    cin >> a >> b >> c;
    calculate_root(a, b, c);
    return 0;
}
*/

//Q3

#include <iostream> // 用于标准输入输出 (cout, cin)
#include <cmath>    // 用于数学函数 (sqrt, fabs)
#include <iomanip>  // 用于设置输出精度 (setprecision)

// 使用 std 命名空间，避免重复写 std::
using namespace std;

// 定义一个足够小的精度，用于二分法判断
const double PRECISION = 1e-7;

/*
 * ===================================================================
 * 辅助函数：定义一元二次方程 f(x) = ax^2 + bx + c
 * ===================================================================
 */
 double f(double x, double a, double b, double c) {
     return a * x * x + b * x + c;
 }

 /*
  * ===================================================================
  * 题目 3: 二分法求解
  * ===================================================================
  */

 /**
 * @brief 二分法的核心实现
 * @param a, b, c 方程系数
 * @param low 搜索区间的下界
 * @param high 搜索区间的上界
 * @return 找到的实根
 */
double bisection_internal(double a, double b, double c, double low, double high) {
    // 检查并确保 low 处的函数值和 high 处的函数值异号
    if (f(low, a, b, c) * f(high, a, b, c) > 0) {
        // 这是一个理论上的错误，我们的主调用函数应该保证不会发生
        cout << "[错误] 二分法初始区间符号相同！" << endl;
        return 0; // 返回一个无效值
    }

    double mid = (low + high) / 2.0;

    // 当区间足够小，或中点值足够接近0时，停止迭代
    while (fabs(high - low) > PRECISION && fabs(f(mid, a, b, c)) > PRECISION) {
        
        // 判断根在哪个子区间
        if (f(mid, a, b, c) * f(low, a, b, c) < 0) {
            // 根在 [low, mid] 区间
            high = mid;
        } else {
            // 根在 [mid, high] 区间
            low = mid;
        }
        
        // 计算新的中点
        mid = (low + high) / 2.0;
    }
    return mid;
}

/**
 * @brief 题目3的主函数，用于寻找二分法区间并调用
 */
void bisection_solver(double a, double b, double c) {
    cout << "--- 3. 二分法求解 ---" << endl;

    // 情况 1: a = 0 (线性方程)
    if (fabs(a) < PRECISION) {
        if (fabs(b) < PRECISION) {
            if (fabs(c) < PRECISION) {
                cout << "方程为 0 = 0，有无穷多解。" << endl;
            } else {
                cout << "方程为 " << c << " = 0，无解。" << endl;
            }
        } else {
            // 线性方程可以直接求解，无需二分法
            cout << "线性方程，一个实根: x = " << -c / b << endl;
        }
        return; // 结束函数
    }

    // --- 以下是 a != 0 的二次方程情况 ---

    // 计算判别式
    double delta = b * b - 4 * a * c;

    // 情况 2: 判别式 < 0 (没有实根)
    if (delta < 0) {
        cout << "判别式 < 0，方程只有复根。" << endl;
        cout << "二分法不适用于求解复根。" << endl;
    } 
    // 情况 3: 判别式 = 0 (只有一个实根)
    else if (fabs(delta) < PRECISION) {
        // 这种情况二分法很难找到异号区间，我们直接返回解析解
        cout << "判别式 = 0，有一个实根 (二分法不适用):" << endl;
        cout << "  x1 = x2 = " << -b / (2 * a) << endl;
    } 
    // 情况 4: 判别式 > 0 (有两个实根)
    else {
        cout << "判别式 > 0，用二分法寻找两个实根:" << endl;

        // 两个根分布在抛物线对称轴的两侧
        double vertex_x = -b / (2.0 * a);
        double f_vertex = f(vertex_x, a, b, c);

        // --- 寻找第一个根 (在对称轴左侧) ---
        // 我们从对称轴开始向左搜索，直到找到一个点 f(x) 与 f(vertex_x) 异号
        // (f_vertex 是抛物线顶点的y值，它的符号与抛物线开口方向相关)
        double low = vertex_x - 1.0; // 初始猜测
        while (f(low, a, b, c) * f_vertex >= 0) {
            low = low - 10.0; // 扩大搜索步长
        }

        // --- 寻找第二个根 (在对称轴右侧) ---
        // 我们从对称轴开始向右搜索，直到找到一个点 f(x) 与 f(vertex_x) 异号
        double high = vertex_x + 1.0; // 初始猜测
        while (f(high, a, b, c) * f_vertex >= 0) {
            high = high + 10.0; // 扩大搜索步长
        }

        // 现在我们有了两个区间: [low, vertex_x] 和 [vertex_x, high]
        // 在这两个区间上分别执行二分法
        double root1 = bisection_internal(a, b, c, low, vertex_x);
        double root2 = bisection_internal(a, b, c, vertex_x, high);

        // 确保 x1 是较小的根
        if (root1 < root2) {
            cout << "  x1 (二分法) = " << root1 << endl;
            cout << "  x2 (二分法) = " << root2 << endl;
        } else {
            cout << "  x1 (二分法) = " << root2 << endl;
            cout << "  x2 (二分法) = " << root1 << endl;
        }
    }
}

double calculate_root(double a, double b, double c)
{
    double dis = b*b - 4*a*c;
    if(dis<0)
    {
        double real_part = -b/(2*a);
        double ima_part_1 = sqrt(-dis)/(2*a);
       

        cout << "此方程根为"<< real_part << " + " << ima_part_1 << "i 和 " << real_part << " - " << ima_part_1 << "i" << endl;
        return -1;
    }
    else if(dis==0)
    {
        double result = -b/(2*a);
        cout <<"此方程的根为"<< result <<endl;
        return 1;
    }
    else
    {
        double result_1 = (-b+sqrt(dis))/(2*a);
        double result_2 = (-b-sqrt(dis))/(2*a);
        cout <<"此方程的根为"<<result_1<<"和"<<result_2<<endl;
        return 0;
    }
}
/*
 * ===================================================================
 * Main 函数：用于测试
 * ===================================================================
 */
int main() {
    double a, b, c;
    
    cout << "请输入一元二次方程 ax^2 + bx + c = 0 的系数 a, b, c" << endl;
     cout << "(用空格隔开): ";
     cin >> a >> b >> c;

     // 设置输出精度为 7 位小数
     cout << fixed << setprecision(7);

     cout << "\n============================================" << endl;
     // 调用第三题的二分法求解器
     bisection_solver(a, b, c);
     cout<<"以下为解析法结果"<<endl;
     //调用第二题的解析法
    calculate_root(a,b,c);
    
    cout<<"解析法和二分法结果很相近"<<endl;
   

     return 0;
 }

//Q4

// int transmit10_2(int a)
// {
//     if(a == 0)
//         return 0;
//     else if(a == 1)
//         return 1;
//     else
//     {
//         return (a % 2) + 10 * transmit10_2(a / 2);
//     }
// }


// int main(void)
// {
//     int a = 0;
//     cout << "请输入一个十进制整数"<<endl;
//     cin >> a;
    
//     int result = transmit10_2(a);
//     cout<< "十进制转换结果为"<< result<<endl;
//     return 0;
// }