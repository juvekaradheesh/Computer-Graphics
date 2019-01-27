#include <GL/glut.h>

char title[] = "Experiment 6 (OpenGL)";

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(-2.0f, -1.0f, -6.0f);
    // glRotatef(-35,-1.0,1.0,0.0);
    // glScalef(1.0,1.2,0.8);

    // DRAW KEY
    glBegin(GL_QUADS);

        // BACK FACE START

        glColor3f(0.43f, 0.43f, 0.43f); //Darker  Grey
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.5f, 0.0f, 0.0f);
        glVertex3f(1.5f, 2.5f, 0.0f);
        glVertex3f(1.0f, 2.5f, 0.0f);

        glVertex3f(1.5f, 2.5f, 0.0f);
        glVertex3f(1.5f, 2.25f, 0.0f);
        glVertex3f(2.5f, 2.25f, 0.0f);
        glVertex3f(2.5f, 2.5f, 0.0f);

        glVertex3f(1.5f, 2.1f, 0.0f);
        glVertex3f(1.5f, 1.85f, 0.0f);
        glVertex3f(2.0f, 1.85f, 0.0f);
        glVertex3f(2.0f, 2.1f, 0.0f);

        glVertex3f(1.5f, 1.65f, 0.0f);
        glVertex3f(1.5f, 1.35f, 0.0f);
        glVertex3f(2.25f, 1.35f, 0.0f);
        glVertex3f(2.25f, 1.65f, 0.0f);

        // BACK FACE END

        // FRONT FACE START

        glColor3f(0.63f, 0.63f, 0.63f); // Lighter Grey
        glVertex3f(1.0f, 0.0f, 0.5f);
        glVertex3f(1.5f, 0.0f, 0.5f);
        glVertex3f(1.5f, 2.5f, 0.5f);
        glVertex3f(1.0f, 2.5f, 0.5f);

        glVertex3f(1.5f, 2.5f, 0.5f);
        glVertex3f(1.5f, 2.25f, 0.5f);
        glVertex3f(2.5f, 2.25f, 0.5f);
        glVertex3f(2.5f, 2.5f, 0.5f);

        glVertex3f(1.5f, 2.1f, 0.5f);
        glVertex3f(1.5f, 1.85f, 0.5f);
        glVertex3f(2.0f, 1.85f, 0.5f);
        glVertex3f(2.0f, 2.1f, 0.5f);

        glVertex3f(1.5f, 1.65f, 0.5f);
        glVertex3f(1.5f, 1.35f, 0.5f);
        glVertex3f(2.25f, 1.35f, 0.5f);
        glVertex3f(2.25f, 1.65f, 0.5f);

        // FRONT FACE END

        // SIDES, TOPS, BOTTOMS START

        glColor3f(0.53f, 0.53f, 0.53f); // Grey

        glVertex3f(2.5f, 2.25f, 0.5f);
        glVertex3f(2.5f, 2.25f, 0.0f);
        glVertex3f(2.5f, 2.5f, 0.0f);
        glVertex3f(2.5f, 2.5f, 0.5f);

        glVertex3f(1.5f, 2.25f, 0.5f);
        glVertex3f(2.5f, 2.25f, 0.5f);
        glVertex3f(2.5f, 2.25f, 0.0f);
        glVertex3f(1.5f, 2.25f, 0.0f);

        glVertex3f(1.5f, 2.5f, 0.5f);
        glVertex3f(2.5f, 2.5f, 0.5f);
        glVertex3f(2.5f, 2.5f, 0.0f);
        glVertex3f(1.5f, 2.5f, 0.0f);

        glVertex3f(2.0f, 1.85f, 0.5f);
        glVertex3f(2.0f, 1.85f, 0.0f);
        glVertex3f(2.0f, 2.1f, 0.0f);
        glVertex3f(2.0f, 2.1f, 0.5f);

        glVertex3f(1.5f, 1.85f, 0.5f);
        glVertex3f(2.0f, 1.85f, 0.5f);
        glVertex3f(2.0f, 1.85f, 0.0f);
        glVertex3f(1.5f, 1.85f, 0.0f);

        glVertex3f(1.5f, 2.1f, 0.5f);
        glVertex3f(2.0f, 2.1f, 0.5f);
        glVertex3f(2.0f, 2.1f, 0.0f);
        glVertex3f(1.5f, 2.1f, 0.0f);

        glVertex3f(2.25f, 1.35f, 0.5f);
        glVertex3f(2.25f, 1.35f, 0.0f);
        glVertex3f(2.25f, 1.65f, 0.0f);
        glVertex3f(2.25f, 1.65f, 0.5f);

        glVertex3f(1.5f, 1.35f, 0.5f);
        glVertex3f(2.25f, 1.35f, 0.5f);
        glVertex3f(2.25f, 1.35f, 0.0f);
        glVertex3f(1.5f, 1.35f, 0.0f);

        glVertex3f(1.5f, 1.65f, 0.5f);
        glVertex3f(2.25f, 1.65f, 0.5f);
        glVertex3f(2.25f, 1.65f, 0.0f);
        glVertex3f(1.5f, 1.65f, 0.0f);

        glVertex3f(1.5f, 0.0f, 0.5f);
        glVertex3f(1.5f, 0.0f, 0.0f);
        glVertex3f(1.5f, 2.5f, 0.0f);
        glVertex3f(1.5f, 2.5f, 0.5f);

        glVertex3f(1.0f, 0.0f, 0.5f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 2.5f, 0.0f);
        glVertex3f(1.0f, 2.5f, 0.5f);

        glVertex3f(1.0f, 2.5f, 0.5f);
        glVertex3f(1.5f, 2.5f, 0.5f);
        glVertex3f(1.5f, 2.5f, 0.0f);
        glVertex3f(1.0f, 2.5f, 0.0f);

        glVertex3f(1.0f, 0.0f, 0.5f);
        glVertex3f(1.5f, 0.0f, 0.5f);
        glVertex3f(1.5f, 0.0f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);

        // SIDES, TOPS, BOTTOMS END


    glEnd();

   glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
        GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}
