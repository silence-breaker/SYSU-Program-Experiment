#include <iostream>
#include <math.h>
using namespace std;

/* 
 * P1
*/
/*
int main(void)
{
    double ounce, metric_ton;
    while(1)
    {
        cout << "请输入一盒麦片的重量（单位为盎司）\n";
        cin >> ounce;
        metric_ton = ounce *(1.0/35273.92);
        cout << "该麦片的重量为 " << metric_ton << " 公吨\n";
    }

    return 0;
}
*/
/*
double guess_sqrt(double n)
{
    int i;
    double guess = 0;
    double r = 0;
    guess = n/2.0;
    for (i=0;i<10000;i++)
    {
        double temp = guess;
        r = n/guess;
        guess = (guess + r) / 2.0;
        if((fabs(guess - temp))/guess < 1e-2) //挑战性部分
            break;
    }
    return guess;  
}

int main(void)
{
    double n;
    cout << "请输入一个正数：";
    cin >> n;
    double sqrt = guess_sqrt(n);
    cout << n << " 的平方根为 " << sqrt << endl;
    return 0;
}
*/

/*
double time_change(double mph)
{
    return 3600.0 / mph;
}

int main(void)
{
    double mph;
    int minute;
    double second;
    cout << "请输入速度（单位为英里每小时）：";
    cin >> mph;
    double seconds = time_change(mph);
    minute = static_cast<int>(seconds/ 60.0);
    second = seconds - minute * 60.0;
    cout << mph << " 英里每小时的速度相当于 " << minute << " 分钟 " << second << " 秒每英里。\n";
    return 0;
}
*/
/*
struct Mad_Lib{
    char teaname[25];
    char yourname[25];
    char food[25];
    int number;
    char adjective[25];
    char color[25];
    char animal[25];

};
int print_out(Mad_Lib lib)
{
    cout << "亲爱的" << lib.teaname << "老师:" <<endl;
    cout << "\t对不起，我暂时交不了作业。我先是吃了一个烂掉的" << lib.food << ",我全身都变" << lib.color <<"了，感觉很糟糕，现在发烧" << lib.number << "度。然后我的" << lib.adjective <<"宠物" << lib.animal << "肯定是闻到了作业本上的"<< lib.food << "的味道，因为它居然把作业本给吃掉了。现在我在重新写作业，希望晚些时候能交上来"<<endl;
    cout << "你的忠实的" << lib.yourname << endl;

    return 0;
}

int main(void)
{
    Mad_Lib lib;
    cout << "请输入老师的名字：";
    cin >> lib.teaname;
    cout << "请输入你的名字：";
    cin >> lib.yourname;
    cout << "请输入食物：";
    cin >> lib.food;
    cout << "请输入100到120之间的一个数字：";
    cin >> lib.number;
    cout << "请输入形容词：";
    cin >> lib.adjective;
    cout << "请输入颜色：";
    cin >> lib.color;
    cout << "请输入动物：";
    cin >> lib.animal;
    print_out(lib);
    return 0;
}
*/

int main(void)
{
    double radius, vm; // 圆的半径和体积
    cout << "请输入球体半径：" << endl;
    cin >> radius; //输入半径
    vm = (4.0/3.0) * 3.1415 * radius * radius * radius; //计算球体体积
    cout << "球体的体积为：" << vm << endl;
    return 0;
}