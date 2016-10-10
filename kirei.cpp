#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み
#include <math.h>
#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

const int W = 400;
const int H = 400;

void display(void) {
	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear (GL_COLOR_BUFFER_BIT );     // 画面消去

//	glBegin(GL_LINE_LOOP);
//	glBegin(GL_LINES);
//	glBegin(GL_LINE_STRIP);
	glBegin(GL_POINTS);
	for(double i = -1.0 ; i <= 1.0; i += 2.0/W){
		for(double j = -1.0 ; j <= 1.0; j += 2.0/H){
			std::complex<double> c(i, j);
			std::complex<double> z(0, 0);
			int k = 0;
			for(k = 0; k < 100 & abs(z) < 2; k++){
				z = z*z + c;
			}
			if(abs(z) > 2){
				glColor3d(abs(z) - 2, arg(z)/(2*M_PI) + 0.5, k / 10.0);   // 色指定(R,G,B)で0～1まで
			}else{
				glColor3d(1.0, 1.0, 1.0);   // 色指定(R,G,B)で0～1まで
			}
			glVertex2d(i, j); 
		}
	}
	glEnd();

	glFlush(); // 画面出力
}

// メインプログラム
int main (int argc, char *argv[]) { 
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(W , H);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glViewport(0, 0, 400, 400);
	glutMainLoop();                 // イベント待ち
	return 0;
}

