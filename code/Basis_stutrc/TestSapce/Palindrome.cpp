#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x)
{
    if (x == 0)
        return true;
    if (x < 0 || x % 10 == 0)
        return false;
    int reverice = 0;
    while (x > reverice)
    {
        reverice = reverice * 10 + x % 10;
        x /= 10;
    }
    cout  << x << endl;
    cout  << reverice << endl;
    return (reverice == x) || (reverice /10 ==x);
}

int main()
{
    int temp = 121;
    if (isPalindrome(temp))
    {
        cout << temp << endl;
    }
  

    return 0;
}