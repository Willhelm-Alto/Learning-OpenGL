#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

int windowWidth = 500, windowHeight = 500;

void resize(int w, int h)
{
  windowWidth = w;
  windowHeight = h;
  glViewport(0,0,windowWidth,windowHeight);
}

void render(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
  glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,0.5);
    
    glColor3f(0.0,1.0,0.0);
    glVertex2f(-0.5,-0.5);

    glColor3f(0.0,0.0,1.0);
    glVertex2f(0.5,-0.5);
  glEnd();

  glutSwapBuffers();
  glutPostRedisplay();
}

int main(int argc, char *argv[])
{
  //Inits
  glutInit(&argc, argv);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutCreateWindow("Teste");
  //Define Callbacks
  glutReshapeFunc(resize);
  glutDisplayFunc(render);
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  //loopPrincipal
  glutMainLoop();
  return 1;
}
