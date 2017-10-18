//Program to convert  a Url to


#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1;
	string str_space("%20");
	getline(cin,s1);
	auto it = s1.begin();
	for (;it != s1.end();)
	{
		if(*it == ' '){
			s1.erase(it);
			s1.insert(it,str_space.begin(),str_space.end());
			it+=3;
		}else{
			it+=1;
		}
		/* code */
	}
	cout<<s1<<"\n";



	return 0;
}