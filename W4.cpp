#include <iostream>
using namespace std;
#include <math.h>
#include <time.h>
/*
int calculate_factorial(int n)
{
    if(n <= 1)
        return 1;
    else
        return n * calculate_factorial(n - 1);
}

int calculate_factorial_plus(int n)
{
    int i = 0;
    int result = 0;
    for(i=0;i<n;i++)
    {
        result += calculate_factorial(i+1);
    }
    return result;

}

int main(void)
{
    int n;
    cout << "请输入一个整数" <<endl;
    cin >> n;
    int result = calculate_factorial_plus(n);
    cout << n << " 的阶乘的和为 " << result << endl;
    return 0;
}
*/
/*
int generate_number(void)
{
    srand(time(NULL));
    return rand() % 100 + 1;
}

int guess_number(int number, int guess)
{
    if(guess > number)
        return 1;
    else if(guess < number)
        return -1;
    else
        return 0;
}

int main(void)
{
    int number = generate_number();
    int guess;
    int result;
    int i = 0;
    cout << "我已经选择了一个1到100之间的数字，你能猜到它是什么吗？" << endl;
    do
    {
        cout << "请输入你的猜测：";
        cin >> guess;
        result = guess_number(number, guess);
        if(result == 1)
            cout << "太大了！" << endl;
        else if(result == -1)
            cout << "太小了！" << endl;
        else
            cout << "恭喜你，猜对了！" << endl;
        i++;
        
    }while(result != 0);
    cout << "你已经猜了 " << i << " 次。" << endl;
    return 0;
}
*/

/*
int score_transform(int score)
{
    if(score >= 90 && score <= 100)
        return 5;
    else if(score >= 80 && score < 90)
        return 4;
    else if(score >= 70 && score < 80)
        return 3;
    else if(score >= 60 && score < 70)
        return 2;
    else if(score >= 0 && score < 60)
        return 1;
}

int main(void)
{
    int score;
    cout << "请输入成绩：";
    cin >> score;
    int level = score_transform(score);
    cout << "成绩等级为：" << level << endl;
    return 0;
}
*/

// 计算实际年龄的程序
int calculate_age(int birth_year, int birth_month, int birth_day, 
                  int current_year, int current_month, int current_day)
{
    int age = current_year - birth_year;
    
    // 如果当前月份小于出生月份，或者月份相同但日期小于出生日期，年龄减1
    if (current_month < birth_month || 
        (current_month == birth_month && current_day < birth_day))
    {
        age--;
    }
    
    return age;
}

int main(void)
{
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;
    
    cout << "请输入你的出生日期（年 月 日）：";
    cin >> birth_year >> birth_month >> birth_day;
    
    cout << "请输入当前日期（年 月 日）：";
    cin >> current_year >> current_month >> current_day;
    
    int age = calculate_age(birth_year, birth_month, birth_day, 
                            current_year, current_month, current_day);
    
    cout << "你的实际年龄是：" << age << " 岁" << endl;
    
    return 0;
}

