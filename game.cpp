#include<bits/stdc++.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
unsigned long long grid[4][4]={0};
int cnt_empty_grid = 16;
int main(){
	int score = 0;
	char dir;
	srand(time(NULL));
	while (cnt_empty_grid){
		//generate new blocks
		int gen = rand()%2 + 1;
		while (gen > cnt_empty_grid) gen = rand()%2 + 1;
		score ++;
		int x[gen];
		for (int i=0;i<gen;i++){
			x[i] = 2*((rand()%2)+1);
		}
		pair<int,int> pos[gen];
		for (int i=0;i<gen;i++){
			pos[i].first = rand()%4;
			pos[i].second = rand()%4;
			while ((i&&pos[i].first == pos[0].first &&pos[i].second == pos[0].second)||(grid[pos[i].first][pos[i].second])){
				pos[i].first = rand()%4;
				pos[i].second = rand()%4;
			}
			grid[pos[i].first][pos[i].second] = x[i];
		}
		printf("Score: %d\n", score);
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				printf("%5d ", grid[i][j]);
			}
			cout << endl;
		}
		//detect dir
		cin >> dir; // U, D, L, R
		//operate
		switch(dir){
			case 'L':{
				//"bubble" sort
				for (int i=0;i<4;i++){//row number
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[i][k] && grid[i][k+1]){
								swap(grid[i][k], grid[i][k+1]);
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[i][k] == grid[i][k+1]){
								score += grid[i][k];
								grid[i][k]*=2;
								grid[i][k+1] = 0;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[i][k] && grid[i][k+1]){
								swap(grid[i][k], grid[i][k+1]);
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[i][k] == grid[i][k+1]){
								score += grid[i][k];
								grid[i][k]*=2;
								grid[i][k+1] = 0;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[i][k] && grid[i][k+1]){
								swap(grid[i][k], grid[i][k+1]);
							}
						}
					}
				}
				break;
			}
			case 'R':{
				for (int i=0;i<4;i++){
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[i][k+1] && grid[i][k]){
								swap(grid[i][k], grid[i][k+1]);
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[i][k] == grid[i][k+1]){
								score += grid[i][k];
								grid[i][k] = 0;
								grid[i][k+1] *= 2;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[i][k+1] && grid[i][k]){
								swap(grid[i][k], grid[i][k+1]);
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[i][k] == grid[i][k+1]){
								score += grid[i][k];
								grid[i][k] = 0;
								grid[i][k+1] *= 2;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[i][k+1] && grid[i][k]){
								swap(grid[i][k], grid[i][k+1]);
							}
						}
					}
				}
				break;
			}
			case 'U':{
				for (int i=0;i<4;i++){ // column number
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[k][i] && grid[k+1][i]) swap(grid[k][i], grid[k+1][i]);
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] == grid[k+1][i]){
								score += grid[k][i];
								grid[k][i] *= 2;
								grid[k+1][i] = 0;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[k][i] && grid[k+1][i]) swap(grid[k][i], grid[k+1][i]);
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] == grid[k+1][i]){
								score += grid[k][i];
								grid[k][i] *= 2;
								grid[k+1][i] = 0;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (!grid[k][i] && grid[k+1][i]) swap(grid[k][i], grid[k+1][i]);
						}
					}
				}
				break;
			}
			case 'D':{
				for (int i=0;i<4;i++){ // column number
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] && !grid[k+1][i]) swap(grid[k][i], grid[k+1][i]);
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] == grid[k+1][i]){
								score += grid[k][i];
								grid[k][i] = 0;
								grid[k+1][i] *= 2;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] && !grid[k+1][i]) swap(grid[k][i], grid[k+1][i]);
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] == grid[k+1][i]){
								score += grid[k][i];
								grid[k][i] = 0;
								grid[k+1][i] *= 2;
							}
						}
					}
					for (int j=0;j<4;j++){
						for (int k=0;k<3;k++){
							if (grid[k][i] && !grid[k+1][i]) swap(grid[k][i], grid[k+1][i]);
						}
					}
				}
				break;
			}
			default:{
				break;
			}
		}
		//check
		int flag = 0;
		int cnt = 0;
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				if (grid[i][j] == 0) flag = 1;
				if (grid[i][j] == 0) cnt++;
				if (grid[i][j] == 2048){
					cout << "You win!!" << endl;
					return 0;
				}
			}
		}
		cnt_empty_grid = cnt;
		for (int i=0;i<50;i++) cout << '\n';
		PlaySound(TEXT("thud.wav"),NULL,SND_FILENAME);
	}
	cout << "You lose!" << endl;
	cout << "Final score: " << score << endl;
}
