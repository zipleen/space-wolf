//////////////////////////////////////////////////////////////////////
//
// glPoint.h: interface for the glPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLPOINT_H__ADADC708_0176_471A_8241_5DD4D700BCB2__INCLUDED_)
#define AFX_GLPOINT_H__ADADC708_0176_471A_8241_5DD4D700BCB2__INCLUDED_

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif


class glPoint  
{
public:
	glPoint();
	virtual ~glPoint();
	GLfloat z;
	GLfloat y;
	GLfloat x;
};

#endif // !defined(AFX_GLPOINT_H__ADADC708_0176_471A_8241_5DD4D700BCB2__INCLUDED_)
