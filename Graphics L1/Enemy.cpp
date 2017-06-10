#include "Enemy.h"


Enemy::Enemy(int direction,int pos_x,int pos_z,float speed_up,float speed_down,float speed_left,float speed_right)
{
	this->direction = direction;
	this->pos_x = pos_x;
	this->pos_z = pos_z;
	this->speed_up = speed_up;
	this->speed_down = speed_down;
	this->speed_right = speed_right;
	this->speed_left = speed_left;
	count = 0;
}
void Enemy::set_mat(glm::mat4 mat)
{
	ModelMatrix = mat;
}
Enemy::~Enemy()
{

}
