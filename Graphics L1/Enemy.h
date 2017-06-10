#pragma once
#include "Model3D.h"
class Enemy
{
public:
	Enemy(int direction, int pos_x, int pos_z, float speed_up, float speed_down, float speed_left, float speed_right);
	~Enemy();
	void set_mat(glm::mat4 in);
	glm::mat4 ModelMatrix;
	int count, direction, pos_x, pos_z;
	float speed_up,speed_down,speed_left,speed_right;
};

