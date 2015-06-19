/**
 ***********************************************************************
 * \file GlutMain.cpp
 ***********************************************************************
 * 
 *
 ***********************************************************************
 * \author		Diego Mazala - diegomazala@gmail.com
 * \date		January, 2009
 ***********************************************************************/
 
 
#include <iostream>
#include "GlutApp.h"
#include "GlutWindow.h"


class MyWindow : public GlutWindow
{
public:
	MyWindow():GlutWindow(){}
	virtual ~MyWindow(){}


protected:
	virtual void OnRender(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		gluLookAt(	0.0, 0.0, 5.0, 
					0.0, 0.0, -1.0,
					0.0, 1.0, 0.0);

		glColor3f(0.7f, 0.5f, 0.9f);
		glutSolidTeapot(1);

		DisplayString("Hello Glut Window", 10, 20);

		glutSwapBuffers();
	}

	virtual void OnInit(void)
	{
		glEnable(GL_DEPTH_TEST);  
		glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
		glEnable(GL_CULL_FACE);
	}

	virtual void OnResize(int w, int h)
	{
		glViewport(0,0,w,h);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0, (double)w/(double)h, 0.1, 1000.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	virtual void OnKeyDown(int nKey, char cAscii)
	{       
		if (cAscii == 27) // 0x1b = ESC
		{
			this->Close(); // Close Window!
			GlutApp::Exit();
		} 
	}
};





int main(int argc, char** argv)
{
	GlutApp::Init(&argc, argv);

	MyWindow lWin; 
	lWin.Create("My first Window", GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

	MyWindow lWin2;
	lWin2.Create("My first Window 2", GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

	GlutApp::Run();

	return GlutApp::Exit();
}
 
 
 
 
 
 