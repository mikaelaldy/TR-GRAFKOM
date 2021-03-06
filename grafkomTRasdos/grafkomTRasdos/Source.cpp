
#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
float pindah1 = 0;
float pindah2 = 0;
bool mousedown = false;
int is_depth;

void timer(int value)
{

    if (pindah1 == 0) {
        pindah1 = -25;
    }
    else if (pindah1 == -25) {
        pindah1 = 0;
    }

    if (pindah2 == 0) {
        pindah2 = 25;
    }
    else if (pindah2 == 25) {
        pindah2 = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000, timer, 10);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 1000);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("London Metropolitan University");
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutDisplayFunc(display);
    glutTimerFunc(1, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20.0);
    glLineWidth(0.5f);

}
void display(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

 
    /// ///////////////////////////////////////alas/////////////////////////////

    glBegin(GL_POLYGON);//alas
    glColor3f(0.0, 0.6, 1.0);
    glVertex3f(-400, -1, -200); // kiri atas
    glColor3f(0.6, 0.4, 0.4);
    glVertex3f(-400, -1, 200); // kiri bawah 
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(400, -1, 200);
    glColor3f(0.0, 0.4, 1.0);
    glVertex3f(400, -1, -200);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis alas
    glColor3f(0, 0, 0);
    glVertex3f(-400, -1, -200);
    glVertex3f(-400, -1, 200);
    glVertex3f(400, -1, 200);
    glVertex3f(400, -1, -200);
    glEnd();

    // bangun 1 //
    glBegin(GL_POLYGON); //alas 1 
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-300, 0, -100); // kiri atas
    glVertex3f(-300, 0, 50); // kiri bawah
    glVertex3f(-180, 0, 50); // kanan bawah
    glVertex3f(-180, 0, -100);
    glEnd();

    glBegin(GL_POLYGON); //sisi 1 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-350, 300, 50); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-300, 0, 50); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-180, 0, 50); // kanan bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-150, 250, 50);
    glEnd();

    glBegin(GL_POLYGON); //sisi 1 atap
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-350, 300, 50); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-150, 250, 50); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-150, 250, -100); // kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-350, 300, -100); // kanan atas
    glEnd();

    glBegin(GL_POLYGON); //sisi 1 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-350, 300, -100); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-300, 0, -100); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-180, 0, -100); // kanan bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-150, 250, -100); // kanan atas
    glEnd();

    glBegin(GL_POLYGON); //sisi pintu kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-350, 300, 50); // kiri atas
    glVertex3f(-300, 0, 50); // kiri bawah
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-300, 0, 0); // kanan bawah
    glVertex3f(-350, 300, 0); // kanan atas
    glEnd();

    glBegin(GL_POLYGON); //sisi pintu tengah
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-350, 300, 0); // kiri atas
    glVertex3f(-308, 50, 0); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-308, 50, -50); // kanan bawah
    glVertex3f(-350, 300, -50); // kanan atas
    glEnd();

    glBegin(GL_POLYGON); //sisi pintu kiri
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-350, 300, -100); // kiri atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-300, 0, -100); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-300, 0, -50); // kanan bawah
    glVertex3f(-350, 300, -50); // kanan atas
    glEnd();

    // jendela sisi pintu kanan di lantai 2
////////////////coba jendela////////////////////////

    glBegin(GL_POLYGON); // depan
    glColor3f(0, 0, 0);
    glVertex3f(-323, 130, -30);
    glVertex3f(-341, 240, 0);
    glVertex3f(-335, 200, 50);
    glVertex3f(-316, 90, 50);
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela, kiri
    glColor3f(1, 1, 1);
    glVertex3f(-324, 132, -20);
    glVertex3f(-339, 225, 5); // kiri atas
    glVertex3f(-337, 210, 25); // kanan atas
    glVertex3f(-324, 122, -2); //
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela, tengah
    glColor3f(1, 1, 1);
    glVertex3f(-324, 120, 3); // kiri bawah
    glVertex3f(-336, 205, 30); // kiri atas
    glVertex3f(-335, 195, 45); // kanan atas
    glVertex3f(-320, 111, 20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela, kanan
    glColor3f(1, 1, 1);
    glVertex3f(-322, 109, 24); // bawah kiri
    glVertex3f(-334, 193, 47); // atas
    glVertex3f(-318, 98, 47); // bawah kanan
    glEnd();


    glBegin(GL_POLYGON); // samping
    glColor3f(0, 0, 0);
    glVertex3f(-335, 200, 52.8);
    glVertex3f(-316, 90, 52.8);
    glVertex3f(-280, 70, 52.8);
    glVertex3f(-250, 160, 52.8);
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela samping , kiri
    glColor3f(1, 1, 1);
    glVertex3f(-300, 175, 55); // atas kanan
    glVertex3f(-330, 190, 55); // atas kiri
    glVertex3f(-318, 119, 55); // bawah
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela samping , tengah
    glColor3f(1, 1, 1);
    glVertex3f(-297, 173, 55); // atas kiri
    glVertex3f(-317, 114, 55); // bawah kiri
    glVertex3f(-313, 93, 55); // bawah tengah
    glVertex3f(-302, 87, 55); // bawah kanan
    glVertex3f(-276, 163, 55); // atas kanan
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela samping , kanan
    glColor3f(1, 1, 1);
    glVertex3f(-273, 162, 55); // atas kiri
    glVertex3f(-299, 85, 55); // bawah kiri
    glVertex3f(-282, 75, 55); // bawah kanan
    glVertex3f(-255, 154, 55); // atas kanan
    glEnd();
    ////////////////////////////////////////////////////



    //////////////////////jendela(bagian kanan)/////////////////////////////////////

    glBegin(GL_POLYGON); // bagian depan / kanan
    glColor3f(0, 0, 0);
    glVertex3f(-140, 191, 101);
    glVertex3f(-160, 50, 101);
    glVertex3f(-130, 30, 101);
    glVertex3f(-109, 196, 101);
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela bagian depan / kanan, bawah
    glColor3f(1, 1, 1);
    glVertex3f(-150, 101, 101.5); // atas kiri
    glVertex3f(-157, 51, 101.5); // bawah kiri
    glVertex3f(-132, 35, 101.5); //bawah kanan
    glVertex3f(-125, 90, 101.5); // atas kanan
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela bagian depan / kanan, atas
    glColor3f(1, 1, 1);
    glVertex3f(-137, 188, 101.5); // atas kiri
    glVertex3f(-149, 105, 101.5); // bawah kiri
    glVertex3f(-124, 94, 101.5); //bawah kanan
    glVertex3f(-112, 192, 101.5); // atas kanan
    glEnd();

    glBegin(GL_POLYGON); // bagian atas
    glColor3f(0, 0, 0);
    glVertex3f(-140, 191, 101);
    glVertex3f(-109, 196, 101);
    glVertex3f(-109, 196, 51);
    glVertex3f(-140, 191, 51);
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela bagian atas
    glColor3f(1, 1, 1);
    glVertex3f(-137, 192, 98); // kiri depan
    glVertex3f(-112, 196, 98); // kanan depan
    glVertex3f(-112, 196, 54); // kanan belakang
    glVertex3f(-137, 192, 54); //kiri belakang
    glEnd();

    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////kaca jendela paling kanan/ paling belakang///////////////////////////
    glBegin(GL_POLYGON); // dalem jendela samping , tengah
    glColor3f(1, 1, 1);
    glVertex3f(145, 188, 52); // atas kiri
    glVertex3f(124, 169, 52); // bawah kiri
    glVertex3f(133, 145, 52); // bawah kanan
    glVertex3f(155, 163, 52); // atas kanan
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela samping , tengah
    glColor3f(1, 1, 1);
    glVertex3f(168, 208, 52); // atas kiri
    glVertex3f(148, 190, 52); // bawah kiri
    glVertex3f(158, 165, 52); // bawah kanan
    glVertex3f(180, 183, 52); // atas kanan
    glEnd();

    glBegin(GL_POLYGON); // dalem jendela samping , kanan
    glColor3f(1, 1, 1);
    glVertex3f(183, 222, 52); // atas kiri
    glVertex3f(171, 210, 52); // bawah kiri
    glVertex3f(183, 185, 52); // bawah kanan
    glVertex3f(195, 195, 52); // atas kanan
    glEnd();
    ///////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////lis pintu/////////////////////////////////////////

    glBegin(GL_POLYGON); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-310, 50, 0);
    glVertex3f(-310, 50, -50);
    glVertex3f(-320, 50, -50);
    glVertex3f(-320, 50, 0);
    glEnd();


    glBegin(GL_POLYGON); //kanopi depan / kanan
    glColor3f(0, 0, 0);
    glVertex3f(-300, 0, 0);
    glVertex3f(-310, 50, 0);
    glVertex3f(-320, 50, 0);
    glVertex3f(-310, 0, 0);
    glEnd();



    glBegin(GL_POLYGON); //kanopi belakang / kiri
    glColor3f(0, 0, 0);
    glVertex3f(-300, 0, -50);
    glVertex3f(-310, 50, -50);
    glVertex3f(-320, 50, -50);
    glVertex3f(-310, 0, -50);
    glEnd();

    /////////////////////////lantai 2///////////////////////////////
    glBegin(GL_POLYGON); //alas 2 kiri 
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(190, 100, -100); // kiri atas
    glVertex3f(190, 100, 10); // kiri bawah
    glVertex3f(-315, 100, 10); // kanan bawah
    glVertex3f(-315, 100, -100);
    glEnd();

    glBegin(GL_POLYGON); //alas 2 kanan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(190, 100, 10); // kiri atas
    glVertex3f(190, 100, 50); // kiri bawah
    glVertex3f(-150, 100, 50); // kanan bawah
    glVertex3f(-150, 100, 10);
    glEnd();


    // tangga di bangun 1

    int j = -250;
    for (int i = 0; i < 100; i += 5) {

        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON); // kotak vertical
        glVertex3f(j, i, 10); // kiri atas
        glVertex3f(j, i, 50); // kiri bawah
        glVertex3f(j, i + 5, 50); // kanan bawah
        glVertex3f(j, i + 5, 10); // kanan atas
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_POLYGON);
        glVertex3f(j, i + 5, 10); // kiri atas
        glVertex3f(j, i + 5, 50); // kiri bawah
        glVertex3f(j + 5, i + 5, 50); // kanan bawah
        glVertex3f(j + 5, i + 5, 10); // kanan atas
        glEnd();
        j += 5;
    }








    /// bangun 2
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4); //alas ke-2 kanan
    glVertex3f(-180, 0, -100); // kiri atas
    glVertex3f(-180, 0, 50); // kiri bawah
    glVertex3f(0, 0, 50); // kanan bawah
    glVertex3f(0, 0, -100);
    glEnd();

    glBegin(GL_POLYGON); // atap bangun 2, tengah
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20, 210, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(20, 210, -100);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-150, 250, -100);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-150, 250, 50);
    glEnd();


    glBegin(GL_POLYGON); // tembok bangun 2, belakang, tengah
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(0, 0, -100);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(20, 210, -100);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-150, 250, -100);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-180, 0, -100);
    glEnd();

    glBegin(GL_POLYGON); // tembok bangun 2, depan, tengah
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(0, 0, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(20, 210, 50);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-150, 250, 50);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-180, 0, 50);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4); //alas ke-2 ke bawah
    glVertex3f(-200, 0, 50); // kiri atas
    glVertex3f(-200, 0, 100); // kiri bawah
    glVertex3f(0, 0, 100); // kanan bawah
    glVertex3f(0, 0, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9); //alas ke-2 ke bawah , bagian depan
    glVertex3f(-230, 180, 100); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, 0, 100); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(0, 0, 100); // kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(20, 210, 100); // kanan atas
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6); //alas ke-2 ke bawah , bagian kiri
    glVertex3f(-230, 180, 50); // kiri atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-200, 0, 50); // kiri bawah
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, 0, 100); // kanan bawah
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-230, 180, 100); // kanan atas
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //alas ke-2 ke bawah , bagian atap
    glVertex3f(-230, 180, 50); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-230, 180, 100); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(20, 210, 100); // kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(20, 210, 50); // kanan atas
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); //alas ke-2 ke bawah , bagian kanan
    glVertex3f(20, 210, 50); // kiri atas
    glVertex3f(0, 0, 50); // kiri bawah
    glVertex3f(0, 0, 100); // kanan bawah
    glVertex3f(20, 210, 100); // kanan atas
    glEnd();

    // bangun 3

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4); //alas ke-3 kanan
    glVertex3f(0, 0, -100); // kiri atas
    glVertex3f(0, 0, 50); // kiri bawah
    glVertex3f(180, 0, 50); // kanan bawah
    glVertex3f(180, 0, -100);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //TEMBOK BELAKANG ke-3 kanan
    glVertex3f(210, 260, -100); // kanan atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(210, 260, 50); // kiri atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(180, 0, 50); // kiri bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(180, 0, -100); // kanan bawah 
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //atap ke-3 kanan
    glVertex3f(20, 210, -100); // kanan atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(20, 210, 50); // kiri atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(210, 260, 50); // kiri bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(210, 260, -100); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //TEMBOK kiri ke-3 kanan
    glVertex3f(210, 260, 50); // kanan atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(20, 210, 50); // kiri atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(0, 0, 50); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(180, 0, 50); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //TEMBOK kanan ke-3 kanan
    glVertex3f(210, 260, -100); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(20, 210, -100); // kanan atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(0, 0, -100); // kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(180, 0, -100); // kiri bawah
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4); //alas ke-3 bawah
    glVertex3f(0, 0, 50); // kiri atas
    glVertex3f(0, 0, 150); // kiri bawah
    glVertex3f(180, 0, 150);
    glVertex3f(180, 0, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //alas ke-3 atap
    glVertex3f(15, 160, 50); // kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(15, 160, 150); // kiri bawah
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(180, 160, 150);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(180, 160, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //depan
    glVertex3f(15, 160, 150);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0, 0, 150);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(180, 0, 150);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(180, 160, 150);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //sisi kiri
    glVertex3f(15, 160, 50); //kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(15, 160, 150); //kanan atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(0, 0, 150); //kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(0, 0, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //sisi kanan
    glVertex3f(180, 160, 50); //kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(180, 160, 150); //kanan atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(180, 0, 150); //kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(180, 0, 50); //kiri bawah
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //sisi kiri
    glVertex3f(15, 160, 50); //kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(15, 160, 150); //kanan atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(0, 0, 150); //kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(0, 0, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9); //sisi kanan
    glVertex3f(180, 160, 50); //kiri atas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(180, 160, 150); //kanan atas
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(180, 0, 150); //kanan bawah
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(180, 0, 50); //kiri bawah
    glEnd();


    // TEKSTUR SEMUA BANGUN

    /////////////////////////////////textur bangun 3 bawah 1/////////////////////////////////////////////////////////


    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-135, 191, 100.5);
    glVertex3f(-228, 167, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(20, 210, 100.5);
    glVertex3f(-224, 147, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(18, 190, 100.5);
    glVertex3f(-221, 127, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(16, 170, 100.5);
    glVertex3f(-217, 107, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(14, 149, 100.5);
    glVertex3f(-214, 87, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(12, 128, 100.5);
    glVertex3f(-211, 67, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(10, 107.5, 100.5);
    glVertex3f(-208, 47, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(8, 89, 100.5);
    glVertex3f(-204, 28, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(6, 70, 100.5);
    glVertex3f(-201, 14, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(4, 49.5, 100.5);
    glVertex3f(-190, 0, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(2, 33, 100.5);
    glVertex3f(-130, 0, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(0, 17, 100.5);
    glVertex3f(-70, 0, 100.5);
    glEnd();

    ////////////////////////////////textur bangun 3 bawah 2 ////////////////////////////////////

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-37, 203, 100.5);
    glVertex3f(18, 189, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-90, 197, 100.5);
    glVertex3f(16, 170, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-142, 190, 100.5);
    glVertex3f(14, 150, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-195, 183.2, 100.5);
    glVertex3f(12, 130, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-228, 173, 100.5);
    glVertex3f(10, 111, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-225, 153, 100.5);
    glVertex3f(8, 91, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-222, 133, 100.5);
    glVertex3f(6, 71, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-218, 112, 100.5);
    glVertex3f(4, 52, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-215, 93, 100.5);
    glVertex3f(3, 35, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-212, 74, 100.5);
    glVertex3f(1, 20, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-209, 55, 100.5);
    glVertex3f(-3, 5, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-206, 37, 100.5);
    glVertex3f(-45, 0, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-203, 18, 100.5);
    glVertex3f(-120, 0, 100.5);
    glEnd();

    //////////////////////////////////////////vertikal bangun 2 bawah/////////////////////////////////


    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(0, 0, 100.5);
    glVertex3f(20, 210, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-28, 0, 100.5);
    glVertex3f(-19, 205, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-57, 0, 100.5);
    glVertex3f(-59, 201, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-89, 0, 100.5);
    glVertex3f(-101, 197, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-125, 0, 100.5);
    glVertex3f(-141, 191, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-156, 0, 100.5);
    glVertex3f(-180, 187, 100.5);
    glEnd();


    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-192, 0, 100.5);
    glVertex3f(-218, 183, 100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-200, 0, 100.5); // kanan bawah
    glVertex3f(-230, 180, 100.5); // kanan atas
    glEnd();


    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-230, 180, 100.5); // kiri bawah
    glVertex3f(20, 210, 100.5); // kanan bawah
    glEnd();

    ///////////////////////////////////////garis texture depan bangun 1 horisontal /////////////////////////////

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, -25);
    glVertex3f(-348, 282, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, -100);
    glVertex3f(-344.5, 262, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-348, 282, -100);
    glVertex3f(-341, 242, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-344.5, 262, -100);
    glVertex3f(-337.5, 222, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-341, 242, -100);
    glVertex3f(-334, 202, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-337.5, 222, -100);
    glVertex3f(-330.5, 182, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-334, 202, -100);
    glVertex3f(-327.3, 162, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-330.5, 182, -100);
    glVertex3f(-324, 142, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-327.3, 162, -100);
    glVertex3f(-320.8, 122, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-324, 142, -100);
    glVertex3f(-317.2, 102, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-320.8, 122, -100);
    glVertex3f(-314, 82, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-317.6, 102, -100);
    glVertex3f(-311, 62, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-314.4, 82, -100);
    glVertex3f(-307, 42, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-307.5, 35, 0);
    glVertex3f(-303.8, 22, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-311.2, 62, -100);
    glVertex3f(-310, 49, -50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-308, 42, -100);
    glVertex3f(-305, 29, -50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-303.5, 15, 0);
    glVertex3f(-300.5, 2, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-304, 22, -100);
    glVertex3f(-302, 9, -50);
    glEnd();
    ///////////////////////////////////////garis texture depan bangun 1 horisontal balik /////////////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, 50);
    glVertex3f(-350, 300, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, -25);
    glVertex3f(-348, 282, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, 50);
    glVertex3f(-344.5, 262, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-348, 282, 50);
    glVertex3f(-341, 242, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-344.5, 262, 50);
    glVertex3f(-337.5, 222, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-341, 242, 50);
    glVertex3f(-334, 202, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-337.5, 222, 50);
    glVertex3f(-330.5, 182, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-334, 202, 50);
    glVertex3f(-327.3, 162, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-330.5, 182, 50);
    glVertex3f(-324, 142, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-327.3, 162, 50);
    glVertex3f(-320.8, 122, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-324, 142, 50);
    glVertex3f(-317.2, 102, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-320.8, 122, 50);
    glVertex3f(-314, 82, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-317.6, 102, 50);
    glVertex3f(-311, 62, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-314.4, 82, 50);
    glVertex3f(-307, 42, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-307.5, 35, -50);
    glVertex3f(-303.8, 22, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-311.2, 62, 50);
    glVertex3f(-310, 49, 0);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-308, 42, 50);
    glVertex3f(-305, 29, 0);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-303.5, 15, -50);
    glVertex3f(-300.5, 2, -100);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-304, 22, 50);
    glVertex3f(-302, 9, 0);
    glEnd();

    //////////////////////////////textur garis vertikal depan////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350.5, 300, -63);
    glVertex3f(-300.5, 0, -63);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350.5, 300, -25);
    glVertex3f(-310.5, 50, -25);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350.5, 300, 13);
    glVertex3f(-300.5, 0, 13);
    glEnd();

    // garis hitam bangun ke 3 sisi depan

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(15, 160, 150);
    glVertex3f(0, 0, 150);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(0, 0, 150);
    glVertex3f(180, 0, 150);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(180, 0, 150);
    glVertex3f(180, 160, 150);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(180, 160, 150);
    glVertex3f(15, 160, 150);
    glEnd();


    /////////////// garis tekstur bangun 3 sisi depan ///////////////////////////////

    glBegin(GL_LINES); //kanopi atas 1
    glColor3f(0, 0, 0);
    glVertex3f(125, 160, 150.5);
    glVertex3f(182.6, 145, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 2
    glColor3f(0, 0, 0);
    glVertex3f(50, 160, 150.5);
    glVertex3f(183, 125, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 3
    glColor3f(0, 0, 0);
    glVertex3f(13, 150, 150.5);
    glVertex3f(183.2, 105, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 4
    glColor3f(0, 0, 0);
    glVertex3f(12, 130, 150.5);
    glVertex3f(183, 85, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 5
    glColor3f(0, 0, 0);
    glVertex3f(9, 110, 150.5);
    glVertex3f(183, 65, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 6
    glColor3f(0, 0, 0);
    glVertex3f(6, 90, 150.5);
    glVertex3f(183, 45, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 7
    glColor3f(0, 0, 0);
    glVertex3f(3, 70, 150.5);
    glVertex3f(182.2, 25, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 8
    glColor3f(0, 0, 0);
    glVertex3f(1, 50, 150.5);
    glVertex3f(179.8, 5, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 9
    glColor3f(0, 0, 0);
    glVertex3f(-2, 30, 150.5);
    glVertex3f(140, 0, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 10
    glColor3f(0, 0, 0);
    glVertex3f(-4, 12, 150.5);
    glVertex3f(80, 0, 150.5);
    glEnd();


    //////////////// garis horizontal bangun ke 3 sisi depan



    glBegin(GL_LINES); //kanopi atas 1
    glColor3f(0, 0, 0);
    glVertex3f(50, 160, 150.5);
    glVertex3f(13, 150, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 2
    glColor3f(0, 0, 0);
    glVertex3f(13, 130, 150.5);
    glVertex3f(125, 160, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 3
    glColor3f(0, 0, 0);
    glVertex3f(12, 110, 150.5);
    glVertex3f(180, 158, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 4
    glColor3f(0, 0, 0);
    glVertex3f(9, 90, 150.5);
    glVertex3f(181, 140, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 5
    glColor3f(0, 0, 0);
    glVertex3f(3, 70, 150.5);
    glVertex3f(181, 120, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(1, 50, 150.5);
    glVertex3f(181, 100, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-2, 30, 150.5);
    glVertex3f(181, 80, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-4, 12, 150.5);
    glVertex3f(181, 60, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(120.6, 28, 150.5);
    glVertex3f(181, 40, 150.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(150, 20, 150.5);
    glVertex3f(180, 27, 150.5);
    glEnd();


    ////////////////// Garis vertikal sisi depan bangun ke 3

    glBegin(GL_LINES); // vertikal 1
    glColor3f(0, 0, 0);
    glVertex3f(50, 160, 150.5);
    glVertex3f(30, 0, 150.5);
    glEnd();

    glBegin(GL_LINES); // vertikal 2
    glColor3f(0, 0, 0);
    glVertex3f(90, 160, 150.5);
    glVertex3f(70, 0, 150.5);
    glEnd();

    glBegin(GL_LINES); // vertikal 3
    glColor3f(0, 0, 0);
    glVertex3f(125, 160, 150.5);
    glVertex3f(110, 0, 150.5);
    glEnd();

    glBegin(GL_LINES); // vertikal 4
    glColor3f(0, 0, 0);
    glVertex3f(160, 160, 150.5);
    glVertex3f(140, 0, 150.5);
    glEnd();

    ///// Tekstur Bangun 3 Sisi Kanan

    glBegin(GL_LINES); //kanopi atas 1
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 140, 150.5);
    glVertex3f(180.5, 160, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 2
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 120, 150.5);
    glVertex3f(180.5, 140, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 3
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 100, 150.5);
    glVertex3f(180.5, 120, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 3
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 80, 150.5);
    glVertex3f(180.5, 100, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 4
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 60, 150.5);
    glVertex3f(180.5, 80, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 5
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 40, 150.5);
    glVertex3f(180.5, 60, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 6
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 25, 150.5);
    glVertex3f(180.5, 40, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas 7
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 5, 150.5);
    glVertex3f(180.5, 20, 50);
    glEnd();

    // Diagonal bangun 3 sisi kanan

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 1
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 25, 150.5);
    glVertex3f(180.5, 0, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 2
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 40, 150.5);
    glVertex3f(180.5, 20, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 3
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 60, 150.5);
    glVertex3f(180.5, 40, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 4
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 80, 150.5);
    glVertex3f(180.5, 60, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 5
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 100, 150.5);
    glVertex3f(180.5, 80, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 6
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 120, 150.5);
    glVertex3f(180.5, 100, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 7
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 140, 150.5);
    glVertex3f(180.5, 120, 50);
    glEnd();

    glBegin(GL_LINES); //Diagonal (lihat dari bawah ke atas) 8
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 160, 150.5);
    glVertex3f(180.5, 140, 50);
    glEnd();

    /// garis vertical bangun ke 3 sisi kanan

    glBegin(GL_LINES); //vertical 1
    glColor3f(0, 0, 0);
    glVertex3f(180.5, 160, 100);
    glVertex3f(180.5, 0, 100);
    glEnd();


    /////// garis - garis hitam bangun 3 sisi kanan

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(180, 160, 50); //kiri atas
    glVertex3f(180, 160, 150); //kanan atas
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180, 160, 150); //kanan atas
    glVertex3f(180, 0, 150); //kanan bawah
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180, 0, 150); //kanan bawah
    glVertex3f(180, 0, 50); //kiri bawah
    glEnd();




    /////////////////////////////////////////////////texture vertikal belakang/////////////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180, 0, -100.5);
    glVertex3f(210, 260, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(145, 0, -100.5);
    glVertex3f(178, 250, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(110, 0, -100.5);
    glVertex3f(143, 240, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(75, 0, -100.5);
    glVertex3f(105, 230, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(40, 0, -100.5);
    glVertex3f(63, 220, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(0, 0, -100.5);
    glVertex3f(20, 210, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-30, 0, -100.5);
    glVertex3f(-15, 220, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-60, 0, -100.5);
    glVertex3f(-55, 230, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-91, 0, -100.5);
    glVertex3f(-96, 240, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-125, 0, -100.5);
    glVertex3f(-138, 250, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-156, 0, -100.5);
    glVertex3f(-182, 260, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-190, 0, -100.5);
    glVertex3f(-225, 270, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-227, 0, -100.5);
    glVertex3f(-268, 280, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-260, 0, -100.5);
    glVertex3f(-310, 290, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-300, 0, -100.5);
    glVertex3f(-350, 300, -100.5);
    glEnd();

    /////////////////////////////////////////////////texture vertikal depan/////////////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180, 0, 50.5);
    glVertex3f(210, 260, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(145, 0, 50.5);
    glVertex3f(178, 250, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(110, 0, 50.5);
    glVertex3f(143, 240, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(75, 0, 50.5);
    glVertex3f(105, 230, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(40, 0, 50.5);
    glVertex3f(63, 220, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(0, 0, 50.5);
    glVertex3f(20, 210, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-30, 0, 50.5);
    glVertex3f(-15, 220, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-60, 0, 50.5);
    glVertex3f(-55, 230, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-91, 0, 50.5);
    glVertex3f(-96, 240, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-125, 0, 50.5);
    glVertex3f(-138, 250, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-156, 0, 50.5);
    glVertex3f(-182, 260, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-190, 0, 50.5);
    glVertex3f(-225, 270, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-227, 0, 50.5);
    glVertex3f(-268, 280, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-260, 0, 50.5);
    glVertex3f(-310, 290, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-300, 0, 50.5);
    glVertex3f(-350, 300, 50.5);
    glEnd();

    ////////////////////////////garis tekstur belakang diagonal///////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-302, 290, -100.5);
    glVertex3f(-348, 282, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-262, 280, -100.5);
    glVertex3f(-344.5, 262, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-222, 270, -100.5);
    glVertex3f(-341, 242, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-182, 260, -100.5);
    glVertex3f(-337.5, 222, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-142, 250, -100.5);
    glVertex3f(-334, 202, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-102, 240, -100.5);
    glVertex3f(-330.5, 182, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-62, 230, -100.5);
    glVertex3f(-327, 162, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-22, 220, -100.5);
    glVertex3f(-323.5, 142, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, -100.5);
    glVertex3f(-320, 122, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(207.6, 240, -100.5);
    glVertex3f(-316.5, 102, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(205.2, 220, -100.5);
    glVertex3f(-313, 82, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(202.8, 200, -100.5);
    glVertex3f(-309.5, 62, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(200.4, 180, -100.5);
    glVertex3f(-306, 42, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(198, 160, -100.5);
    glVertex3f(-302.5, 22, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(195.6, 140, -100.5);
    glVertex3f(-299, 2, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(193.2, 120, -100.5);
    glVertex3f(-250, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(190.8, 100, -100.5);
    glVertex3f(-190, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(188.4, 80, -100.5);
    glVertex3f(-130, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(186, 60, -100.5);
    glVertex3f(-70, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(183.6, 40, -100.5);
    glVertex3f(-10, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(181.2, 20, -100.5);
    glVertex3f(50, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(178.8, 0, -100.5);
    glVertex3f(110, 0, -100.5);
    glEnd();

    ////////////////////////////garis tekstur depan diagonal///////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-302, 290, 50.5);
    glVertex3f(-348, 282, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-262, 280, 50.5);
    glVertex3f(-344.5, 262, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-222, 270, 50.5);
    glVertex3f(-341, 242, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-182, 260, 50.5);
    glVertex3f(-337.5, 222, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-142, 250, 50.5);
    glVertex3f(-334, 202, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-102, 240, 50.5);
    glVertex3f(-330.5, 182, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-62, 230, 50.5);
    glVertex3f(-327, 162, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-22, 220, 50.5);
    glVertex3f(-323.5, 142, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, 50.5);
    glVertex3f(-320, 122, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(207.6, 240, 50.5);
    glVertex3f(-316.5, 102, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(205.2, 220, 50.5);
    glVertex3f(-313, 82, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(202.8, 200, 50.5);
    glVertex3f(-309.5, 62, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(200.4, 180, 50.5);
    glVertex3f(-306, 42, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(198, 160, 50.5);
    glVertex3f(-302.5, 22, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(195.6, 140, 50.5);
    glVertex3f(-299, 2, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(193.2, 120, 50.5);
    glVertex3f(-250, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(190.8, 100, 50.5);
    glVertex3f(-190, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(188.4, 80, 50.5);
    glVertex3f(-130, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(186, 60, 50.5);
    glVertex3f(-70, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(183.6, 40, 50.5);
    glVertex3f(-10, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(181.2, 20, 50.5);
    glVertex3f(50, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(178.8, 0, 50.5);
    glVertex3f(110, 0, 50.5);
    glEnd();




    /////////////////////////////garis tekstur belakang///////////////////////

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180, 252, -100.5);
    glVertex3f(208.6, 245, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(139, 241, -100.5);
    glVertex3f(206.2, 225, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(98, 230.5, -100.5);
    glVertex3f(203.8, 205, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(57, 220, -100.5);
    glVertex3f(201.4, 185, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, -100.5);
    glVertex3f(199, 165, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-346.5, 280, -100.5);
    glVertex3f(196.6, 145, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-343, 260, -100.5);
    glVertex3f(194.2, 125, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-339.5, 240, -100.5);
    glVertex3f(191.8, 105, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-336, 220, -100.5);
    glVertex3f(189.4, 85, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-332.5, 200, -100.5);
    glVertex3f(187, 65, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-329, 180, -100.5);
    glVertex3f(184.6, 45, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-325, 160, -100.5);
    glVertex3f(182.2, 25, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-321.5, 140, -100.5);
    glVertex3f(179.8, 5, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-318, 120, -100.5);
    glVertex3f(140, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-314.5, 100, -100.5);
    glVertex3f(80, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-311, 80, -100.5);
    glVertex3f(20, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-307.5, 60, -100.5);
    glVertex3f(-45, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-304, 40, -100.5);
    glVertex3f(-120, 0, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-300.5, 20, -100.5);
    glVertex3f(-195, 0, -100.5);
    glEnd();

    /////////////////////////////garis tekstur depan///////////////////////

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180, 252, 50.5);
    glVertex3f(208.6, 245, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(139, 241, 50.5);
    glVertex3f(206.2, 225, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(98, 230.5, 50.5);
    glVertex3f(203.8, 205, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(57, 220, 50.5);
    glVertex3f(201.4, 185, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-350, 300, 50.5);
    glVertex3f(199, 165, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-346.5, 280, 50.5);
    glVertex3f(196.6, 145, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-343, 260, 50.5);
    glVertex3f(194.2, 125, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-339.5, 240, 50.5);
    glVertex3f(191.8, 105, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-336, 220, 50.5);
    glVertex3f(189.4, 85, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-332.5, 200, 50.5);
    glVertex3f(187, 65, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-329, 180, 50.5);
    glVertex3f(184.6, 45, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-325, 160, 50.5);
    glVertex3f(182.2, 25, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-321.5, 140, 50.5);
    glVertex3f(179.8, 5, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-318, 120, 50.5);
    glVertex3f(140, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-314.5, 100, 50.5);
    glVertex3f(80, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-311, 80, 50.5);
    glVertex3f(20, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-307.5, 60, 50.5);
    glVertex3f(-45, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-304, 40, 50.5);
    glVertex3f(-120, 0, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(-300.5, 20, 50.5);
    glVertex3f(-195, 0, 50.5);
    glEnd();

    //////////////////////////textur bangunan paling kanan kekanan /////////////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, -100);
    glVertex3f(210, 260, 50);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, -25.5);
    glVertex3f(208.6, 245, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, 43);
    glVertex3f(206.2, 225, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(208.6, 245, 50.5);
    glVertex3f(203.8, 205, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(206.2, 225, 50.5);
    glVertex3f(201.4, 185, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(203.8, 205, 50.5);
    glVertex3f(199.3, 165, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(201.4, 185, 50.5);
    glVertex3f(197, 145, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(199.3, 165, 50.5);
    glVertex3f(194.6, 125, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(197, 145, 50.5);
    glVertex3f(192.3, 105, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(194.6, 125, 50.5);
    glVertex3f(190, 85, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(192.3, 105, 50.5);
    glVertex3f(187.6, 65, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(190, 85, 50.5);
    glVertex3f(185.3, 45, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(187.6, 65, 50.5);
    glVertex3f(183, 25, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(185.3, 45, 50.5);
    glVertex3f(180.6, 5, -100.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(183, 25, 50.5);
    glVertex3f(180.6, 0, -45.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180.6, 5, 50.5);
    glVertex3f(180.6, 0, 27);
    glEnd();

    //////////////////////////textur bangunan paling kanan kekanan /////////////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, -25.5);
    glVertex3f(208.6, 245, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210, 260, -93);
    glVertex3f(206.2, 225, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(208.6, 245, -100.5);
    glVertex3f(203.8, 205, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(206.2, 225, -100.5);
    glVertex3f(201.4, 185, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(203.8, 205, -100.5);
    glVertex3f(199.3, 165, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(201.4, 185, -100.5);
    glVertex3f(197, 145, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(199.3, 165, -100.5);
    glVertex3f(194.6, 125, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(197, 145, -100.5);
    glVertex3f(192.3, 105, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(194.6, 125, -100.5);
    glVertex3f(190, 85, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(192.3, 105, -100.5);
    glVertex3f(187.6, 65, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(190, 85, -100.5);
    glVertex3f(185.3, 45, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(187.6, 65, -100.5);
    glVertex3f(183, 25, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(185.3, 45, -100.5);
    glVertex3f(180.6, 5, 50.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(183, 25, -100.5);
    glVertex3f(180.6, 0, -5.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(180.6, 5, -100.5);
    glVertex3f(180.6, 0, -75);
    glEnd();

    //////////////////////////////textur garis vertikal belakang////////////////////
    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210.5, 260, -25.5);
    glVertex3f(180.5, 0, -25.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210.5, 260, 12.5);
    glVertex3f(180.5, 0, 12.5);
    glEnd();

    glBegin(GL_LINES); //kanopi atas
    glColor3f(0, 0, 0);
    glVertex3f(210.5, 260, -65.5);
    glVertex3f(180.5, 0, -65.5);
    glEnd();




    // pintu bangun ke-3 ke bawah ///

    glBegin(GL_POLYGON); // bagian depan pojok kanan / belakang
    glColor3f(0.1, 0.1, 0.1); //sisi luar hitam
    glVertex3f(204, 200, 51); // atas kanan
    glVertex3f(130, 140, 51);  // bawah kanan
    glVertex3f(120, 170, 51);   // bawah kiri
    glVertex3f(210, 250, 51); // atas kiri
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1); //sisi luar hitam
    glVertex3f(50, 50, 151);
    glVertex3f(55, 0, 151);
    glVertex3f(150, 0, 151);
    glVertex3f(150, 20, 151);
    glEnd();

    // kaca
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1); // sisi putih 1
    glVertex3f(60, 37, 152);
    glVertex3f(65, 6, 152);
    glVertex3f(77, 6, 152);
    glVertex3f(77, 30, 152);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1); // sisi putih 2
    glVertex3f(78, 30, 152);
    glVertex3f(78, 6, 152);
    glVertex3f(89, 6, 152);
    glVertex3f(89, 25, 152);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1); // sisi putih 3
    glVertex3f(94, 25, 152);
    glVertex3f(94, 6, 152);
    glVertex3f(104, 6, 152);
    glVertex3f(104, 21, 152);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); // sisi putih 4
    glVertex3f(105, 21, 152);
    glVertex3f(105, 6, 152);
    glVertex3f(115, 6, 152);
    glVertex3f(115, 17, 152);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); // sisi putih 5
    glVertex3f(117, 17, 152);
    glVertex3f(117, 6, 152);
    glVertex3f(127, 6, 152);
    glVertex3f(127, 13, 152);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); // sisi putih 6
    glVertex3f(128, 13, 152);
    glVertex3f(128, 6, 152);
    glVertex3f(138, 6, 152);
    glVertex3f(138, 10, 152);
    glEnd();

    /////// pagar l2 //////////////////////////////////////////

    glBegin(GL_POLYGON); //alas 2 kanan
    glColor3f(0.9, 0.9, 1.5);
    glVertex3f(-315, 100, 10); // kiri atas
    glVertex3f(-315, 120, 10); // kiri bawah
    glVertex3f(-149, 120, 10); // kanan bawah
    glVertex3f(-149, 100, 10);
    glEnd();

    glBegin(GL_POLYGON); //pagar
    glColor3f(0, 0, 0);
    glVertex3f(-150, 100, 10);
    glVertex3f(-150, 120, 10);
    glVertex3f(-149, 120, 10);
    glVertex3f(-149, 100, 10);
    glEnd();

    glBegin(GL_POLYGON); //pagar
    glColor3f(0, 0, 0);
    glVertex3f(-150, 120, 10);
    glVertex3f(-150, 119, 10);
    glVertex3f(-315, 119, 10);
    glVertex3f(-315, 120, 10);
    glEnd();

    glBegin(GL_POLYGON); //pagar
    glColor3f(0, 0, 0);
    glVertex3f(-150, 100, 11);
    glVertex3f(-150, 120, 11);
    glVertex3f(-149, 120, 11);
    glVertex3f(-149, 100, 11);
    glEnd();

    glBegin(GL_POLYGON); //pagar
    glColor3f(0, 0, 0);
    glVertex3f(-150, 100, 10);
    glVertex3f(-150, 120, 10);
    glVertex3f(-150, 120, 11);
    glVertex3f(-150, 100, 11);
    glEnd();

    glBegin(GL_POLYGON); //pagar
    glColor3f(0, 0, 0);
    glVertex3f(-150, 120, 11);
    glVertex3f(-150, 119, 11);
    glVertex3f(-315, 119, 11);
    glVertex3f(-315, 120, 11);
    glEnd();

    glBegin(GL_POLYGON); //pagar
    glColor3f(0, 0, 0);
    glVertex3f(-150, 120, 10);
    glVertex3f(-150, 120, 11);
    glVertex3f(-315, 120, 11);
    glVertex3f(-315, 120, 10);
    glEnd();
    ///////////////////////////////////////////////////

    ////////////////////////HIASAN////////////////////////////////////////

    glBegin(GL_QUADS);//Papan Tulis
    glColor3f(1, 1, 1);
    glVertex3f(178, 60, -70); // kanan atas
    glVertex3f(178, 60, 20); // kiri atas
    glVertex3f(178, 20, 20); // kiri bawah
    glVertex3f(178, 20, -70); // kanan bawah
    glEnd();

    glBegin(GL_LINE_LOOP);//Garis Papan Tulis
    glColor3f(0, 0, 0);
    glVertex3f(178, 60, -70); // kanan atas
    glVertex3f(178, 60, 20); // kiri atas
    glVertex3f(178, 20, 20); // kiri bawah
    glVertex3f(178, 20, -70); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);// penggaris lur
    glColor3ub(210, 105, 30);
    glVertex3f(170, 0, 40); // kanan bawah
    glVertex3f(170, 0, 37); // kiri bawah
    glVertex3f(185, 50, 37); // kiri atas
    glVertex3f(185, 50, 40); // kanan atas
    glEnd();

    ////////////////////coba bikin papan pijakan/////////////////////////
    glBegin(GL_QUADS);//Pijakan, alas bagian bawah
    glColor3ub(210, 105, 30);
    glVertex3f(165, 2, -70); //kiri belakang
    glVertex3f(165, 2, 20); // kiri depan
    glVertex3f(178, 2, 20); // kanan depan
    glVertex3f(178, 2, -70); // kanan belakang
    glEnd();

    glBegin(GL_LINE_LOOP);//Pijakan, alas bagian bawah
    glColor3ub(0, 0, 0);
    glLineWidth(1.0f);
    glVertex3f(165, 2, -70); //kiri belakang
    glVertex3f(165, 2, 20); // kiri depan
    glVertex3f(178, 2, 20); // kanan depan
    glVertex3f(178, 2, -70); // kanan belakang
    glEnd();

    glBegin(GL_QUADS);//Pijakan, alas bagian atas
    glColor3ub(210, 105, 30);
    glVertex3f(165, 10, -70); //kiri belakang
    glVertex3f(165, 10, 20); // kiri depan
    glVertex3f(178, 10, 20); // kanan depan
    glVertex3f(178, 10, -70); // kanan belakang
    glEnd();

    glBegin(GL_LINE_LOOP);//Pijakan, alas bagian atas
    glLineWidth(1.0f);
    glColor3ub(0, 0, 0);
    glVertex3f(165, 10, -70); //kiri belakang
    glVertex3f(165, 10, 20); // kiri depan
    glVertex3f(178, 10, 20); // kanan depan
    glVertex3f(178, 10, -70); // kanan belakang
    glEnd();

    glBegin(GL_QUADS);//Pijakan, bagian kiri
    glColor3ub(210, 10, 30);
    glVertex3f(165, 10, -70); // belakang bawah
    glVertex3f(165, 10, 20); // depan bawah
    glVertex3f(165, 10, 20); // depan atas
    glVertex3f(165, 10, -70); // belakang atas
    glEnd();

    glBegin(GL_LINE_LOOP);//Pijakan, bagian kiri
    glLineWidth(1.0f);
    glColor3ub(0, 0, 0);
    glVertex3f(165, 2, -70); // belakang bawah
    glVertex3f(165, 2, 20); // depan bawah
    glVertex3f(165, 10, 20); // depan atas
    glVertex3f(165, 10, -70); // belakang atas
    glEnd();


    glBegin(GL_QUADS);//Pijakan, bagian kanan
    glColor3ub(210, 105, 30);
    glVertex3f(178, 2, -70); // belakang bawah
    glVertex3f(178, 2, 20); // depan bawah
    glVertex3f(178, 10, 20); // depan atas
    glVertex3f(178, 10, -70); // belakang atas
    glEnd();

    glBegin(GL_LINE_LOOP);//Pijakan, bagian kanan
    glLineWidth(1.0f);
    glColor3ub(0, 0, 0);
    glVertex3f(178, 2, -70); // belakang bawah
    glVertex3f(178, 2, 20); // depan bawah
    glVertex3f(178, 10, 20); // depan atas
    glVertex3f(178, 10, -70); // belakang atas
    glEnd();

    glBegin(GL_QUADS); // pijakan bagian belakang
    glVertex3f(165, 8, -70); //kiri atas
    glVertex3f(165, 2, -70); //kiri bawah
    glVertex3f(178, 2, -70); // kanan bawah
    glVertex3f(178, 10, -70); // kanan atas
    glEnd();

    glBegin(GL_QUADS); // pijakan bagian depan
    glVertex3f(165, 10, 20); //kiri atas
    glVertex3f(165, 2, 20); //kiri bawah
    glVertex3f(178, 2, 20); // kanan bawah
    glVertex3f(178, 10, 20); // kanan atas
    glEnd();
    /////////////////////////////////////////////////////////////////////
     /////////////////// kursi ///////////
    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(50, 2, -30); // kanan atas
    glVertex3f(52, 2, -30); // kiri atas
    glVertex3f(52, 10, -30); // kiri bawah
    glVertex3f(50, 10, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(58, 2, -30); // kanan atas
    glVertex3f(60, 2, -30); // kiri atas
    glVertex3f(60, 10, -30); // kiri bawah
    glVertex3f(58, 10, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(50, 2, -30); // kanan atas
    glVertex3f(50, 2, -28); // kiri atas
    glVertex3f(50, 10, -28); // kiri bawah
    glVertex3f(50, 10, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(60, 2, -30); // kanan atas
    glVertex3f(60, 2, -28); // kiri atas
    glVertex3f(60, 10, -28); // kiri bawah
    glVertex3f(60, 10, -30); // kanan bawah
    glEnd();

    /// kiri bawah //

    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(50, 2, -20); // kanan atas
    glVertex3f(52, 2, -20); // kiri atas
    glVertex3f(52, 10, -20); // kiri bawah
    glVertex3f(50, 10, -20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki kursi 
    glColor3ub(210, 105, 30);
    glVertex3f(50, 2, -20); // kanan atas
    glVertex3f(50, 2, -22); // kiri atas
    glVertex3f(50, 10, -22); // kiri bawah
    glVertex3f(50, 10, -20); // kanan bawah
    glEnd();
    /// kanan bawah
    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(58, 2, -20); // kanan atas
    glVertex3f(60, 2, -20); // kiri atas
    glVertex3f(60, 10, -20); // kiri bawah
    glVertex3f(58, 10, -20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki kursi
    glColor3ub(210, 105, 30);
    glVertex3f(60, 2, -20); // kanan atas
    glVertex3f(60, 2, -22); // kiri atas
    glVertex3f(60, 10, -22); // kiri bawah
    glVertex3f(60, 10, -20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas kursi
    glColor3ub(180, 105, 30);
    glVertex3f(50, 10, -30); // kanan atas
    glVertex3f(60, 10, -30); // kiri atas
    glVertex3f(60, 10, -20); // kiri bawah
    glVertex3f(50, 10, -20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(210, 105, 30);
    glVertex3f(50, 10, -20); // kanan atas
    glVertex3f(60, 10, -20); // kiri atas
    glVertex3f(60, 9, -20); // kiri bawah
    glVertex3f(50, 9, -20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(210, 105, 30);
    glVertex3f(50, 10, -30); // kanan atas
    glVertex3f(60, 10, -30); // kiri atas
    glVertex3f(60, 9, -30); // kiri bawah
    glVertex3f(50, 9, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(210, 105, 30);
    glVertex3f(50, 10, -30); // kanan atas
    glVertex3f(50, 10, -20); // kiri atas
    glVertex3f(50, 9, -20); // kiri bawah
    glVertex3f(50, 9, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(210, 105, 30);
    glVertex3f(60, 10, -30); // kanan atas
    glVertex3f(60, 10, -20); // kiri atas
    glVertex3f(60, 9, -20); // kiri bawah
    glVertex3f(60, 9, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//punggung kursi
    glColor3ub(210, 105, 30);
    glVertex3f(50, 10, -30); // kanan atas
    glVertex3f(50, 10, -28); // kiri atas
    glVertex3f(50, 19, -28); // kiri bawah
    glVertex3f(50, 19, -30); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//punggung kursi
    glColor3ub(210, 105, 30);
    glVertex3f(50, 10, -20); // kanan atas
    glVertex3f(50, 10, -22); // kiri atas
    glVertex3f(50, 19, -22); // kiri bawah
    glVertex3f(50, 19, -20); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//punggung kursi
    glColor3ub(210, 105, 30);
    glVertex3f(50, 17, -20); // kanan atas
    glVertex3f(50, 17, -30); // kiri atas
    glVertex3f(50, 21, -30); // kiri bawah
    glVertex3f(50, 21, -20); // kanan bawah
    glEnd();

    //////// meja  ///////
    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(230, 105, 30);
    glVertex3f(80, 2, -40); // kanan atas
    glVertex3f(82, 2, -40); // kiri atas
    glVertex3f(82, 15, -40); // kiri bawah
    glVertex3f(80, 15, -40); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(95, 2, -40); // kanan atas
    glVertex3f(97, 2, -40); // kiri atas
    glVertex3f(97, 15, -40); // kiri bawah
    glVertex3f(95, 15, -40); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(80, 2, -40); // kanan atas
    glVertex3f(80, 2, -38); // kiri atas
    glVertex3f(80, 15, -38); // kiri bawah
    glVertex3f(80, 15, -40); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(97, 2, -40); // kanan atas
    glVertex3f(97, 2, -38); // kiri atas
    glVertex3f(97, 15, -38); // kiri bawah
    glVertex3f(97, 15, -40); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(80, 2, -10); // kanan atas
    glVertex3f(82, 2, -10); // kiri atas
    glVertex3f(82, 15, -10); // kiri bawah
    glVertex3f(80, 15, -10); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(95, 2, -10); // kanan atas
    glVertex3f(97, 2, -10); // kiri atas
    glVertex3f(97, 15, -10); // kiri bawah
    glVertex3f(95, 15, -10); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(80, 2, -10); // kanan atas
    glVertex3f(80, 2, -12); // kiri atas
    glVertex3f(80, 15, -12); // kiri bawah
    glVertex3f(80, 15, -10); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//kaki meja
    glColor3ub(250, 105, 30);
    glVertex3f(97, 2, -10); // kanan atas
    glVertex3f(97, 2, -12); // kiri atas
    glVertex3f(97, 15, -12); // kiri bawah
    glVertex3f(97, 15, -10); // kanan bawah
    glEnd();
    /// alas ///

    glBegin(GL_POLYGON);//alas
    glColor3ub(250, 105, 30);
    glVertex3f(80, 15, -40); // kanan atas
    glVertex3f(97, 15, -40); // kiri atas
    glVertex3f(97, 15, -10); // kiri bawah
    glVertex3f(80, 15, -10); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(250, 105, 30);
    glVertex3f(80, 15, -10); // kanan atas
    glVertex3f(97, 15, -10); // kiri atas
    glVertex3f(97, 19, -10); // kiri bawah
    glVertex3f(80, 19, -10); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(250, 105, 30);
    glVertex3f(80, 15, -40); // kanan atas
    glVertex3f(97, 15, -40); // kiri atas
    glVertex3f(97, 19, -40); // kiri bawah
    glVertex3f(80, 19, -40); // kanan bawah
    glEnd();


    glBegin(GL_POLYGON);//alas
    glColor3ub(250, 105, 30);
    glVertex3f(97, 15, -40); // kanan atas
    glVertex3f(97, 15, -10); // kiri atas
    glVertex3f(97, 19, -10); // kiri bawah
    glVertex3f(97, 19, -40); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//alas atas
    glColor3ub(250, 105, 30);
    glVertex3f(80, 19, -39.5); // kanan atas
    glVertex3f(97, 19, -39.5); // kiri atas
    glVertex3f(97, 19, -10.5); // kiri bawah
    glVertex3f(80, 19, -10.5); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//laci
    glColor3f(0, 0, 0);
    glVertex3f(80, 18.5, -39.5); // kanan atas
    glVertex3f(97, 18.5, -39.5); // kiri atas
    glVertex3f(97, 18.5, -10.5); // kiri bawah
    glVertex3f(80, 18.5, -10.5); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//laci
    glColor3f(0, 0, 0);
    glVertex3f(82, 15.5, -39.5); // kanan atas
    glVertex3f(97, 15.5, -39.5); // kiri atas
    glVertex3f(97, 15.5, -10.5); // kiri bawah
    glVertex3f(82, 15.5, -10.5); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//sisi laci
    glColor3f(0, 0, 0);
    glVertex3f(82, 15, -10.5); // kanan atas
    glVertex3f(97, 15, -10.5); // kiri atas
    glVertex3f(97, 19, -10.5); // kiri bawah
    glVertex3f(82, 19, -10.5); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//sisi laci
    glColor3f(0, 0, 0);
    glVertex3f(82, 15, -39.5); // kanan atas
    glVertex3f(97, 15, -39.5); // kiri atas
    glVertex3f(97, 19, -39.5); // kiri bawah
    glVertex3f(82, 19, -39.5); // kanan bawah
    glEnd();

    glBegin(GL_POLYGON);//sisi laci
    glColor3ub(210, 105, 30);
    glVertex3f(82, 15, -25); // kanan atas
    glVertex3f(97, 15, -25); // kiri atas
    glVertex3f(97, 19, -25); // kiri bawah
    glVertex3f(82, 19, -25); // kanan bawah
    glEnd();

    // rak

    // rak
    glColor3f(0.5, 0.5, 0);
    glBegin(GL_POLYGON); // samping kiri rak
    glVertex3f(50, 47, -100); // kiri atas
    glVertex3f(50, 0, -100); // kiri bawah
    glVertex3f(50, 0, -80); // kanan bawah
    glVertex3f(50, 47, -80); // kanan atas
    glEnd();

    glBegin(GL_POLYGON); // samping kanan rak
    glVertex3f(100, 47, -100); // kiri atas
    glVertex3f(100, 0, -100); // kiri bawah
    glVertex3f(100, 0, -80); // kanan bawah
    glVertex3f(100, 47, -80); // kanan atas
    glEnd();
    for (int i = 5; i < 45; i += 10) {
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON);
        glVertex3f(50, i, -100); // kiri atas
        glVertex3f(50, i, -80); // kiri bawah
        glVertex3f(100, i, -80); // kanan bawah
        glVertex3f(100, i, -100); // kanan atas
        glEnd();
    }

    ///////////////////////////////////HIASAN////////////////////////////////////////////
    /////////////////////////////////////////jalan///////////////////////////////////////////////
    glBegin(GL_POLYGON); //jalan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-600, 0, 200); // kiri atas
    glVertex3f(-600, 0, 500); // kiri bawah 
    glVertex3f(600, 0, 500);
    glVertex3f(600, 0, 200);
    glEnd();

    glBegin(GL_POLYGON); //marka jalan
    glColor3f(1, 1, 1);
    glVertex3f(-550, 1, 340);
    glVertex3f(-550, 1, 360);
    glVertex3f(-400, 1, 360);
    glVertex3f(-400, 1, 340);
    glEnd();

    glBegin(GL_POLYGON); //marka jalan
    glColor3f(1, 1, 1);
    glVertex3f(-350, 1, 340);
    glVertex3f(-350, 1, 360);
    glVertex3f(-200, 1, 360);
    glVertex3f(-200, 1, 340);
    glEnd();

    glBegin(GL_POLYGON); //marka jalan
    glColor3f(1, 1, 1);
    glVertex3f(-150, 1, 340);
    glVertex3f(-150, 1, 360);
    glVertex3f(0, 1, 360);
    glVertex3f(0, 1, 340);
    glEnd();

    glBegin(GL_POLYGON); //marka jalan
    glColor3f(1, 1, 1);
    glVertex3f(50, 1, 340);
    glVertex3f(50, 1, 360);
    glVertex3f(200, 1, 360);
    glVertex3f(200, 1, 340);
    glEnd();

    glBegin(GL_POLYGON); //marka jalan
    glColor3f(1, 1, 1);
    glVertex3f(250, 1, 340);
    glVertex3f(250, 1, 360);
    glVertex3f(400, 1, 360);
    glVertex3f(400, 1, 340);
    glEnd();

    glBegin(GL_POLYGON); //marka jalan
    glColor3f(1, 1, 1);
    glVertex3f(450, 1, 340);
    glVertex3f(450, 1, 360);
    glVertex3f(600, 1, 360);
    glVertex3f(600, 1, 340);
    glEnd();


    /////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////pintu //////////////////////////////////////////



    glPushMatrix();
    glTranslatef(-1.0, 0.0, pindah2);
    glBegin(GL_QUADS);//pintu kampus kiri
    glColor3f(0.702f, 0.29f, 0.0f);
    glVertex3f(-300, 0, 0);
    glVertex3f(-300, 0, -25);
    glVertex3f(-310, 50, -25);
    glVertex3f(-310, 50, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis pintu kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-301, 0, 0);
    glVertex3f(-301, 0, -25);
    glVertex3f(-311, 50, -25);
    glVertex3f(-311, 50, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, 0.0, pindah1);
    glBegin(GL_QUADS);//pintu kampus kanan
    glColor3f(0.702f, 0.29f, 0.0f);
    glVertex3f(-300, 0, -25);
    glVertex3f(-300, 0, -50);
    glVertex3f(-310, 50, -50);
    glVertex3f(-310, 50, -25);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis pintu kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-301, 0, -25);
    glVertex3f(-301, 0, -50);
    glVertex3f(-311, 50, -50);
    glVertex3f(-311, 50, -25);
    glEnd();

    glPopMatrix();
    //////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////ini penting, jangan sampai kehapus///////////////////////////////////
    glPopMatrix();                                      //////////////////////////
    glutSwapBuffers();                                      /////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////sisi atap alas 2 //////////////////////

}
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
/*
Cara penggunaan :
+++++++++++++++++++++----------------------------------------------------+++++++++++++
untuk penggunaan mouse langsung klik rumah dan arahkan
+++++++++++++++++++++----------------------------------------------------+++++++++++++
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"5" : transparankan rumah
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(10.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-10.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 10.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -10.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 10.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -10.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, width / height, 30.0, 2000.0);
    glTranslatef(0.0, -500.0, -1500.0);
    glMatrixMode(GL_MODELVIEW);
}
