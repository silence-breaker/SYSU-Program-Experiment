#include <iostream>
using namespace std;
/*计算豌豆数量
int main(void)
{
    cout << "Hello";
    int number0fPods, peasPerPod, totalPeas;
    cout<<"Press return after entering a number.\n";
    cout<<"Enter the number of pods:\n";
    cin>>number0fPods;
    cout<<"Enter the number of peas in a pod:\n";
    cin>>peasPerPod;
    totalPeas=number0fPods+peasPerPod;
    cout<<"If you have ";
    cout <<number0fPods;
    cout << " pea pods\n";
    cout << "and ";
    cout << peasPerPod;
    cout << " peas in each pod, then\n";
    cout << "you have ";
    cout << totalPeas;
    cout << " peas in all the pods.\n";
    cout << "Good-bye\n";
    return 0;
}
*/
int main(void)
{
    double width, height, totalLength;
    cout << "Enter the width of the rectangle: \n";
    cin >> width;
    cout << "Enter the height of the rectangle: \n";
    cin >> height;
    totalLength=2*(width+height);
    cout << "So the total length of the rectangle is ";
    cout << totalLength;
    cout << "\n";
    cout << "So the total length of the rectangle is " << totalLength << "\n";

    return 0;
}