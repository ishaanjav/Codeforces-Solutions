
#include<iostream>

using namespace std;
#include<vector>
int main(){
	long long n;
	cin >> n;

	vector<long long> funkies;
	long long exp = 0;
	long long c = 0;
	while(exp < n){
		c++;
		exp = c * (c + 1)/2;
		funkies.push_back(exp);
	}
if(n == 1){
	cout <<"NO";
	return 0;
}
bool possible = false;
	for(int i = 0; i < funkies.size() - 1; i++){
		for(int j = i ; j < funkies.size(); j++)
			if(funkies[i] + funkies[j] == n){
				possible = true;
				//cout << funkies[i] << " " << funkies[j] <<endl;
				break;
			}
			if(possible) break;
	}

	cout << (possible ? "YES" : "NO");

}
