#include <iostream>
#include <conio.h>
#include <string>
#include "sentences.cpp"
#include<sys/time.h>
using namespace std;
long getTime(){
    struct timeval start;
    gettimeofday(&start ,NULL);
    return start.tv_sec*1000000 + start.tv_usec;
}

int getString(string s)
{
    int ch, cnt = 0, n = s.length(), spaceCnt=0, prev=100;
    for (int i = 0; i < s.length(); i++)
    {
        ch = getch();
        if (ch == s[i])
        {
            cout << s[i];
            if(s[i] == ' ')
                spaceCnt++;
        }
        else
        {
            i--;
            cnt++;
        }
    }
    // cout<<"You pressed "<<cnt<<" wrong key\n";
    float acc = float(n -cnt) / (float)n;
    cout << "\n\n\nYou have completed the race with a accuracy of " << acc * 100.0 << endl;
    return spaceCnt;
}

int main()
{
    string st = TakeString();
    cout << endl<< endl<< st<< endl<<endl;
    long start = getTime();
    int word = getString(st)+1;
    long end = getTime();

    // Calculating total time taken by the program.
    int timeTaken =(end - start)/1000000;
    cout<<"Your speed is "<<(word/(float)timeTaken)*60 <<" WPM \n";
    getch();
    return 0;
}