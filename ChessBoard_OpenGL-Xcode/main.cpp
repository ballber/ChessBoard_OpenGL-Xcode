//
//  main.cpp
//  ChessBoardOpenGL
//
//  Created by Josep B on 3/11/18.
//  Copyright © 2018 Universitat de Lleida. All rights reserved.
//
// 1. To solve linking error "linker command failed with exit code 1 (use -v to see invocation)" config buid settings from IDE xCode adding linker flags:
// xCode IDE > Select ChessBoardOpenGL project> Build Settings >All > Linking > Other linker flags > + > -framework OpenGL -framework GLUT -L /System/Library/Frameworks/OpenGL.framework/
// 2.Remove Warnings Deprecated functions : xCode > Select ChessBoardOpenGL > Build Settings > Search > deprecated > Deprecated Functions NO

// "Play" button to run ChessBoard , and CMD+q to close screen.

#include <iostream>
#include <GLUT/glut.h>

#define COLUMNS 8
#define ROWS 8
#define WIDTH 600
#define HEIGHT 600

//-----------------------------------------------

void display();;
void keyboard(unsigned char c,int x,int y);

//-----------------------------------------------

int keyflag=0;

//-----------------------------------------------
// -- MAIN PROCEDURE
//-----------------------------------------------

int main(int argc,char *argv[])
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Chess board");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,WIDTH-1,0,HEIGHT-1);
    
    glutMainLoop();
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    return 0;
}

//------------------------------------------------------------
//-- Display the chess board
//------------------------------------------------------------

void display()
{
    int i,j;
    
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(i=0;i<WIDTH;i++)
        for(j=0;j<HEIGHT;j++)
            if( (keyflag==0 && (i+j)%2==0) || (keyflag==1 && (i+j)%2==1) )
            {
                glColor3f(0.8,0.8,0.8);
                glBegin(GL_QUADS);
                
                glVertex2i(i*WIDTH/COLUMNS,j*HEIGHT/ROWS);
                glVertex2i((i+1)*WIDTH/COLUMNS,j*HEIGHT/ROWS);
                glVertex2i((i+1)*WIDTH/COLUMNS,(j+1)*HEIGHT/ROWS);
                glVertex2i(i*WIDTH/COLUMNS,(j+1)*HEIGHT/ROWS);
                
                glEnd();
            }
    
    glutSwapBuffers();
    
}

//-----------------------------------------------
//-----------------------------------------------
void keyboard(unsigned char c,int x,int y)
{
    if(keyflag==0)
        keyflag=1;
    else
        keyflag=0;
    
    glutPostRedisplay();
    
};

