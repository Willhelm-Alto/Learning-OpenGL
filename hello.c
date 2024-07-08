#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void render(){
  //Limpa os buffers da janela
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);

  //Desenha um triangulo
  glBegin(GL_TRIANGLES);
    glVertex2f(-0.5,0);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(0,1);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(0.5,0);
  glEnd();

  //Função para buffers duplos: 
  //Troca o buffer que foi completamente processado pelo que está sendo mostrado na tela para efeito de suavização
  glutSwapBuffers();
}

// void resize(int w, int h){
//   if(h == 0)
//     h = 1; //evita divizão por 0
//   float ratio = 1.0 * w / h;
//
//   glMatrixMode(GL_PROJECTION); //Define a matrix da janela como sendo de projeção podendo desenhar volume 
//   glLoadIdentity(); //Inicia a matrix de identidade para inicializar a matrix da janela 
//
//   //Define o viewport (área da janela onde as coisas acontecem, dentro das bordas decorativas) como sendo o tamanho inteiro da janela
//   //os dois primeiros parametros são o canto inferior esquerdo; e depois a largura e altura
//   glViewport(0,0,w,h);
//
//   //Define os parametros de perspectiva. 
//   //O primeiro parametro define o angulo de visão do plano YZ
//   //O segundo parametro define o ratio entre largura sobre altura
//   //O terceiro e quarto parametro define a distancia de "clip" de perto e de longe
//   //ou seja, qualquer coisa menor do que 1 ou maior do que 100 não serão redenrizados 
//   //pois estarão muito perto ou muito longe para isso.
//   gluPerspective(45,ratio,0.1,1000);
//
//   glMatrixMode(GL_MODELVIEW); //Todas as operações de matrizes usarão o modelo MODELVIEW
// }

int main(int argc, char *argv[])
{
  // Inicializa o GLUT 
  glutInit(&argc, argv);
  //==========================//
  
  //Define a janela
  glutInitWindowPosition(0,0); //Define a posição da janela
  glutInitWindowSize(500,500); //Define o tamanho da janela
  //==========================// 
 
  //Define o modo de exibição da janela
  //Os modos possíveis são: 
  //  GLUT_RGB ou GLUT_RGBA(padrão) ou GLUT_INDEX para cores
  //  GLUT_SINGLE ou GLUT_DOUBLE ou GLUT_ACCUM ou GLUT_STENCIL ou GLUT_DEPTH para os tipos de buffers da janela
  //Pode-se combinar esses modos por meio de um OR bitwise que é passado como argumento da função abaixo para que 
  //a janela tenha as capacidades desejadas
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); //Assim a janela suportará cores RGBA, com buffer duplo e profundidade 
  //==========================//

  //Cria a janela depois de tudo ser inicializado
  glutCreateWindow("Minha janela legal :)");
  //==========================//
  
  //Define as callbacks
  glutDisplayFunc(render); //Define qual função será chamada toda vez que a janela for renderizada
//  glutReshapeFunc(resize);//Callback para quando a janela for redimensionada
  
  //Começa o loop de processamento principal do GLUT
  glutMainLoop();

   return 0;
}
