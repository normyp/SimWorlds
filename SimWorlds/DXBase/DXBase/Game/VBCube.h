#ifndef _VB_CUBE_H_
#define _VB_CUBE_H_
#include "VBGO.h"
#include "vertex.h"
#include "gameobject.h"
#include "CMOGO.h"
//procedurally generate a VBGO Cube
//each side be divided in to _size * _size squares (2 triangles per square)

class VBCube : public VBGO
{
public:
	VBCube(int _size, ID3D11Device* GD);
	~VBCube();

	//initialise the Veretx and Index buffers for the cube
	bool getAliveState();
	void spawn();
	void tick(GameData* GD);
	Vector3 m_endPos;

protected:
	//this is to allow custom versions of this which create the basic cube and then distort it
	//see Spirla, SpikedVB and Pillow
	virtual void Transform(){};


	bool m_alive;
	int m_size;
	myVertex* m_vertices;
};

#endif