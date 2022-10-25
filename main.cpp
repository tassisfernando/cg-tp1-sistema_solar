
/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

// Vari�veis que guardam a transla��o que ser� aplicada
// sobre a casinha
GLfloat Tx;
GLfloat Ty;

// Vari�veis que guardam os valores m�nimos de x e y da
// casinha
GLfloat minX, maxX;
GLfloat minY, maxY;

// Vari�veis que guardam o tamanho do incremento nas
// dire��es x e y (n�mero de pixels para se mover a
// cada intervalo de tempo)
GLfloat xStep;
GLfloat yStep;

// Vari�veis que guardam a largura e altura da janela
GLfloat windowXmin, windowXmax;
GLfloat windowYmin, windowYmax;

GLfloat ang1 = 0;

GLsizei largura, altura;

int win = 250;

int exibeTempo = 1;

bool stopAnimate = false;

bool showOrbit = true;

bool showMercury = true;

bool showVenus = true;

bool showEarth = true;

bool showMars = true;

bool showJupiter = true;

bool showSaturn = true;

bool showUranus = true;

bool showNeptune = true;

bool showSun = true;

void DesenhaSatelite() {
    int vertices = 30;
    float raio = 1.5f;
	glColor3f(1.0f, 1.0f, 1.0f);

    // Desenha circulo
	float angulo, incremento;

	incremento = (2 * M_PI) / vertices;

	glBegin(GL_POLYGON);
     for(angulo=0; angulo<2*M_PI; angulo+=incremento){
        glVertex2f(raio*cos(angulo),raio*sin(angulo));
        glVertex2d(raio*cos(angulo+incremento), raio*sin(angulo+incremento));
     }
    glEnd();
}

void DesenhaAstro(float raio, GLfloat red, GLfloat green, GLfloat blue) {
    int vertices = 30;
	glColor3f(red, green, blue);

    // Desenha circulo
	float angulo, incremento;

	incremento = (2 * M_PI) / vertices;

	glBegin(GL_POLYGON);
     for(angulo=0; angulo<2*M_PI; angulo+=incremento){
        glVertex2f(raio*cos(angulo),raio*sin(angulo));
        glVertex2d(raio*cos(angulo+incremento), raio*sin(angulo+incremento));
     }
    glEnd();
}

void DesenhaOrbita(float raio) {
    int vertices = 100;
    glColor3f(1.0f, 1.0f, 1.0f);

    // Desenha circulo
	float angulo, incremento;

	incremento = (2 * M_PI) / vertices;

	glBegin(GL_LINES);
     for(angulo=0; angulo<2*M_PI; angulo+=incremento){
        glVertex2f(raio*cos(angulo),raio*sin(angulo));
        glVertex2d(raio*cos(angulo+incremento), raio*sin(angulo+incremento));
     }
    glEnd();
}

void DesenhaNetuno() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(200.0f);
        glPopMatrix();
    }
    if(showNeptune) {
        glPushMatrix();
            glRotatef(ang1/64, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(-200, 0, 0.0f);
                glRotatef(ang1*18, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(11.0f, 0.1f, 0.1f, 0.9f);
                DesenhaOrbita(17.0f);

                glTranslatef(17, 0, 0.0f);
                DesenhaSatelite();
                glTranslatef(-34, 0, 0.0f);
                DesenhaSatelite();
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaUrano() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(175.0f);
        glPopMatrix();
    }
    if(showUranus) {
        glPushMatrix();
            glRotatef(ang1/32, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(175, 0, 0.0f);
                glRotatef(ang1*18, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(12.0f, 0.5f, 0.6f, 0.0f);
                DesenhaOrbita(15.0f);
                DesenhaOrbita(17.0f);

                glTranslatef(15, 0, 0.0f);
                DesenhaSatelite();
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaSaturno() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(150.0f);
        glPopMatrix();
    }
    if(showSaturn) {
        glPushMatrix();
            glRotatef(ang1/24, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(-150, 0, 0.0f);
                glRotatef(ang1*21, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(10.0f, 0.5f, 0.1f, 0.5f);
                DesenhaOrbita(15.0f);
                DesenhaOrbita(17.0f);
                DesenhaOrbita(19.0f);
                DesenhaOrbita(21.0f);

                glTranslatef(17, 0, 0.0f);
                DesenhaSatelite();
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaJupiter() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(125.0f);
        glPopMatrix();
    }
    if(showJupiter) {
        glPushMatrix();
            glRotatef(ang1/16, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(125, 0, 0.0f);
                glRotatef(ang1*20, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(14.0f, 1.0f, 0.5f, 0.5f);
                DesenhaOrbita(19.0f);

                glTranslatef(19, 0, 0.0f);
                DesenhaSatelite();
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaMarte() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(100.0f);
        glPopMatrix();
    }
    if(showMars) {
        glPushMatrix();
            glRotatef(ang1/2, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(-100, 0, 0.0f);
                glRotatef(ang1*16, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(7.0f, 1.0f, 0.0f, 0.0f);

                glTranslatef(13, 0, 0.0f);
                DesenhaSatelite();
                glTranslatef(-26, 0, 0.0f);
                DesenhaSatelite();
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaTerra() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(75.0f);
        glPopMatrix();
    }
    if(showEarth) {
        glPushMatrix();
            glRotatef(ang1, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(75, 0, 0.0f);
                glRotatef(ang1*16, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(9.0f, 0.0f, 0.0f, 1.0f);

                glTranslatef(15, 0, 0.0f);
                DesenhaSatelite();
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaVenus() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(50.0f);
        glPopMatrix();
    }
    if(showVenus) {
        glPushMatrix();
            glRotatef(ang1*2, 0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(-50, 0, 0.0f);
                glRotatef(ang1*2, 0.0f, 0.0f, 1.0f);
                DesenhaAstro(7.0f, 1.0f, 0.0f, 1.0f);
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaMercurio() {
    if(showOrbit) {
        glPushMatrix();
            DesenhaOrbita(30.0f);
        glPopMatrix();
    }
    if(showMercury) {
        glPushMatrix();
            glRotatef(ang1*4, 0.0f, 0.0f, 1.0f); // translação
            glPushMatrix();
                glTranslatef(30, 0, 0.0f); // manda pra órbita
                glRotatef(ang1*5, 0.0f, 0.0f, 1.0f); // rotação
                DesenhaAstro(5.0f, 1.0f, 0.0f, 0.5f);
            glPopMatrix();
        glPopMatrix();
    }
}

void DesenhaSol() {
    if(showSun) {
        glPushMatrix();
            glRotatef(ang1, 0.0f, 0.0f, 1.0f);
            DesenhaAstro(20.0f, 1.0f, 1.0f, 0.0f);
        glPopMatrix();
    }
}

// Fun��o callback de redesenho da janela de visualiza��o
void DesenhaSistemaSolar(void)
{
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transforma��o corrente
	glLoadIdentity();

	// Limpa a janela de visualiza��o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Aplica uma transla��o sobre a casinha
	//glTranslatef(Tx, Ty, 0.0f);
    //glRotatef(ang1,0.0f,0.0f,1.0f);

    DesenhaSol();

    DesenhaMercurio();

    DesenhaVenus();

    DesenhaTerra();

    DesenhaMarte();

    DesenhaJupiter();

    DesenhaSaturno();

    DesenhaUrano();

    DesenhaNetuno();

	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as vari�veis
	largura = w;
	altura = h;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior,
	// superior) mantendo a propor��o com a janela de visualiza��o
	if (largura <= altura)
	{
		gluOrtho2D (-250.0f, 250.0f, -250.0f*altura/largura, 250.0f*altura/largura);
	}
	else
	{
		gluOrtho2D (-250.0f*largura/altura, 250.0f*largura/altura, -250.0f, 250.0f);
	}
}

// Fun��o callback chamada pela GLUT a cada intervalo de tempo
void Anima(int value)
{

    ang1 += 0.5;

	glutPostRedisplay();

	if(!stopAnimate)
        glutTimerFunc(10, Anima, 1);

    int angF = (int) ang1;
    if ((angF % 360) == 0) {

        if (exibeTempo == 1) {
            cout << "Tempo da Terra: " << angF / 360 << " anos\n";
            exibeTempo = 0;
        } else {
            exibeTempo = 1;
        }
    }
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	switch (key) {
	    case 27:
            exit(0);
            break;
		case 'p':
		    stopAnimate = !stopAnimate;
            if(!stopAnimate){
                glutTimerFunc(10, Anima, 1);
            }
            break;
        case 'o':
            showOrbit = !showOrbit;
            break;
        case 'm':
            showMercury = !showMercury;
            break;
        case 'v':
            showVenus = !showVenus;
            break;
        case 't':
            showEarth = !showEarth;
            break;
        case 'a':
            showMars = !showMars;
            break;
        case 'j':
            showJupiter = !showJupiter;
            break;
        case 's':
            showSaturn = !showSaturn;
            break;
        case 'u':
            showUranus = !showUranus;
            break;
        case 'n':
            showNeptune = !showNeptune;
            break;
        case 'x':
            showSun = !showSun;
            break;
	}
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Inicializa��o das vari�veis globais
	xStep = yStep = 0.1f;
	Tx = Ty = 0.0f;
	minX = -5.1f;
	maxX =  5.1f;
	minY = -5.1f;
	maxY =  5.1f;
	windowXmin = windowYmin = -40.0f;
	windowXmax = windowYmax = 40.0f;
}


// Programa Principal
int main(int argc, char *argv[])
{
    // Utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Sistema solar");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(DesenhaSistemaSolar);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Registra a fun��o callback que ser� chamada a cada intervalo de tempo
	glutTimerFunc(10, Anima, 1);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
