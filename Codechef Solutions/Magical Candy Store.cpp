#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define MOD 1000000007

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, i;
		cin >> n;
		vector<ll> a(n);
		ll idx = -1;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1)
				idx = i;
			//checking if 1 is present
		}

		if (n == 1) {
			// single element
			ll q;
			cin >> q;
			while (q--) {
				ll r;
				cin >> r;
				if (a[0] % 2)
					cout << mul(r , a[0]) << "\n";
				else {
					r--;
					ll ans = mul(r , (a[0] - 1));
					ans = add(ans, a[0]);
					cout << ans << "\n";
				}
			}
		}
		else if (idx == -1) {
			// no 1 in the array
			vector<ll> pref(n);
			ll sum = 0;
			for (i = 0; i < n; i++) {
				if ((i == n - 1 && a[i] % 2 == 0) || (i != n - 1 && a[i] % 2))
					sum = add(sum, a[i] - 1);
				else
					sum = add(sum, a[i]);
				pref[i] = sum;
			}
			ll q;
			cin >> q;
			while (q--) {
				ll r;
				cin >> r;
				r--;
				ll d = r / n;
				ll ans = mul(d, pref[n - 1]);
				ans = add(ans, pref[r % n]);
				if ((r + 1) % n == 0 && a[n - 1] % 2 == 0)
					ans++;
				else if (a[r % n] % 2 && r % n != n - 1)
					ans++;
				cout << ans << "\n";
			}
		}
		else {
			if (idx == 0) {
				// at the beginning
				ll q;
				cin >> q;
				while (q--) {
					ll r;
					cin >> r;
					r--;
					ll d = r / n;
					if (d == 0)
						cout << "1\n";
					else if ((r + 1) % n == 1)
						cout << d << "\n";
					else
						cout << d + 1 << "\n";
				}
			}
			else if (idx == n - 1) {
				// at the end
				vector<ll> pref(n);
				ll sum = 0;
				for (i = 0; i < n; i++) {
					if (i != n - 1 && a[i] % 2)
						sum = add(sum, a[i] - 1);
					else
						sum = add(sum, a[i]);
					pref[i] = sum;
				}

				ll q;
				cin >> q;
				while (q--) {
					ll r;
					cin >> r;
					r--;
					ll d = r / n;
					ll ans = mul(d, pref[n - 1]);
					ans = add(ans, pref[r % n]);
					if (a[r % n] % 2 && a[r % n] != 1)
						ans++;
					cout << ans << "\n";
				}
			}
			else {
				// in the middle somewhere
				vector<ll> pref(n);
				ll sum = 0;
				for (i = 0; i < n; i++) {
					if (a[i] == 1)
						sum += 0;
					else if (a[i] % 2 && i == idx - 1)
						sum = add(sum, a[i]);
					else if (a[i] % 2 == 0 && i == idx - 1)
						sum = add(sum, a[i] - 1);
					else if (a[i] % 2 && i == n - 1)
						sum = add(sum, a[i]);
					else if (a[i] % 2 == 0 && i == n - 1)
						sum = add(sum, a[i] - 1);
					else if (a[i] % 2)
						sum = add(sum, a[i] - 1);
					else
						sum = add(sum, a[i]);
					pref[i] = sum;
				}

				ll q;
				cin >> q;
				while (q--) {
					ll r;
					cin >> r;
					r--;
					ll d = r / n;
					ll ans = mul(d, pref[n - 1]);
					ans = add(ans, pref[r % n]);
					if (r % n == idx - 1 && a[idx - 1] % 2 == 0)
						ans++;
					else if (r % n == idx && a[idx - 1] % 2 == 0)
						ans += 2;
					else if ((r + 1) % n == 0 && a[n - 1] % 2 == 0)
						ans++;
					else if (a[r % n] % 2 && a[r % n] != 1 && r % n != idx - 1 && r % n != n - 1)
						ans++;
					cout << ans << "\n";
				}
			}
		}
	}
}
