#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
	string a,b;

	cout<<"입력1"<<endl; getline(cin,a);
	cout<<"입력2"<<endl; getline(cin,b);

	int* cnta = new int[26];
	int* cntb = new int[26];

	char* arra = (char*)a.c_str();
	char* arrb = (char*)b.c_str();

	if(strlen(arra) == strlen(arrb))
	{
		for(int i=0;i<strlen(arra);i++)
		{
			cnta[arra[i] - 'a']++;
			cntb[arrb[i] - 'a']++;
		}

		int x;

		for(x=0;x<26;x++)
		{
			if(cnta[x] != cntb[x])
			{
				cout<<"다름"<<endl;
				break;
			}
		}
		
		if(x == 26)
		{
			cout<<"같음"<<endl;
		}
	}
	
	else
	{
		cout<<"다름"<<endl;
	}

}
