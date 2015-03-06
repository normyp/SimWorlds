#include "boid.h"
#include "gamedata.h"

Boid::Boid(string fileName, ID3D11Device* pd3dDevice, MyEffectFactory* EF, XMFLOAT3 _scale) :CMOGO(fileName, pd3dDevice, EF)
{
	m_alive = false;
	//XMStoreFloat4x4(&m_fudge, XMMatrixRotationRollPitchYaw(-XM_PI*0.5f, 0.0f, 0.0f)*XMMatrixTranslation(0.0f, -10.0f, 0.0f));
	//update my world_transform
}

Boid::~Boid()
{
	//Nothing additional here but add this just in case
}

void Boid::tick(GameData * GD)
{
	XMVECTOR vector1 = XMLoadFloat3(&m_endPos);
	XMVECTOR vector2 = XMLoadFloat3(&m_pos);
	XMVECTOR direction = XMVectorSubtract(vector1, vector2);
	float dist = XMVectorGetX(XMVector3Length(direction));
	direction = 100.0f*GD->dt*XMVector3Normalize(direction);
	XMStoreFloat3(&m_pos, vector2 + direction);
	if (dist < 10.0)
	{
		m_endPos = XMFLOAT3(-1 * (((float)rand() / (float)RAND_MAX) - 0.5f), 1 * (((float)rand() / (float)RAND_MAX) - 0.5f), -2 * ((float)rand() / (float)RAND_MAX) - 0.5f);
	}
	CMOGO::Tick(GD);
}

void Boid::spawn()
{
	m_alive = true;
	m_pos = Vector3(-1 * (((float)rand() / (float)RAND_MAX) - 0.5f), 1 * (((float)rand() / (float)RAND_MAX) - 0.5f), -2 * ((float)rand() / (float)RAND_MAX) - 0.5f);
	m_endPos = XMFLOAT3(-1 * (((float)rand() / (float)RAND_MAX) - 0.5f), 1 * (((float)rand() / (float)RAND_MAX) - 0.5f), -2 * ((float)rand() / (float)RAND_MAX) - 0.5f);
}

bool Boid::getAliveState()
{
	return m_alive;
}
