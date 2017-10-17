//===================Program Checks if the two strings are permutations of each other 

#include <bits/stdc++.h>
using namespace std;



//First Method one sorting and comparing  



bool arePermutation(string str1,string str2){
string s1(str1);
string s2(str2);
if(str1.length() != str2.length()){
	return false;
}
else{
 	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1 == s2)
		return true;
	else
		return false;
}
}



//Second Method Implementation method Suggested by the BOOK i.e by Character Count


bool arePermutation2(string str1,string str2){
int count[128] = {0} ;
if(str1.length() != str2.length()){
	return false;
}
else{

for (int i = 0; i < str1.length(); i++)
{
	count[str1[i]]++;
	/* code */
}

for (int j = 0; j < str2.length(); j++)
{
	count[str2[j]]--;
	/* code */
}

for (int k = 0; k < 128 ; k++)
{
	if(count[k] != 0)
		return false;
	else
		continue;
	/* code */
}
}
return true;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2;
	cin>>s1>>s2;

	if(arePermutation(s1,s2)){
		cout<<"They are anagrams of each other\n";
	}
	else{
		cout<<"Sorry they are not anagrams of each other\n";	
	}

	//=========================Method 2 calling
	if(arePermutation2(s1,s2)){
		cout<<"They are anagrams of each other\n";
	}
	else{
		cout<<"Sorry they are not anagrams of each other\n";	
	}
	
	return 0;
}