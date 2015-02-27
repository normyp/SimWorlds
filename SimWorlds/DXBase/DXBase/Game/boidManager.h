#ifndef _ BOID_MANAGER_H_
#define _ BOID_MANAGER_H_
#include "gameobject.h"
#include "MyEffectsFactory.h"
#include <list>
using namespace std;

struct GameData;
class VBCube;

class BoidManager : public GameObject
{
public:
	BoidManager(int _maxEnemies, ID3D11Device* pd3dDevice);
	~BoidManager();

	void Draw(DrawData* DD);
	void Tick(GameData* GD);

	XMFLOAT3 m_destination;
	int maxBoids;
	XMFLOAT3 newPos;
	bool m_alive;
protected:
	list<VBCube *> myBoids;

};

#endif