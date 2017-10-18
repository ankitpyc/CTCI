//Program to convert  a Url to
#include <bits/stdc++.h>
using namespace std;

bool is_len_changed(string s1) {
	string s2 = "";
	char c = s1[0];
	int count = 1;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i + 1] == c) {
			count++;
		}
		else {
			s2 += (s1[i] + to_string(count));
			c = s1[i + 1];
			count = 1;
		}


	}
	if (s1.length() > s2.length())
		return true;
	else
		return false;

}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1;
	cin >> s1;
	if (is_len_changed(s1)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}