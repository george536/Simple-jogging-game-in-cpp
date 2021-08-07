#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

using namespace std;
class Frog {
private:
	vector<int> x{}, y{};
	//int x_frog, y_frog,num,speed=100,random;
	int num,speed=100,random;
	vector<int> frog_bodyx, frog_bodyy;
	bool quit = false;
	int width, height;
public:
	Frog(int w,int h) {
		width = w; height = h;
		frog_bodyx = { 1,1,1 };
		frog_bodyy = { height - 1,height - 2,height - 3 };
		//x_frog = 1;
		//y_frog = height - 1;
	}
	void Draw() {
		system("cls");
		for (int i = 0; i < width+2;i++) {
			cout << "\xB2";
		}
		cout << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) {
					cout << "\xB2";
				}
				if (i == frog_bodyy[0] && j == frog_bodyx[0]) {
					cout << "\xBA";
				}
				else if (i == frog_bodyy[1] && j == frog_bodyx[1]) {
					cout << "\xDB";
				}
				else if (i == frog_bodyy[2] && j == frog_bodyx[2]) {
					cout << "O";
				}
				else {
					bool space = false;
					for (int k = 0; k < num; k++) {
						if (x[k] == j && y[k] == i) {
							cout << "\xDC";
							space = true;
						}
					}
					if (!space) {
						cout << " ";
					}
					if (j == width - 1) {
						cout << "\xB2";
					};
				}
			}
			cout << endl;
		}
		for (int i = 0; i < width + 2; i++) {
			cout << "\xB2";
		}
		cout << endl;

	}

	void Input() {
		if (_kbhit()) {
			switch (_getch()) {
			case 'w':
				for (int i = 0; i < frog_bodyy.size();i++) {
					frog_bodyy[i] -= 2;
				}
				//y_frog-=2;
				break;
			case 'a':
				for (int i = 0; i < frog_bodyx.size(); i++) {
					frog_bodyx[i] --;
				}
				//x_frog--;
				break;
			case 'd':
				for (int i = 0; i < frog_bodyx.size(); i++) {
					frog_bodyx[i] ++;
				}
				//x_frog++;
				break;
			case 'x':
				quit = true;
				break;
			}
		}
		else {
			frog_bodyy = { height - 1,height - 2,height - 3 };
			//y_frog= height - 1; 
		}
	}
	void Algorithm() {
		if (!x.empty()) {
			for (int i = 0; i < num; i++) {
				x[i]--;
			}
		}
		int temp = random;
		random = rand() % 5;
		if (random != temp) {
			if (random == 0) {
				x.push_back(width - 1);
				y.push_back(height - 1);
				num++;
			}
		}
		for (int z = 0; z < num;z++) {
			//if (x[z]==x_frog && y[z]==y_frog) {
			if (x[z] == frog_bodyx[0] && y[z] == frog_bodyy[0]) {
				cout << endl << "Game Over !"<<endl;
				quit = true;
			}
		}
		speed--;
	}
	void Run() {
		while (!quit){
			Draw();
			Algorithm();
			Input();
			
			Sleep(speed);
		}
	}
};

int main() {
	Frog game(50,5);
	game.Run();
	return 0;
};