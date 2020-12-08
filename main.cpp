#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const string getRandomNum()
{
    string str = "0000";
    srand(time(0));
    str[0] = static_cast<char>(rand()%9 + 1) + 48;
    for(int i = 1; i < 4; ++i)
    {
        str[i] = static_cast<char>(rand()%10) + 48;
        for(int j = 0; j < i; ++j)
        {
            if(str[i] == str[j])
            {
                --i;
                break;
            }
        }
    }
    return str;
}
int testBull(const string &userNum, const string &conceivedNum)
{
    int bull = 0;
    for(size_t i = 0; i < conceivedNum.length(); ++i)
    {
        if(userNum[i] == conceivedNum[i])
            ++bull;
    }
    return bull;
}
int testCow(const string &userNum, const string &conceivedNum)
{
    int cow = 0;
    for(size_t i = 0; i < userNum.length(); ++i)
    {
        for(size_t j = 0; j < conceivedNum.length(); ++j)
        {
            if(i == j)
                continue;
            if(userNum[i] == conceivedNum[j])
            {
                ++cow;
                break;
            }
        }
    }
    return cow;
}
int main()
{
    string conceivedNumber = getRandomNum();
    string userNumber;
    int count = 0;
    do
    {
        ++count;
        cout << "Try No. " << count << ". Enter a 4-digit number. To quit the game, enter 0." << endl;
        cin >> userNumber;
        if(userNumber == "0")
        {
            cout << "You are out of the game, we will be glad to see you again." << endl;
            break;
        }
        if(userNumber.length() != 4)
            continue;
        int bulls = testBull(userNumber, conceivedNumber);
        int cows = testCow(userNumber, conceivedNumber);
        if (bulls == 4)
        {
            cout << "Congratulations! You guessed the number!" << endl;
            cout << "Attempts = " <<  count << endl;
            break;
        }
        else
        {
            cout << "bulls = " <<  bulls << endl;
            cout << "cows = " <<  cows << endl;
        }
    } while (1);
    return 0;
}
