#include<stdio.h>
#include<stdbool.h>

int move[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
bool vst[9][9];
int cnt = 0, step = 1;

bool ok(int x, int y){
	return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

void recurse(int x, int y)
{
	if (step == 64){
		printf("hi");
		return;
	}
	for (int i = 0; i < 8; ++i){
		//printf("i: %i", i);
		if (ok(x+move[i][0], y+move[i][1])){
			vst[x+move[i][0]][y+move[i][1]] = 1;
			recurse(x+move[i][0], y+move[i][1]);
			vst[x+move[i][0]][y+move[i][1]] = 0;
		}
	}
}

int main()
{
	vst[1][1] = 1;
	recurse(1, 1);
	return 0;
}