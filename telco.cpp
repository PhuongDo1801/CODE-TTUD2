#include<bits/stdc++.h>
using namespace std;

long long total = 0;
int check = 1;
vector<string> phone;
map<string, int> number_calls; 
map<string, long long> time_calls;

bool checkPhone(string data) {
	int n = data.length();
	
	if (n != 10) return false;
	for (int i = 0; i < n; i++) {
		if (data[i] < '0' || data[i] > '9') {
			return false;
		}
	}
	return true;
}

long long countTime(string begin, string end) {
	long long b = 0, e = 0;
	
	b = ((int) begin[0] - 48)*36000 + ((int) begin[1] - 48)*3600 + ((int) begin[3] - 48)*600 + ((int) begin[4] - 48)*60 + ((int) begin[6] - 48)*10 + ((int) begin[7] - 48);
	e = ((int) end[0] - 48)*36000 + ((int) end[1] - 48)*3600 + ((int) end[3] - 48)*600 + ((int) end[4] - 48)*60 + ((int) end[6] - 48)*10 + ((int) end[7] - 48);
	return e - b;
}

void solve() {
	string tmp;
	
	getline(cin, tmp);	
	while (tmp != "#") {
		total++;
		string from_number = tmp.substr(5, 10);
		string to_number = tmp.substr(16, 10);
		string begin = tmp.substr(38, 8);
		string end = tmp.substr(47, 8);
		
		if (!checkPhone(from_number) || !checkPhone(to_number)) check = 0;
		
		if (find(phone.begin(), phone.end(), from_number) == phone.end()) {
			phone.push_back(from_number);
			number_calls[from_number] = 1;
			time_calls[from_number] = countTime(begin, end);
		} else {
			number_calls[from_number]++;
			time_calls[from_number] += countTime(begin, end);
		}
		
		getline(cin, tmp);
	}
	
	getline(cin, tmp);
	while (tmp != "#") {
		if (tmp == "?check_phone_number") cout << check << endl;
		else if (tmp.substr(0, 18) == "?number_calls_from") cout << number_calls[tmp.substr(19, 10)] << endl;
		else if (tmp == "?number_total_calls") cout << total << endl;
		else cout << time_calls[tmp.substr(23, 10)] << endl;
		
		getline(cin, tmp);
	}
}

int main() {
	solve();
    return 0;
}

