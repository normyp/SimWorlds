#ifndef _Boid_H_
#define _Boid_H_
#include "gameobject.h"
#include "CMOGO.h"

struct GameData;

class Boid : public CMOGO
{
public:
	Boid(string fileName, ID3D11Device* pd3dDevice, MyEffectFactory* EF, XMFLOAT3 _scale);
	~Boid();
	void spawn();
	bool getAliveState();
	void tick(GameData* GD);
	XMFLOAT3 m_endPos;

protected:

	bool m_alive;

};

#endif