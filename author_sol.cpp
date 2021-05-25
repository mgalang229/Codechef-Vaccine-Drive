#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long g, p;
		cin >> g >> p;
		vector<long long> x(10);
		for (int i = 0; i < 10; i++) {
			cin >> x[i];
		}
		long long before_chef = 0;
		for (int i = g; i < 10; i++) {
			// calculate the number of people that will get vaccinated before chef
			before_chef += x[i];
		}
		auto GetDays = [&](long long people) {
			// calculate ceil('people' / 'p')
			return (people / p + (people % p != 0));
		};
		// minimum is equal to the total number of people that will get vaccinated
		// before chef plus one (if chef is the first person to get vaccinated) divided
		// by the number of vaccines per day
		long long mn = GetDays(before_chef + 1);
		// maximum is equal to the total number of people that will get vaccinated
		// before chef plus the number of people in chef's age group (if chef will get
		// vaccinated as the last person) divided by the number of vaccines per day
		long long mx = GetDays (before_chef + x[g - 1]);
		cout << mn << " " << mx << '\n';
	}
	return 0;
}
