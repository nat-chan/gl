#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み
#include <math.h>
#include <vector>

std::vector<std::vector<double>>  v{{-1,0},{1,0}};

for(int i=0;i<v.size();i++) {
	v[i]
}

std::vector<std::vector<double>> koch(std::vector<std::vector<double>> v){
	return v;
}

// 表示部分をこの関数で記入
void display(void) {
	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear (GL_COLOR_BUFFER_BIT );     // 画面消去

	glColor3d(0.0, 0.0, 0.0);   // 色指定(R,G,B)で0～1まで
	glBegin(GL_LINES);
	for(int i = 0; i < 360; i++) {
		double x1 = cos(i * 3.14159 /180.0);
		double y1 = sin(i * 3.14159 /180.0);
		double x2 = cos(2 * i * 3.14159 /180.0);
		double y2 = sin(2 * i * 3.14159 /180.0);
        glVertex2d(x1 * 0.6, y1 * 0.6); 
        glVertex2d(x2 * 0.6, y2 * 0.6); 
	}
	glEnd();

	glFlush(); // 画面出力
}

// メインプログラム
int main (int argc, char *argv[]) { 
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(400 , 400);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glutMainLoop();                 // イベント待ち
	return 0;
}

