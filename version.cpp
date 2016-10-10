#include <iostream>
#include <GLUT/glut.h>
using namespace std; 
int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutCreateWindow("Check OpenGL");
 
  cout << "Vendor :"<<glGetString(GL_VENDOR)<<'\n';
  cout << "GPU : "<<glGetString(GL_RENDERER) <<'\n';
  cout << "OpenGL ver. " <<glGetString(GL_VERSION)<<'\n';
  cout << "【拡張機能一覧】"<<endl;
  cout << glGetString(GL_EXTENSIONS) <<endl;
 
  int i; cin >> i;
  return 0;
}

