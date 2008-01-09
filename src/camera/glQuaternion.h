//////////////////////////////////////////////////////////////////////
//
// glQuaternion.h: interface for the glQuaternion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLQUATERNION_H__52FB84BB_6D1B_4314_833F_5A8737A35DAB__INCLUDED_)
#define AFX_GLQUATERNION_H__52FB84BB_6D1B_4314_833F_5A8737A35DAB__INCLUDED_

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
#include <math.h>

#define PI			3.14159265358979323846

class glQuaternion  
{
public:
	glQuaternion operator *(glQuaternion q);
	void CreateMatrix(GLfloat *pMatrix);
	void CreateFromAxisAngle(GLfloat x, GLfloat y, GLfloat z, GLfloat degrees);
	glQuaternion();
	virtual ~glQuaternion();

private:
	GLfloat m_w;
	GLfloat m_z;
	GLfloat m_y;
	GLfloat m_x;
};

#endif // !defined(AFX_GLQUATERNION_H__52FB84BB_6D1B_4314_833F_5A8737A35DAB__INCLUDED_)
