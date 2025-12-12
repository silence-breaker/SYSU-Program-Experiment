#include <iostream>
#include <cstring>  // 用于字符数组操作（strcpy）
using namespace std;

// // 定义student类
// class Student {
// private:
//     // 成员变量：字符数组存储个人信息，整型存储总成绩
//     char name[20];    // 姓名
//     char cls[15];     // 班级（避免与关键字class冲突，命名为cls）
//     char gender[5];   // 性别
//     char addr[50];    // 家庭住址
//     int totalScore;   // 总成绩

// public:
//     // 构造函数：初始化成员变量为默认值
//     Student() {
//         strcpy(name, "未知");
//         strcpy(cls, "未知");
//         strcpy(gender, "未知");
//         strcpy(addr, "未知");
//         totalScore = 0;
//     }

//     // 析构函数：释放资源（此处字符数组为栈内存，无动态资源需释放）
//     ~Student() {
//         cout << "Student对象已销毁" << endl;
//     }

//     // insert函数：添加个人信息
//     void insert(const char* n, const char* c, const char* g, const char* a, int s) {
//         strcpy(name, n);
//         strcpy(cls, c);
//         strcpy(gender, g);
//         strcpy(addr, a);
//         totalScore = s;
//     }

//     // chang函数：修改个人信息
//     void chang(const char* n, const char* c, const char* g, const char* a, int s) {
//         // 逻辑与insert一致，覆盖原有信息
//         strcpy(name, n);
//         strcpy(cls, c);
//         strcpy(gender, g);
//         strcpy(addr, a);
//         totalScore = s;
//     }

//     // display函数：显示个人信息
//     void display() {
//         cout << "姓名：" << name << endl;
//         cout << "班级：" << cls << endl;
//         cout << "性别：" << gender << endl;
//         cout << "家庭住址：" << addr << endl;
//         cout << "总成绩：" << totalScore << endl;
//     }
// };

// // 测试main函数
// int main() {
//     // 创建Student对象
//     Student stu;

//     // 测试insert函数：添加信息
//     cout << "=== 初始添加信息 ===" << endl;
//     stu.insert("张三", "高一(1)班", "男", "北京市海淀区XX路XX号", 580);
//     stu.display();

//     // 测试chang函数：修改信息
//     cout << "\n=== 修改后信息 ===" << endl;
//     stu.chang("李四", "高一(2)班", "女", "上海市浦东新区XX路XX号", 620);
//     stu.display();

//     return 0;
// }


//Q2

class Block{
    private:
        double length;
        double width;
        double height;
    public:
        Block(){length = 0;width = 0;height = 0;}
        ~Block(){cout<<"消除数据"<<endl;}
        void Set(double len, double wid, double hei)
        {
            length = len;
            width = wid;
            height = hei;
        }
        double volume()
        {
            double V = length*width*height;
            return V;
        }
        double surface()
        {
            double S = length*width*2+length*height*2+width*height*2;
            return S;
        
        }
};

int main(void)
{
    Block Box;
    Box.Set(1,2,4);
    double V = Box.volume();
    double S = Box.surface();
    cout << "箱子体积为" << V <<endl;
    cout <<"箱子表面积为" << S <<endl;
    return 0 ;
}