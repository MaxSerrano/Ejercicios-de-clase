//Semestre 2019 - 2
/*

  Serrano Martínez Max Yael
  Grupo 02
  visual studio 2017
  Práctica 2
  Manual de uso:
*/

#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	glBegin(GL_POLYGON); //DIBUJA point y line, etc.
	//C
	
	glColor3f(1, 0, 0);
	glVertex3f(-9, 0, 1);
	glVertex3f(-9.5, 0, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-9.5, 4, 1);
	glVertex3f(-9, 4, 1);
	glEnd();  //necesario

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(-9, 0, 1);
	glVertex3f(-7, 0, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-7, .5, 1);
	glVertex3f(-9, .5, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(-9, 4, 1);
	glVertex3f(-7, 4, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-7, 3.5, 1);
	glVertex3f(-9, 3.5, 1);
	glEnd();

	///////////////////// G
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(-6, 0, 1);
	glVertex3f(-6.5, 0, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-6.5, 4, 1);
	glVertex3f(-6, 4, 1);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(-6, 4, 1);
	glVertex3f(-4, 4, 1);
	glColor3f(0, 1, 1);
	glVertex3f(-4, 3.5, 1);
	glVertex3f(-6, 3.5, 1);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(-6, 0, 1);
	glVertex3f(-4, 0, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-4, .5, 1);
	glVertex3f(-6, .5, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(-4.5, 0, 1);
	glVertex3f(-4, 0, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-4, 2, 1);
	glVertex3f(-4.5, 2, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(-4, 2, 1);
	glVertex3f(-5, 2, 1);
	glColor3f(0, 1, 1);
	glVertex3f(-5, 1.5, 1);
	glVertex3f(-4, 1.5, 1);
	glEnd();

	/////////////////// Letra M
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(-3, 0, 1);
	glVertex3f(-3.5, 0, 1);
	glColor3f(0, 1, 1);
	glVertex3f(-3.5, 4, 1);
	glVertex3f(-3, 4, 1);
	glEnd(); //palito

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	 glVertex3f(-3.5, 4.5, 1);
	 glVertex3f(-3.5, 3.5, 1);
	glColor3f(0, 0, 1);
	 glVertex3f(-1, 1, 1);
	 glVertex3f(-1, 1.5, 1);
	glEnd(); // El dificil

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(-1, 1.5, 1);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1.5, 3.5, 1);
	glVertex3f(1.5, 4.5, 1);
	glEnd(); // El dificilp2

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1.5, 0, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1.5, 4, 1);
	glVertex3f(1, 4, 1);
	glEnd(); //palito2

	//////// LETRA S
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex3f(2.5, 2, 1);
	glVertex3f(3, 2, 1);
	glColor3f(0, 1, 1);
	glVertex3f(3, 4.5, 1);
	glVertex3f(2.5, 4.5, 1);
	glEnd();  //necesario //PALITO

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);

	glVertex3f(2.5, 4, 1);
	glVertex3f(6, 4, 1);
	glColor3f(1, 0, 1);

	glVertex3f(6, 4.5, 1);
	glVertex3f(2.5, 4.5, 1);
	glEnd();  //necesario //PALITO

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);

	glVertex3f(2.5, 2, 1);
	glVertex3f(6, 2, 1);
	glColor3f(1, 0, 1);

	glVertex3f(6, 2.5, 1);
	glVertex3f(2.5, 2.5, 1);
	glEnd();  //necesario //PALITO2

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);

	glVertex3f(2.5, 0, 1);
	glVertex3f(6, 0, 1);
	glColor3f(0, 1, 1);

	glVertex3f(6, 0.5, 1);
	glVertex3f(2.5, 0.5, 1);
	glEnd();  //necesario //PALITO3


	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);

	glVertex3f(5.5, 0, 1);
	glVertex3f(6, 0, 1);
	glColor3f(1, 0, 1);

	glVertex3f(6, 2.5, 1);
	glVertex3f(5.5, 2.5, 1);
	glEnd();  //necesario //PALITOverticalfinl






	

	
	
	
											

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10,10,-10,10,-1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

