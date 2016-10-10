#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み
#include <math.h>
#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

//複素数zを用いて,点P = (x, y) を P(z) = (real(z), imag(z))として表す。

/*頂点位置を反時計回りに格納した配列を引数にとり、
 * 一世代後の頂点を追加した配列を返す関数。
 */
std::vector<std::complex<double>> koch(const std::vector<std::complex<double>> &src){
	std::vector<std::complex<double>> dst = {};
	int i;
	for(i=0; i+1<src.size(); i++){
		std::complex<double> a = (2.0 * src[i] + 1.0 * src[i+1])/3.0;
		std::complex<double> b = (1.0 * src[i] + 2.0 * src[i+1])/3.0;
		std::complex<double> c = std::polar(1.0, - M_PI / 3.0) * (b - a) + a;
		dst.push_back(src[i]);
		dst.push_back(a);
		dst.push_back(c);
		dst.push_back(b);
	}
	dst.push_back(src[i]);
	return dst;
}

// 表示部分をこの関数で記入
void display(void) {
	//ガウス平面における単位円上の正三角形の頂点をa,b,cとする
	const std::complex<double> a = std::polar(1.0, M_PI / 6.0 + 0.0 * M_PI / 3.0);
	const std::complex<double> b = std::polar(1.0, M_PI / 6.0 + 2.0 * M_PI / 3.0);
	const std::complex<double> c = std::polar(1.0, M_PI / 6.0 + 4.0 * M_PI / 3.0);

	//初期状態として三角形の頂点を結んだ閉路を定義
	std::vector<std::complex<double>>  v{a, b, c, a};

	//再起的に10世代後のコッホ曲線の頂点を求める。
	for(int i=0; i<10; i++){
		v = koch(v);
	}
//debug
//	for(int i=0; i<v.size(); i++){
//		std::cout << v[i] << std::endl;
//	}

	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear (GL_COLOR_BUFFER_BIT );     // 画面消去

	glColor3d(0.0, 0.0, 1.0);   // 色指定(R,G,B)で0～1まで

	glBegin(GL_LINE_LOOP);
//	glBegin(GL_LINES);
	//実際に複素平面をplot
	for(int i=0; i<v.size(); i++){
		glVertex2d(std::real(v[i]), std::imag(v[i])); 
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

