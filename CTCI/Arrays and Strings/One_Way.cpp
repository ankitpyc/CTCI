//Program to convert  a Url to


#include <bits/stdc++.h>
using namespace std;

bool is_one_place(string s1, string s2) {
	if (s1.length() == s2.length()) {
		auto it = s1.begin();
		auto jt = s2.begin();
		bool vare = false;
		while (it != s1.end()) {
			if (*it == *jt) {
				it++;
				jt++;
			}
			else {
				if (*it != *jt && !vare) {
					it++; jt++;
					vare = true;
					continue;

				} else {
					return false;
					break;
				}

			}
			/* code */
		}
		return true;

	}
	else {
		if ((abs(s1.length() - s2.length()) == 1)) {

			auto it = s1.begin();
			auto jt = s2.begin();
			while (it != s1.end()) {
				if (*jt ==  *it) {
					it++ ;
					jt++;
					continue;
				} else {
					if (*(it + 1) == *jt ) {
						it++;
						continue;
					}
					else {
						return false;
					}
				}
			}
			return true;

		}
	}
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2, str2, str1;
	cin >> s1 >> s2;

	if (s1.length() >= s2.length()) {
		str1 = s1;
		str2  = s2;
	}
	else {
		str2 = s1;
		str1  = s2;
	}

	if (is_one_place(str1, str2)) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";

	}
	return 0;
}