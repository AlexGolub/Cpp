// drawShapes.cpp 
//
#include "stdafx.h"
#include <iostream>
#include <gl/glut.h>
#include <cmath>
#include <stdlib.h>
#include <windows.h>


#define SIZE 2000

float rotate = 0.0;

float start = 0.0;


using namespace std;

int sides;
const float DEG2RAD = 3.14159/180;
float PI = 3.1415;

void init( void )
{
	//Print version and graphic renderer
    printf( "OpenGL version: %s\n", (char*)glGetString(GL_VERSION ) );
    printf( "OpenGL renderer: %s\n", (char*)glGetString(GL_RENDERER ) );
 
    //Configure basic OpenGL settings
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glShadeModel( GL_SMOOTH );
    glEnable( GL_BLEND );
    glEnable( GL_TEXTURE_2D );
}


	void square( void )
	{
		//Clear the screen and set our initial view matrix
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
 

		//Draw a square
		glBegin(GL_QUADS);
    
		glVertex2f(-0.5, -0.5);
		glVertex2f( 0.5, -0.5);

		//         R    G    B
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f( 0.5, 0.5);
		glVertex2f(-0.5, 0.5);
		
		
		glEnd();

		glutSwapBuffers();
	}

	void triangle( void )
	{
		//Clear the screen and set our initial view matrix
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
 
		
		//Draw a triangle
		glBegin(GL_TRIANGLES);

		//         R    G    B
        glColor3f( 0.1, 0.2, 0.3 );

        glVertex3f( 0.3, 0.8, 0 );
        glVertex3f( 0.4, 0.2, 0 );
        glVertex3f( 0.7, 0.3, 0 );

		
		
		glEnd();

		glutSwapBuffers();
	}

	void glPolygon( unsigned int sides )
{
    if( sides < 3 ) return;

    const float PI = 3.14159;
    const float step = ( 2 * PI ) / static_cast< float > ( sides );

    glBegin( GL_LINE_LOOP );
    for( unsigned int i = 0; i < sides; ++i )
    {
        glVertex2f( cos( i * step ), sin( i * step ) );
    }
    glEnd();
}

void circle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for( i = 0; i <= lineAmount;i++ ) { 
			glVertex2f(
			    x + ( radius * cos( i *  twicePi / lineAmount ) ), 
			    y + ( radius* sin(i * twicePi / lineAmount ) )
			);
		}
	glEnd();
}

	void line( void )
	{
		//Clear the screen and set our initial view matrix
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Draw a line
		glLineWidth(2.5);

		//         R    G    B
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.5, 0.5, 0);

		glEnd();

		glutSwapBuffers();
	}

	class Shapes {
	public:
		Shapes ()
		{
			//Clear the screen and set our initial view matrix
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glColor3f(1.0, 0.0, 0.0);
		}


		void drawline( float x1, float y1, float x2, float y2 )
		{ 
			 glBegin( GL_LINE_STRIP ); 
			 glColor3f(1.0, 0.0, 0.0);
			 glVertex2f( x1, y1 );
			 glVertex2f( x2, y2 );
			 glEnd();
		} 


		void drawAxis( void )
		{
			glBegin(GL_LINES);

			glColor3f(1.0, 1.0, 1.0);

			glVertex3f(-2,0,0);
			glVertex3f(2,0,0);

			glVertex3f(0,-2,0);
			glVertex3f(0,2,0);

			glEnd();
		}
		virtual void draw( void ) = 0;
		
		
	};

	class Square: public Shapes {
	public:
		virtual void draw( void )
		{

			glBegin(GL_QUADS);
    
			glVertex2f(-0.5, -0.5);
			glVertex2f( 0.5, -0.5);

			glVertex2f( 0.5, 0.5);
			glVertex2f(-0.5, 0.5);
		

		}
	};

	class Triangle: public Shapes {
	public:
		virtual void draw( void )
		{
			glBegin(GL_TRIANGLES);


			glVertex3f( 0.3, 0.8, 0 );
			glVertex3f( 0.4, 0.2, 0 );
			glVertex3f( 0.7, 0.3, 0 );

		}
	};

	class Polygon: public Shapes {
	public:
		virtual void draw( void )
		{
			sides = 12;
			const float PI = 3.14159;
			const float step = ( 2 * PI ) / static_cast< float > ( sides );

			glBegin( GL_LINE_LOOP );
			for( int i = 0; i < sides; ++i )
			{
				glVertex2f( cos( i * step ), sin( i * step ) );
			}

		}
	};

	class Circle: public Shapes {
	public:
		virtual void draw()
		{
			int i;
			int lineAmount = 100; 
			
			GLfloat twicePi = 2.0f * PI;
	
			glBegin( GL_LINE_LOOP );
				for( i = 0; i <= lineAmount;i++ ) { 
					glVertex2f(
						0.2 + ( 0.3 * cos( i *  twicePi / lineAmount ) ), 
						0.2 + ( 0.3 * sin( i * twicePi / lineAmount ) )
					);
				}

		}
	};

	class Line: public Shapes {
	public:
		virtual void draw( void )
		{
				
			glLineWidth(2.5);

			glBegin(GL_LINES);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.5, 0.5, 0);


		}
	};

	class Sine: public Shapes {
		virtual void draw( void )
		{
			drawAxis();

			float x1, x2, y1, y2;
			for ( int i = 0; i < SIZE; i++)
			{ 
				 x1 = ( float )i / SIZE;
				 x2 = ( ( float )i + 1.0 ) / SIZE;

				 y1 = sin( x1 * 2 * PI );
				 y2 = sin( x2 * 2 * PI );

				 drawline( x1, y1, x2, y2 );

				 y1 = sin( -x1 * 2 * PI );
				 y2 = sin( -x2 * 2 * PI );

				 drawline( -x1, y1, -x2, y2 );

			}
		}

	};

	class Cosine : public Shapes
	{
		virtual void draw(void)
		{
			drawAxis();

			double x1, x2, y1, y2;
			for (int i = 0; i < SIZE; i++)
			{
				x1 = (double)i / SIZE;
				x2 = ((double)i + 1) / SIZE;

				y1 = cos(x1 * 2 * PI);
				y2 = cos(x2 * 2 * PI);

				drawline(x1, y1, x2, y2);

				y1 = cos(-x1 * 2 * PI);
				y2 = cos(-x2 * 2 * PI);

				drawline(-x1, y1, -x2, y2);
			}
		}
	};

	class Tangent : public Shapes
	{
		virtual void draw(void)
		{
			drawAxis();

			double x1, x2, y1, y2;

			for (int i = 0; i < SIZE; i++)
			{
				x1 = (double)i / SIZE;
				x2 = ((double)i + 1) / SIZE;

				y1 = tan(x1 * 2 * PI);
				y2 = tan(x1 * 2 * PI);

				drawline(x1, y1, x2, y2);

				y1 = tan(-x1 * 2 * PI);
				y2 = tan(-x2 * 2 * PI);

				drawline(-x1, y1, -x2, y2);
			}
		}
	};

	class Axis: public Shapes {
		virtual void draw( void )
		{
			glBegin(GL_LINES);

			glVertex3f(-2,0,0);
			glVertex3f(2,0,0);

			glVertex3f(0,-2,0);
			glVertex3f(0,2,0);

		}
	};

	class Cycloid : public Shapes
	{
		virtual void draw()
		{
			glBegin(GL_LINES);



			glVertex3f(0, -2, 0);
			glVertex3f(0, 0, 0);

			glVertex3f(2, -1, 1);
			glVertex3f(-1, 1, 1);

			glVertex3f(1, 1, 1);
			glVertex3f(2, 2, 2);
		}
	};



void display( void )
{
	Sine a;
	Shapes *shape = &a;
	shape->draw();
		


	/*Shapes *arr[ 8 ];

	arr[ 0 ] = new Square;
	arr[ 1 ] = new Triangle;
	arr[ 2 ] = new Polygon;
	arr[ 3 ] = new Circle;
	arr[ 4 ] = new Line;
	arr[ 5 ] = new Sine;
	arr[ 6 ] = new Cosine;
	arr[ 7 ] = new Tangent;

	for (int i = 0; i < sizeof( arr )/sizeof( arr[0] )-1; i++ ) {
		arr[ i ]->draw();
	}

	for (int i = 0; i < sizeof( arr )/sizeof( arr[0] ); i++ ) {
		delete arr[ i ];
	}*/

	glEnd();
	glutSwapBuffers();

}


void main( int argc, char** argv )
{
		glutInit( &argc, argv );
		glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB );
		glutInitWindowSize ( 800, 600 );
		glutInitWindowPosition ( 100, 100 );
		glutCreateWindow( "OpenGL Test" );
		glutDisplayFunc( display );

		init();
 
		glutMainLoop();
}

