#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み
#include <math.h>
#include <vector>
#include <complex>
#include <iostream>
/* Mandelbrot setをOpenGLで鑑賞する
 * 左クリック:クリック位置を中央にして2倍拡大
 * 右クリック:同様に4倍縮小
 */
const int W = 400; //画面サイズ
const int H = 400;
std::complex<double> zoom(0.7, 0.0);      //拡大率
std::complex<double> center(-0.6, 0.0);   //中心座標

void display(void){                   //表示関数
	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear (GL_COLOR_BUFFER_BIT );     // 画面消去
	glBegin(GL_POINTS);
	for(double i = -1.0 ; i < 1; i += 2.0/W){
		for(double j = -1.0 ; j < 1.0; j += 2.0/H){
			std::complex<double> c(i, j);
			c = c/zoom + center; //正規化座標系から投射
			std::complex<double> z(0, 0);
			int k = 0; //abs(z)>2を超えたら必ず発散する
			for(k = 0; k < 100 & abs(z) < 2; k++){
				z = z*z + c; //漸化式
			}
			if(abs(z) > 2){
				//r:絶対値, g:偏角, b:発散の速さ
				glColor3d(abs(z) - 2, arg(z)/(2*M_PI) + 0.5, k / 10.0);
			}else{
				glColor3d(0.0, 0.0, 0.0);
			}
			glVertex2d(i, j); 
		}
	}
	glEnd();
	glFlush(); // 画面出力
}

void mouse(int button, int state, int x, int y){   //クリックしたら呼ばれる
	if(state == 0){   //ピクセル座標系から正規化座標系へ投射
		std::complex<double> c(2*double(x)/double(W)-1, 1-2*double(y)/double(H));
		center = c/zoom + center; //
		if(button == 0){
			zoom *= 2.0;
		}else if(button == 2){
			zoom /= 4.0;
		}
		display();
	}
}

// メインプログラム
int main (int argc, char *argv[]) { 
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(W , H);      // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glutMouseFunc(mouse);           // マウス関数を指定
	glViewport(0, 0, W, H);
	glutMainLoop();                 // イベント待ち
	return 0;
}
