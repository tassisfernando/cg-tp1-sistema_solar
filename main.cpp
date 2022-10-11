
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

bool stopAnimate = true;

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
    glPushMatrix();
        DesenhaOrbita(200.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-200, 0, 0.0f);
        DesenhaAstro(11.0f, 0.1f, 0.1f, 0.9f);
        DesenhaOrbita(17.0f);

        glTranslatef(-15, 0, 0.0f);
        DesenhaSatelite();
        glTranslatef(15, 0, 0.0f);
        DesenhaSatelite();
    glPopMatrix();
}

void DesenhaUrano() {
    glPushMatrix();
        DesenhaOrbita(175.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(175, 0, 0.0f);
        DesenhaAstro(12.0f, 0.5f, 0.6f, 0.0f);
        DesenhaOrbita(15.0f);
        DesenhaOrbita(17.0f);

        glTranslatef(15, 0, 0.0f);
        DesenhaSatelite();
    glPopMatrix();
}

void DesenhaSaturno() {
    glPushMatrix();
        DesenhaOrbita(150.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-150, 0, 0.0f);
        DesenhaAstro(10.0f, 0.5f, 0.1f, 0.5f);
        DesenhaOrbita(15.0f);
        DesenhaOrbita(17.0f);
        DesenhaOrbita(19.0f);
        DesenhaOrbita(21.0f);

        glTranslatef(15, 0, 0.0f);
        DesenhaSatelite();
    glPopMatrix();
}

void DesenhaJupiter() {
    glPushMatrix();
        DesenhaOrbita(125.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(125, 0, 0.0f);
        DesenhaAstro(14.0f, 1.0f, 0.5f, 0.5f);
        DesenhaOrbita(19.0f);

        glTranslatef(15, 0, 0.0f);
        DesenhaSatelite();
    glPopMatrix();
}

void DesenhaMarte() {
    glPushMatrix();
        DesenhaOrbita(100.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-100, 0, 0.0f);
        DesenhaAstro(7.0f, 1.0f, 0.0f, 0.0f);

        glTranslatef(-15, 0, 0.0f);
        DesenhaSatelite();
        glTranslatef(15, 0, 0.0f);
        DesenhaSatelite();
    glPopMatrix();
}

void DesenhaTerra() {
    glPushMatrix();
        DesenhaOrbita(75.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(75, 0, 0.0f);
        DesenhaAstro(9.0f, 0.0f, 0.0f, 1.0f);

        glTranslatef(15, 0, 0.0f);
        DesenhaSatelite();
    glPopMatrix();
}

void DesenhaVenus() {
    glPushMatrix();
        DesenhaOrbita(50.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-50, 0, 0.0f);
        DesenhaAstro(7.0f, 1.0f, 0.0f, 1.0f);
    glPopMatrix();
}

void DesenhaMercurio() {
    glPushMatrix();
        DesenhaOrbita(25.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(25, 0, 0.0f);
        DesenhaAstro(5.0f, 1.0f, 0.0f, 0.5f);
    glPopMatrix();
}

void DesenhaSol() {
    glPushMatrix();
        DesenhaAstro(20.0f, 1.0f, 1.0f, 0.0f);
    glPopMatrix();
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
		gluOrtho2D (-200.0f, 200.0f, -200.0f*altura/largura, 200.0f*altura/largura);
	}
	else
	{
		gluOrtho2D (-200.0f*largura/altura, 200.0f*largura/altura, -200.0f, 200.0f);
	}
}

// Fun��o callback chamada pela GLUT a cada intervalo de tempo
void Anima(int value)
{
	// Muda a dire��o quando chega na borda esquerda ou direita
	if( (Tx+maxX) > windowXmax || (Tx+minX) < windowXmin )
		xStep = -xStep;

	// Muda a dire��o quando chega na borda superior ou inferior
	if( (Ty+maxY) > windowYmax || (Ty+minY) < windowYmin )
		yStep = -yStep;

	// Move a casinha
	Tx += xStep;
	Ty += yStep;

    ang1 += 0.5;

	// Redesenha a casinha em outra posi��o
	glutPostRedisplay();
	if(stopAnimate)
        glutTimerFunc(10,Anima, 1);
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);

    if (key == 80 || key == 112){
        stopAnimate = !stopAnimate;
        if(stopAnimate){
            glutTimerFunc(10, Anima, 1);
        }
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
