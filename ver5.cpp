#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string unit[] = { "십", "백", "천" };
    string big[] = { "만", "억", "조", "경", "해", "서", "양", "구", "간", "정", "재", "극", "항하사", "아승기", "나유타", "불가사의" };
    string number[] = { "일", "이", "삼", "사", "오", "육", "칠", "팔", "구" };
    char str[64];

    int u, b, length, i;
    int cnt = 0;

	cin>>str;
    length = strlen(str);
    b = (length - 1) / 4 - 1;
    u = (length % 4 == 0) ? 2 : length % 4 - 2;
    for(i = 0; i < length; i++)
    {
           if(str[i] != '0')
           {
                  //printf("%s", number[str[i] - '0' - 1]);
                  cout<<number[str[i] - '0' - 1]<<endl;
                  cnt++;
           }
           if(u < 0 && length > 0)
           {
                  if((cnt || i == 0) && b >= 0)
                  {
						 //printf("%s", big[b]);
						 cout<<big[b]<<endl;
                  }
                  b--;
                  cnt = 0;
                  u = 2;
           }
           else
           {
                  if(str[i] != '0')
                  {
                         //printf("%s", unit[u]);
                         cout<<unit[u]<<endl;

                  }
                  u--;
           }
    }
    puts("");
}
