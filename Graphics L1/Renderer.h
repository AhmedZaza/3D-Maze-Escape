#ifndef Renderer_h__
#define Renderer_h__

#include "../middleware/includes/gl/glew.h"
#include "../middleware/includes/gl/glfw3.h"

#include "Shaders/shader.hpp"
#include "Model.h"
#include <memory>
#include "FirstPersonCamera.h"
#include "texture.h"
#include "Enemy.h"
#include "ShaderProgram.h"
class Renderer
{
	char Grid[40][40];
	GLuint programID;
	GLuint MatrixID;
	GLuint VPID;
	GLuint ModelMatrixID;
	ShaderProgram shader;
	std::unique_ptr<FirstPersonCamera> myCamera;
	//SkyBox
	std::unique_ptr<Model> MySkyBox;
	glm::mat4 MySkyBoxMatrix;
	// Floor
	std::unique_ptr<Model> MyFloor;
	glm::mat4 FloorM;
	// Wall Cube
	std::unique_ptr<Model> MyWall;
	glm::mat4 WallM;
	// Gold Cube
	std::unique_ptr<Model> MyGold;
	glm::mat4 GoldM;
	// My hero
	Model3D* MyHero;
	glm::mat4 MyHeroM;
	// enemys
	Model3D *Enemy_Model;
	std::unique_ptr<Enemy> Enemy1;
	std::unique_ptr<Enemy> Enemy2;
	std::unique_ptr<Enemy> Enemy3;
	//Textures
	std::unique_ptr<Texture> Text1;
	std::unique_ptr<Texture> Text2;
	std::unique_ptr<Texture> Text3;
	std::unique_ptr<Texture> Text4;
	std::unique_ptr<Texture> Text5;
	//Lighting
	GLuint AmbientLightID;

	GLuint DissfuseLightID;
	GLuint SpecularLightID;

	GLuint LightPositionID;
	GLuint EyePositionID;
	GLuint AttID;

	GLuint MaterialDiffuseColorID;
	GLuint MaterialAmbientColorID;
	GLuint MaterialSpecularColorID;

	glm::vec3 ambientLight;
	glm::vec3 specularlight;
	glm::vec3 Diffuselight;
	glm::vec3 lightPosition;
	


public:
	Renderer();
	~Renderer();

	void Initialize();
	void Draw();
	void HandleKeyboardInput(int key, int action);
	void HandleMouse(double deltaX, double deltaY);
	void Update(double deltaTime);
	void Cleanup();
private:
	void Gen_Sky(std::unique_ptr<Model> &MySky);
	void Gen_Floor(std::unique_ptr<Model> &MyFloor);
	void Move_Hero(char direction, char sign);
	void Play();
	void move_enemy(std::unique_ptr<Enemy> &Enemys);
	void detect_collisions();
	int Hero_Pos_x;
	int Hero_Pos_z;
	int hero_direction;
	int total_score, no_hearts = 3, total_golds=0;
	bool pressed;
	bool finall=0,cam=0;

};
#endif 
