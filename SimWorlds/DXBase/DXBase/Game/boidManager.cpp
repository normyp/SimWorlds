#include "boidManager.h"
#include "boid.h"
#include "VBCube.h"

//Boid manager could be implemented into a generic manager because turret barrel is basically similar to a bullet manager

BoidManager::BoidManager(int _maxBoids, ID3D11Device* pd3dDevice)
{
	maxBoids = _maxBoids;
	m_destination = XMFLOAT3(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < maxBoids; i++)
	{
		myBoids.push_back(new VBCube(1, pd3dDevice));
	}
}

BoidManager::~BoidManager()
{

}


void BoidManager::Draw(DrawData* DD)
{
	//draw all boids
	for (list<VBCube *>::iterator it = myBoids.begin(); it != myBoids.end(); it++)
	{
		(*it)->Draw(DD);
	}
}



void BoidManager::Tick(GameData * GD)
{

	//spawn an Boid (possibly)
	//if (0.2f *((float)rand() / (float)RAND_MAX) < GD->dt)
	{
		for (list<VBCube *>::iterator it = myBoids.begin(); it != myBoids.end(); it++)
		{
			//until(*it) is dead
			if (!(*it)->getAliveState())
			{
				(*it)->spawn();
				break;
			}
		}
	}

	for (list<VBCube *>::iterator it = myBoids.begin(); it != myBoids.end(); it++)
	{
		(*it)->Tick(GD);
	}
}