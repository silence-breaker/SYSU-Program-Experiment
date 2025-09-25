#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//问题一
//1为R，2为S，3为P
//玩家为a,b
/*
char is_win(int a, int b)
{
    if (a == 1 && b == 3)
        return b;
    else if (a == 2 && b == 1)
        return b;
    else if (a == 3 && b == 2)
        return b;
    else if (a == b)
        return 0;
    else
        return a;
}

int main(void)
{
    int a, b;
    char i,j;
    cout << "请输入玩家一的手势:\n";
    cin >> i;
    cout << "请输入玩家二的手势:\n";
    cin >> j;
    if(i=='R'||i=='r')
        a=1;
    else if(i=='S'||i=='s')
        a=2;
    else
        a=3;
    if(j=='R'||j=='r')
        b=1;
    else if(j=='S'||j=='s')
        b=2;
    else
        b=3;      
    char res = is_win(a, b);
    if (res == 0)
        cout << "Draw" << endl;
    else if (res == a)
        cout << "A win" << endl;
    else
        cout << "B win" << endl;
    return 0;
}
*/
/*
//问题二
double calculate_interest(double principal)
{
    double rate;
    if(principal<=1000 && principal>=1)
    {
        rate = 1.5;
        return principal * rate * 0.01 ;
    }
    if(principal>1000)
    {
        rate = 1;
        double part1 = calculate_interest(1000);
        double part2 = (principal - 1000) * rate * 0.01;
        return part1 + part2;
    
    }
    return 0;
}

double calculate_min_payment(double money)
{
    if(money<10)
        return money;
    else if(money>=10 && money<100)
        return 10;
    else
        return money*0.1;
}

int main(void)
{
    double principal, interest, min_payment;
    while(1)
    {
        cout << "请输入本金:\n";
        cin >> principal;
        interest = calculate_interest(principal);
        cout << "利息为:\n" << interest << endl;
        cout << "总应付款为:\n" << principal + interest << endl;
        min_payment = calculate_min_payment(principal + interest);
        cout << "最小付款额为:\n" << min_payment << endl;
    }
  
    return 0;
}
*/
/*
//问题三 - 星座运势程序
#include <string>
#include <map>

struct Date {
    int month;
    int day;
    
    Date(int m, int d) : month(m), day(d) {}
};

struct Constellation {
    string name;
    Date start;
    Date end;
    string fortune;
    
    Constellation(string n, int sm, int sd, int em, int ed, string f) 
        : name(n), start(sm, sd), end(em, ed), fortune(f) {}
};

// 比较日期，返回day1是否在day2之前
bool isBeforeOrEqual(Date day1, Date day2) {
    if (day1.month < day2.month) return true;
    if (day1.month > day2.month) return false;
    return day1.day <= day2.day;
}

// 计算两个日期之间的天数差
int daysDifference(Date date1, Date date2) {
    // 简化版本，只考虑同月或相邻月份的情况
    if (date1.month == date2.month) {
        return abs(date1.day - date2.day);
    }
    
    // 月份相邻的情况
    int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 考虑闰年2月
    
    if (date1.month == 12 && date2.month == 1) {
        return (31 - date1.day) + date2.day;
    } else if (date1.month + 1 == date2.month) {
        return (daysInMonth[date1.month] - date1.day) + date2.day;
    } else if (date2.month + 1 == date1.month) {
        return (daysInMonth[date2.month] - date2.day) + date1.day;
    }
    
    return 999; // 返回大数表示相距很远
}

// 检查日期是否在星座范围内
bool isInConstellation(Date birthday, Constellation constellation) {
    if (constellation.start.month <= constellation.end.month) {
        // 正常情况，如3月21日~4月19日
        return (birthday.month > constellation.start.month || 
                (birthday.month == constellation.start.month && birthday.day >= constellation.start.day)) &&
               (birthday.month < constellation.end.month ||
                (birthday.month == constellation.end.month && birthday.day <= constellation.end.day));
    } else {
        // 跨年情况，如12月22日~1月19日
        return (birthday.month > constellation.start.month ||
                (birthday.month == constellation.start.month && birthday.day >= constellation.start.day)) ||
               (birthday.month < constellation.end.month ||
                (birthday.month == constellation.end.month && birthday.day <= constellation.end.day));
    }
}

int main() {
    // 初始化所有星座信息
    vector<Constellation> constellations = {
        Constellation("白羊座(Aries)", 3, 21, 4, 19, "今天适合开始新的计划，充满活力和创造力！"),
        Constellation("金牛座(Taurus)", 4, 20, 5, 20, "保持稳定的步调，财运方面会有不错的收获。"),
        Constellation("双子座(Gemini)", 5, 21, 6, 21, "沟通运佳，适合与朋友聚会或学习新知识。"),
        Constellation("巨蟹座(Cancer)", 6, 22, 7, 22, "家庭运势良好，适合与家人共度温馨时光。"),
        Constellation("狮子座(Leo)", 7, 23, 8, 22, "自信满满的一天，适合展现个人魅力和才华。"),
        Constellation("处女座(Virgo)", 8, 23, 9, 22, "注重细节会带来成功，工作运势上升。"),
        Constellation("天秤座(Libra)", 9, 23, 10, 22, "人际关系和谐，适合处理合作事务。"),
        Constellation("天蝎座(Scorpio)", 10, 23, 11, 21, "直觉敏锐，适合深入思考和研究。"),
        Constellation("射手座(Sagittarius)", 11, 22, 12, 21, "冒险精神旺盛，适合尝试新的挑战。"),
        Constellation("摩羯座(Capricorn)", 12, 22, 1, 19, "踏实努力会有回报，事业运势稳步上升。"),
        Constellation("水瓶座(Aquarius)", 1, 20, 2, 18, "创新思维活跃，适合参与团体活动。"),
        Constellation("双鱼座(Pieces)", 2, 19, 3, 20, "感性且富有想象力，艺术灵感丰富。")
    };
    
    cout << "=== 星座运势占卜程序 ===" << endl;
    cout << "请输入您的生日（月 日）：";
    
    int month, day;
    cin >> month >> day;
    
    Date birthday(month, day);
    
    // 查找对应的星座
    string currentConstellation = "";
    string currentFortune = "";
    vector<pair<string, string>> nearbyConstellations;
    
    for (const auto& constellation : constellations) {
        if (isInConstellation(birthday, constellation)) {
            currentConstellation = constellation.name;
            currentFortune = constellation.fortune;
            
            // 检查是否接近边界（1-2天）
            int startDiff = daysDifference(birthday, constellation.start);
            int endDiff = daysDifference(birthday, constellation.end);
            
            if (startDiff <= 2 || endDiff <= 2) {
                // 找到相邻的星座
                for (const auto& other : constellations) {
                    if (other.name != constellation.name) {
                        int otherStartDiff = daysDifference(birthday, other.start);
                        int otherEndDiff = daysDifference(birthday, other.end);
                        
                        if (otherStartDiff <= 2 || otherEndDiff <= 2) {
                            nearbyConstellations.push_back({other.name, other.fortune});
                        }
                    }
                }
            }
            break;
        }
    }
    
    if (currentConstellation.empty()) {
        cout << "输入的日期有误，请检查后重新输入。" << endl;
        return 1;
    }
    
    // 输出结果
    cout << "\n=== 占卜结果 ===" << endl;
    cout << "您的星座是：" << currentConstellation << endl;
    cout << "今日运势：" << currentFortune << endl;
    
    // 如果在交点附近，输出相邻星座信息
    if (!nearbyConstellations.empty()) {
        cout << "\n*** 特别提示 ***" << endl;
        cout << "您的生日位于星座交点附近，同时受到以下星座影响：" << endl;
        
        for (const auto& nearby : nearbyConstellations) {
            cout << "• " << nearby.first << endl;
            cout << "  运势：" << nearby.second << endl;
        }
    }
    
    return 0;
}
*/

//问题四
/*
#include <cctype>
enum date {mo,tu,we,th,fr,sa,su};//要记住枚举变量的用法
class Phonecall{
    private:
        
        int hour;
        int minute;
        int duration; //通话时长，单位为分钟
        date Day;
    public:
        Phonecall(date d, int h, int m, int du):hour(h),minute(m),duration(du),Day(d){}//初始化顺序最好要和声明顺序一致
        date getdate(){return Day;}
        int gethour(){return hour;}
        int getminute(){return minute;}
        int getduration(){return duration;}
       
};

float calculate_cost(Phonecall call)
{
    float cost;
    if(call.getdate()==sa || call.getdate()==su)
        cost=0.15*call.getduration();
    else
    {
        if(call.gethour()<8 || call.gethour()>18)
            cost=0.25*call.getduration();
        else
            cost=0.40*call.getduration();
    }
    return cost;
}

date str_to_date(string s)
{
    if(s=="mo"||s=="Mo"||s=="MO")
        return mo;
    else if(s=="tu"||s=="Tu"||s=="TU")
        return tu;
    else if(s=="we"||s=="We"||s=="WE")
        return we;
    else if(s=="th"||s=="Th"||s=="TH")
        return th;
    else if(s=="fr"||s=="Fr"||s=="FR")
        return fr;
    else if(s=="sa"||s=="Sa"||s=="SA")
        return sa;
    else
        return su;
}

int main(void)
{
    string d;
    int h,m,du;
    cout << "请输入通话日期(如Mo,Tu,We,Th,Fr,Sa,Su):\n";
    cin >> d;
    date D = str_to_date(d);
    cout << "请输入通话开始时间(时 分):\n";
    cin >> h >> m;
    cout << "请输入通话时长(分钟):\n";
    cin >> du;
    Phonecall call(D,h,m,du);
    float cost=calculate_cost(call);
    cout << "通话费用为:\n" << cost << endl;
    return 0;
}
*/
//问题五
/*
int calculate(double a, double b, double c)
{
    double x = b*b-4*a*c;
    if(x<0)
        return 0;
    else
        return 1;
}

int main(void)
{
    double a,b,c;
    double s1,s2;
    double real_part, imag_part;
    cout << "请输入一元二次方程的系数a,b,c:\n";
    cin >> a >> b >> c;
    if(calculate(a,b,c))
    {
        cout << "该方程有实根\n";
        s1=(-b+sqrt(b*b-4*a*c))/(2*a);
        s2=(-b-sqrt(b*b-4*a*c))/(2*a);
        cout << "实根为:\n" << s1 << " " << s2 << endl;
    }
        
    else
    {
        cout << "该方程无实根\n";
        real_part=-b/(2*a);
        imag_part=sqrt(-(b*b-4*a*c))/(2*a);
        cout << "复根为:\n" << real_part << "+" << imag_part << "i and " << real_part << "-" << imag_part << "i" << endl;
    }
        
    return 0;
}
*/

//问题六
/*
int main(void)
{
    int year;
    cout << "请输入一个年份(1000-3000):\n";
    cin >> year;
    int thousand = year/1000;
    int hundred = (year-1000*thousand)/100;
    int ten = (year-1000*thousand-100*hundred)/10;
    int one = year%10;
    cout << "该年份的罗马数字表示为:\n";
    for(int i=0;i<thousand;i++)
        cout << "M";
    if(hundred==9)
        cout << "CM";
    else if(hundred>=5 && hundred<9 && hundred!=4)
    {
        cout << "D";
        for(int i=0;i<hundred-5;i++)
            cout << "C";
    }
    else if(hundred==4)
        cout << "CD";
    else
    {
        for(int i=0;i<hundred;i++)
            cout << "C";
    }
    if(ten==9)
        cout << "XC";
    else if(ten>=5 && ten<9 && ten!=4)
    {
        cout << "L";
        for(int i=0;i<ten-5;i++)
            cout << "X";
    }
    else if(ten==4)
        cout << "XL";
    else
    {
        for(int i=0;i<ten;i++)
            cout << "X";
    }
    if(one==9)
        cout << "IX";
    else if(one>=5 && one<9 && one!=4)
    {
        cout << "V";
        for(int i=0;i<one-5;i++)
            cout << "I";
    }
    else if(one==4)
        cout << "IV";
    else
    {
        for(int i=0;i<one;i++)
            cout << "I";
    }
    cout << endl;
    return 0;
}
*/


//问题七
//2,2,3,4,5,6,7,8,9,t,j,q,k,a
/*
int count(char *symbel, int num)
{
    int count = 0;
    for(int i=0;i<num;i++)
    {
        if(symbel[i]=='2')
            count = count+2;
        else if(symbel[i]=='3')
            count = count+3;
        else if(symbel[i]=='4')
            count = count+4;
        else if(symbel[i]=='5')
            count = count+5;
        else if(symbel[i]=='6')
            count = count+6;
        else if(symbel[i]=='7')
            count = count+7; 
        else if(symbel[i]=='8')
            count = count+8;
        else if(symbel[i]=='9')
            count = count+9;
        else if(symbel[i]=='t'||symbel[i]=='T'||symbel[i]=='j'||symbel[i]=='J'||symbel[i]=='q'||symbel[i]=='Q'||symbel[i]=='k'||symbel[i]=='K')
            count = count+10;
        else if(symbel[i]=='a'||symbel[i]=='A')
        {
            count = count+11;
            if(count>21)
                count = count-10;
        }
           

    }
    return count;

}
int main(void)
{
    int num;
    cout << "请输入一个正整数:\n";
    cin >> num;
    char *symbel = new char[num];
    cout << "请依次输入每张牌的符号\n";
    for(int i=0;i<num;i++)
        cin >> symbel[i];
    int result = count(symbel,num);
    cout << "牌面总点数为:\n" << result << endl;
    if(result>21)
        cout << "爆牌\n";
    else if(result==21)
        cout << "Blackjack!\n";
    else
        cout << "继续要牌\n";
    delete[] symbel;
    return 0;
}
*/

//问题八
/*
double calculate_money(double principal, double rate, int years)
{
    int i = 0;
    int j = 0;
    // 修正：每月本金还款额应该根据输入的年限计算
    double monthly_principal = principal / (years * 12.0);
    double rest_money = principal;
    double total_interest = 0;
    
    for(i = 0; i < years; i++)
    {   
        double yearly_interest = 0; // 当年的利息
        
        for(j = 0; j < 12; j++)
        {
            if(rest_money <= 0)
                break;
                
            // 当月利息 = 剩余本金 * 月利率
            double monthly_interest = rest_money * rate / 12.0;
            yearly_interest += monthly_interest;
            total_interest += monthly_interest;
            
            // 更新剩余本金：减去每月固定的本金还款额
            rest_money -= monthly_principal;
            
            // 防止剩余本金为负数
            if(rest_money < 0)
                rest_money = 0;
        }
        
        if(rest_money <= 0)
            break;
            
        // 计算当年利息占原始贷款额的百分比
        double percentage = (yearly_interest / principal) * 100;
        cout << "第" << i+1 << "年的利息金额占原始贷款额的百分比为" << percentage << "%" << endl;
    }
    
    cout << "总利息为:\n" << total_interest << endl;
    return total_interest;
}

int main(void)
{
    double principal, rate;
    int years;
    cout << "请输入贷款本金:\n";
    cin >> principal;
    cout << "请输入年利率(如5表示5%):\n";
    cin >> rate;
    rate = rate/100.0;
    cout << "请输入贷款年限:\n";
    cin >> years;
    double interest = calculate_money(principal,rate,years);
    cout << "总还款金额为:\n" << principal + interest << endl;

    return 0;
}
*/

int main(void)
{
    int temp = 0;
    cout << "请输入希望的温度0-999" << endl;
    cin >> temp;
    int hundred = temp / 100;
    int ten = (temp - hundred * 100) / 10;
    int one = temp % 10;
    if(hundred==1||hundred==4||hundred==7)
    {
        temp = temp - 100;
    }
    if(ten==1||ten==4||ten==7)
    {
        temp = temp - 10;
    }
    if(one==1||one==4||one==7)
    {
        temp = temp - 1;
    }
    cout << "实际温度为" << temp << endl;
    return 0;
}