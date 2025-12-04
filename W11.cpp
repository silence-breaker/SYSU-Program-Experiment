#include <iostream>
#include <string>
using namespace std;

// class Drink{
//     public:
//         string name;
//         double price;
//         unsigned long pro_date;
    
//         Drink(string N = "Coca-Cola",double P = 10,unsigned long D = 20251204)
//         {
//             name = N;
//             price = P;
//             pro_date = D;
//         }
//         void set(string N, double P, unsigned long D)
//         {
//             name = N;
//             price = P;
//             pro_date = D;
//         }
//         void display(void)
//         {
//             cout << "名称：" << name <<endl;
//             cout << "价格：" << price <<endl;
//             cout << "生产日期：" << pro_date <<endl;
//         }
// };



// Drink* list(Drink* drink,int n)
// {
//     int i = n;
//     int j = 0;
//     for(i=n-1;i>=0;i--)
//     {
//         for(j=0;j<n;j++)
//         {
//             if(drink[j].pro_date<drink[j+1].pro_date)
//             {
//                 Drink temp;
//                 temp = drink[j+1];
//                 drink[j+1] = drink[j];
//                 drink[j] = temp;
//             }
//             if(drink[j].pro_date==drink[j+1].pro_date)
//             {
//                 if(drink[j].name.size()>drink[j+1].name.size())
//                 {
//                     Drink temp;
//                     temp = drink[j+1];
//                     drink[j+1] = drink[j];
//                     drink[j] = temp;
//                 }
//                 if(drink[j].name.size()==drink[j+1].name.size())
//                 {
//                     if(drink[j].price>drink[j+1].price)
//                     {
//                         Drink temp;
//                         temp = drink[j+1];
//                         drink[j+1] = drink[j];
//                         drink[j] = temp;
//                     }
//                 }
//             }
//         }
//     }
//     return drink;
// }

// int main(void)
// {
//     int n = 0;
//     cout << "输入多少个饮料"<<endl;
//     cin >> n;
//     Drink* Sum = new Drink[n];
//     string name;
//     double price;
//     unsigned long pro_date;

//     int i = 0;
//     for(i=0;i<n;i++)
//     {
//         cout << "现在输入第"<<i+1<<"个饮料的信息（输入顺序为名字，价格，生产日期）"<<endl;
//         cin >> name >> price >> pro_date;
//         Sum[i].set(name,price,pro_date);
        
        
//     }

//     cout << "打印刚刚您输入的所有饮料的信息"<< endl;
//     for(i=0;i<n;i++)
//     {
//         Sum[i].display();
//     }

//     cout << "现在进行重新排列" << endl;
//     list(Sum,n);
//     cout << "打排列完毕，重新打印"<< endl;
//     for(i=0;i<n;i++)
//     {
//         Sum[i].display();
//     }
//     delete[] Sum;

// }

struct Node{
    int data;
    Node* next;
};

Node* createList()
{
    Node* head = nullptr;
    int x;
    int n = 0;
    cout << "请输入数据，-1结束" <<endl;
    while(cin >> x && x!=-1)
    {
        Node* node = new Node{x,head};
        head = node;
        n++;
    }
    cout << "你制造了" << n <<"个节点"<<endl;
    return head;
}
//最后填的节点是head
void print(Node* head)
{
    cout << "下面打印你输入的链表" <<endl;
    while(head)
    {
        cout << head->data <<endl;
        head = head->next;
    }
}


Node* insert(Node* head,int data,int n)
{
    
    Node *p = head;
    int count = 1;
    if(n==1)
    {
        Node* head_new = new Node{data,p};
        return head_new;
        
    }
    else{
       // 循环：找到第n-1个节点，且p不为空（避免越界）
        while (p != nullptr && count < n - 1) {
        p = p->next;      // 指针向后走，遍历链表
        count++;          // 计数器加1，记录当前位置
        }

        // 边界2：n超过链表长度（找不到第n-1个节点）
        if (p == nullptr) {
        cout << "插入失败：位置" << n << "超过链表长度！" << endl;
        return head;
        }
       
        Node* node = new Node{data,p->next};
        p->next = node;
        return head;
    }
    
}

Node* delete_from_last(int n, Node* head)
{
    
}

int main(void)
{
    Node* head = nullptr;
    head = createList();
    print(head);
    int n = 0;
    cout << "插入节点到第n个节点处"<<endl;
    cin >> n;
    int data = 0;
    cout << "插入数值为" <<endl;
    cin >> data;
    insert(head,data,n);
    print(head);
}