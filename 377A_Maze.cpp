using namespace std;
#include<iostream>
#include <queue>
int xs[] = {0, 0, 1 , -1};
int ys[] = {1, -1, 0, 0};
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	char grid[n][m];
	bool visited[n][m];

	int sR, sC;
	int s = 0;
	for(int i =0 ; i < n; i++) for(int j = 0; j < m; j++) {cin >> grid[i][j]; if(grid[i][j] == '.'){s ++;sR = i, sC = j;} visited[i][j] =false;}
	
	queue<pair<int, int > > q;
	
	q.push(make_pair(sR, sC));
	
	int visitedCount = 0;
	while(!q.empty()){
		pair<int, int > p = q.front();
		q.pop();

		if(visited[p.first][p.second]) continue;
		visitedCount++;

		visited[p.first][p.second] = 1;

		if(visitedCount > s - k) grid[p.first][p.second] = 'X';
		
		for(int i =0 ; i < 4; i++){
			int x = p.first + xs[i];
			int y = p.second + ys[i];
			if(x <0 || y <0 || x == n || y== m) continue;

			if(!visited[x][y] && grid[x][y] == '.') q.push(make_pair(x, y));
		}
		

	}
for(int i =0 ; i < n; i++){
	for(int j = 0; j < m; j++) cout << grid[i][j]; cout << endl;}


}