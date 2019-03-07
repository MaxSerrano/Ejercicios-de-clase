//Semestre 2019-2
/*
Serrano Martiínez Max Yael
GRupo 02
visualstudio 2017
Practica 5
manual de uso:
w: enfrente
s: atras
d:izquierda
a:derecha
flechas: izquierda y derecha : angulo de eje x
felchas : arriba, abajo angulo  de eje y 
p,P: movimiento de el hombro
O,o: movimiento de codo
i,I: movimiento de muñeca
B,b: MOVIMIENTO DE PULGAR
Z,z; X,x movimiento indice*/
/////////////////////////////////////////////////
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0f;
float angCodo = 0.0f;
float angMu = 0.0f;
float angPul = 0.0f;
float angIN1 = 0.0f;
float angIN2 = 0.0f;
float angIN3 = 0.0f;
float angAN1 = 0.0f;
float angAN2 = 0.0f; 
float angAN3 = 0.0f;
float angME1 = 0.0f;
float angME2 = 0.0f;
float angME3 = 0.0f;
float angP1 = 0.0f;
float angP2 = 0.0f;
float angP3 = 0.0f;



GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí. //esta en un loop
//hombro
	glRotatef(angHombro, 0, 0, 1);
	glScalef(0.3, 0.45, 0.5);
	glColor3f(1, 1, 1);
	prisma();
	glScalef(3, 2, 1);
	//bisep
	glTranslatef(0.65, 0, 0);
	glScalef(1, 0.45, 1);
	glColor3f(1, 0, 0); //loop infinito al mover
	prisma();
	glScalef(1, 2, 1);
	//codo
	glTranslatef(0.6, 0, 0);
	glRotatef(angCodo, 0, 0, 1);
	glScalef(0.2, 0.40, 1);
	glColor3f(0, 1, 0);
	prisma();
	glScalef(5, 2, 1);
	//antebrazo
	glTranslatef(0.5, 0, 0);
	glScalef(0.8, 0.3, 1);
	glColor3f(0, 0, 1);
	prisma();
	glScalef(1.25, 2, 1);
	//muñeca
	glTranslatef(0.45, 0, 0);
	glRotatef(angMu, 0, 0, 1);
	glScalef(0.1, 0.2, 1);
	glColor3f(0.5, 0, 0.2);
	prisma();
	glScalef(10, 2, 1);
	//palma
	glTranslatef(0.35, 0, 0);
	glScalef(0.6, 0.2, 1);
	glColor3f(0, 1, 1);
	prisma();
	glScalef(1.66, 2, 1);
	//pulgar
	glTranslatef(-0.1, 0.1, -0.655);
	//rotacion
	glScalef(0.15, 0.07, 0.3);//Y=ancho Z=largo
	glColor3f(0, 1, 0);
	prisma();
	glScalef(6.66, 28.57, 1);
	//Faltante de pulgar
	glTranslatef(0, 0, -0.655);
	glRotatef(angPul, 1, 0, 0);
	glScalef(0.15, 0.07, 0.3);
	glColor3f(1,0,0);
    prisma();
	glScalef(6.66, 17.28, 3);
	//indice1
	glTranslatef(0.5, 0, 1.6);
	glScalef(0.35, 0.09, 0.6);
	glColor3f(1, 1, 0);
	prisma();
	glScalef(2.85, 11.11, 1.6);
	//indice2
	glTranslatef(0.18, 0, 0);
	glScalef(0.18, 0.09, 0.6);
	glColor3f(0, 1, 0);
	prisma();
	glScalef(5.55, 11.11, 1.6);
	//indice3
	glTranslatef(0.15, 0, 0);
	glScalef(0.15, 0.09, 0.6);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(6.66, 11.11, 1.6);
	//Medio
	glTranslatef(-0.28, 0, 1.2);
	glScalef(0.35, 0.2, 0.6);
	glColor3f(1, 1, 0);
	prisma();
	glScalef(2.85, 5, 1.66);
	//medio1
	glTranslatef(0.18, 0, 0);
	glScalef(0.4, 0.09, 0.6);
	glColor3f(0, 1, 0);
	prisma();
	glScalef(2.5, 11.11, 1.6);
	//medio2
	glTranslatef(0.25, 0, 0);
	glScalef(0.15, 0.09, 0.6);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(6.66, 11.11, 1.6);
	//anular
	glTranslatef(-0.5, 0, 1.2);
	glScalef(0.35, 0.2, 0.6);
	glColor3f(1, 1, 0);
	prisma();
	glScalef(2.85, 5, 1.66);
	//anular1
	glTranslatef(0.18, 0, 0);
	glScalef(0.28, 0.09, 0.6);
	glColor3f(0, 1, 0);
	prisma();
	glScalef(2.57, 11.11, 1.6);
	//anular2
	glTranslatef(0.3, 0, 0);
	glScalef(0.18, 0.09, 0.6);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(5.55, 11.11, 1.6);
	//meñique
	glTranslatef(-0.7, 0, 1.2);
	glScalef(0.3, 0.2, 0.6);
	glColor3f(1, 1, 0);
	prisma();
	glScalef(5, 5, 1.66);
	//meñique1
	glTranslatef(0.18, 0, 0);
	glScalef(0.15, 0.09, 0.6);
	glColor3f(0, 1, 0);
	prisma();
	glScalef(2.5, 11.11, 1.6);
	//meñique2
	glTranslatef(0.28, 0, 0);
	glScalef(0.18, 0.09, 0.6);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(5.55, 11.11, 1.6);









	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'p':
		if (angHombro < 90)
			angHombro += 0.5f;
		//printf("ang: %f", angHombro);
		break;
	case 'P':
		if (angHombro > -90)
			angHombro -= 0.5f;
		break;
	case 'o':
		if (angCodo < 120)
			angCodo += 0.5f;
		break;
	case 'O':
		if (angCodo > 0)
			angCodo -= 0.5f;
		break;
	case 'i':
		if (angMu < 60)
			angMu += 0.5f;
		break;
	case 'I':
		if (angMu > -45)
			angMu -= 0.5f;
		break;
	case 'b':
		if (angPul < 45)
			angPul += 0.5f;
		break;
	case 'B':
		if (angPul > 0)
			angPul -= 0.5f;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}
