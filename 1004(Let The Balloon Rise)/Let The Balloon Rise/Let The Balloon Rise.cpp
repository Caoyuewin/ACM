#include <iostream>
#include <string>
#include <map>


using namespace std;


int main() {
	int N;
	while (cin >> N) {
		if (N == 0)
			break;
		string str;
		map<string, int> m;
		while (N) {
			cin >> str;
			auto it = m.insert(pair<string, int>(str, 1));
			if (it.second == false) {
				m[str]++;
			}
			N--;
		}
		str = m.begin()->first;
		for (auto getmax_it = m.begin(); getmax_it != m.end(); ++getmax_it) {
			if (getmax_it->second > m[str]) {
				str = getmax_it->first;
			}
		}
		cout << str << endl;
	}
	
	return 0;
}