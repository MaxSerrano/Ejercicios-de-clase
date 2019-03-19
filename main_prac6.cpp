//Semestre 2019 - 2
/*Serrano Martinez Max Yael
grupo 02
visual studio 2017
Practica 6






*/
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement
//venus se utiliza como movimiento de luna
int sol = 0;
int mercurio = 0, mercurioT = 0;
int venus = 0, venusT = 0;
int tierra = 0, tierraT = 0;
int marte = 0, marteT = 0;
int jupiter = 0, jupiterT = 0;
int saturno = 0, saturnoT = 0;
int urano, uranoT;
int neptuno = 0, neptunoT = 0;

float transX = 0.0f, transY = 0.0f;
float camaraZ = 0.0;
float camaraX = 0.0;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

float transZ = 0.0f;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;

//arreglos con formato RGB. COMPONENTES DE LA LUZ 
GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values R,G,B,Alfa(material)
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values puede o no puede estar 
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position X,Y,Z
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position misma luz, sod posiciones distintas 
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			// Light Position
															//COMPONENTES DE MATERIAL (un solo materia)
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background R,G,B,Alfa
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest  ¡depende que tan elevado este el reflejo
//un solo material

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };		// Light Position

GLfloat MerDiffuse[] = { 0.80, 0.45, 0.27, 1.0f };			// Mercurio
GLfloat MerSpecular[] = { 0.80, 0.45, 0.27, 1.0 };
GLfloat MerShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.78, 0.76, 0.74, 1.0f };			//venus
GLfloat VenusSpecular[] = { 0.78, 0.76, 0.74, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat ADiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// anillo
GLfloat ASpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat AShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { .5, 0.5, 0.5, 1.0f };			// Luna
GLfloat MoonSpecular[] = { .5, 0.5, 0.5, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 1, 0, 0, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1, 0, 0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupDiffuse[] = { 0.77, 0.81, 0.87, 1.0f };			// jupiter
GLfloat JupSpecular[] = { 0.77, 0.81, 0.87, 1.0 };
GLfloat JupShininess[] = { 50.0 };

GLfloat SatDiffuse[] = { .95, 0.84, 0.64, 1.0f };			// saturno
GLfloat SatSpecular[] = { .95, 0.84, 0.64, 1.0 };
GLfloat SatShininess[] = { 50.0 };

GLfloat UrDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// urano
GLfloat UrSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UrShininess[] = { 50.0 };

GLfloat NepDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Neptuno
GLfloat NepSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NepShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light 8 luces en un mismo escenario
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light
																	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
																	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

																	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
													//glEnable(GL_LIGHT0);



}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHTING);

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	glRotatef(transX, 1, 0, 0);
	glRotatef(transY, 0, 1, 0);
	glPushMatrix();

	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glDisable(GL_LIGHTING);
	glutSolidSphere(2, 25, 25);  //Draw Sun (radio,H,V);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();//mercurio
	glRotatef(mercurioT, 0, 1, 0);
	glColor3f(0.80, 0.45, 0.27);
	glTranslated(3, 0, 0);
	glRotatef(mercurio, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MerDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MerSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MerShininess);
	glutSolidSphere(.2, 12, 12);
	glPopMatrix();


	glPushMatrix();//venus
	glRotatef(venusT, 0, 1, 0);
	glColor3f(0.78, 0.76, 0.74);
	glTranslated(4.25, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
	glutSolidSphere(.5, 12, 12);
	glPopMatrix();

	glPushMatrix();//tierra
	glRotatef(tierraT, 0, 1, 0);
	glColor3f(0, 0, 1);
	glTranslated(7, 0, 0);
	glRotatef(tierra, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(.7, 12, 12);

	glPushMatrix(); //luna
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(1.25, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,	MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,	MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(.1, 12, 12);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();//marte
	glRotatef(marteT, 0, 1, 0);
	glColor3f(1, 0, 0);
	glTranslated(10, 0, 0);
	glRotatef(marte, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutSolidSphere(.3, 12, 12);

	glPushMatrix();
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(.75, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//jupiter
	glRotatef(jupiterT, 0, 1, 0);
	glColor3f(0.77, 0.81, 0.87);
	glTranslated(14, 0, 0);
	glRotatef(jupiter, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupShininess);
	glutSolidSphere(1, 12, 12);

	glPushMatrix(); //luna
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(1.5, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(.1, 12, 12);
	glPopMatrix();

	glPushMatrix();//luna
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(-1.5, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Saturno
	glRotatef(saturnoT, 0, 1, 0);
	glColor3f(.95, 0.84, 0.64);
	glTranslated(20, 0, 0);
	glRotatef(saturno, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SatDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SatSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SatShininess);
	glutSolidSphere(.9, 12, 12);

	glPushMatrix();//anillo
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(0.1, 0, 0);
	glRotatef(75, 1, 0, 0);
	glutSolidTorus(.05, 1.52, 10, 10);
	glPopMatrix();

	glPushMatrix(); //anillo2
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(0.1, 0, 0);
	glRotatef(-75, 1, 1, 0);
	glutSolidTorus(.05, 1.52, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//urano
	glRotatef(uranoT, 0, 1, 0);
	glColor3f(.62, 0.96, 0.96);
	glTranslated(25, 0, 0);
	glRotatef(urano, 0, 1, 0);
	glutSolidSphere(.7, 12, 12);

	glPushMatrix();//luna
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(1, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glutSolidSphere(.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//neptuno
	glRotatef(neptunoT, 0, 1, 0);
	glColor3f(.25, 0.37, 0.93);
	glTranslated(29, 0, 0);
	glRotatef(neptuno, 0, 1, 0);
	glutSolidSphere(.7, 12, 12);

	glPushMatrix();
	glRotatef(venusT, 0, 1, 0);
	glColor3f(.5, 0.5, 0.5);
	glTranslated(1.25, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glutSolidSphere(.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		mercurio = (mercurio + 10) % 360;
		mercurioT = (mercurioT - 2) % 360;

		venus = (venus + 7) % 360;
		venusT = (venusT + 3) % 360;

		tierra = (tierra + 8) % 360;
		tierraT = (tierraT - 4) % 360;

		marte = (marte + 7) % 360;
		marteT = (marteT + 5) % 360;

		jupiter = (jupiter + 10) % 360;
		jupiterT = (jupiterT - 6) % 360;

		saturno = (saturno + 7) % 360;
		saturnoT = (saturnoT + 7) % 360;

		urano = (urano + 10) % 360;
		uranoT = (uranoT - 8) % 360;

		neptuno = (neptuno + 10) % 360;
		neptunoT = (neptunoT - 2) % 360;

		dwLastUpdateTime = dwCurrentTime; //reinicia un ciclo
	}

	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

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
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
//cuidado, carga  }¡¡¡