#include<iostream>
#include<algorithm>
using namespace std;

void printing(string s ){
	for(int i = 0 ; i < s.size() ; i++){
		if(i == 0 && isupper(s[i])){
			cout << s[i];
			continue;
		}
		else if(isupper(s[i])){
			cout << endl;
			cout << s[i];
			continue;
		}
		else{
			cout << s[i];

		}
	}
}
int main() {
	string s;
	cin >> s ;

	printing(s);
	return 0;
}