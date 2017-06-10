#include"../middleware/includes/glm/glm.hpp"
#include"../middleware/includes/glm/gtx/transform.hpp"
#include "../middleware/includes/glm/gtc/matrix_transform.hpp"

#include "Renderer.h"
#include "Application Manager\ApplicationManager.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	Cleanup();
}

void Renderer::Gen_Sky(std::unique_ptr<Model>& MySky)
{
	MySky = std::unique_ptr<Model>(new Model());
	//back
	MySky->VertexData.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	MySky->VertexData.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	MySky->UVData.push_back(glm::vec2(0.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(0.0f, 1.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 1.0f));

	
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, -1.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, -1.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, -1.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, -1.0));

	//first triangle.
	MySky->IndicesData.push_back(0);
	MySky->IndicesData.push_back(1);
	MySky->IndicesData.push_back(3);

	//second triangle.
	MySky->IndicesData.push_back(0);
	MySky->IndicesData.push_back(2);
	MySky->IndicesData.push_back(3);

	// front    (4,5,6,7)
	MySky->VertexData.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));

	MySky->UVData.push_back(glm::vec2(0.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(0.0f, 1.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 1.0f));

	
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, 1.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, 1.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, 1.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, 0.0, 1.0));

	//first triangle.
	MySky->IndicesData.push_back(4);
	MySky->IndicesData.push_back(5);
	MySky->IndicesData.push_back(7);

	//second triangle.
	MySky->IndicesData.push_back(4);
	MySky->IndicesData.push_back(6);
	MySky->IndicesData.push_back(7);

	// right    (8,9,10,11)
	MySky->VertexData.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	MySky->UVData.push_back(glm::vec2(0.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(0.0f, 1.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 1.0f));

	MySky->NormalsData.push_back(glm::vec3(-1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(-1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(-1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(-1.0, 0.0, 0.0));

	//first triangle.
	MySky->IndicesData.push_back(8);
	MySky->IndicesData.push_back(9);
	MySky->IndicesData.push_back(11);

	//second triangle.
	MySky->IndicesData.push_back(8);
	MySky->IndicesData.push_back(10);
	MySky->IndicesData.push_back(11);

	// left    (12,13,14,15)
	MySky->VertexData.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	MySky->VertexData.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(0.0f, 1.0f, 1.0f));

	MySky->UVData.push_back(glm::vec2(0.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(0.0f, 1.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 1.0f));

	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));

	//first triangle.
	MySky->IndicesData.push_back(12);
	MySky->IndicesData.push_back(13);
	MySky->IndicesData.push_back(15);

	//second triangle.
	MySky->IndicesData.push_back(12);
	MySky->IndicesData.push_back(14);
	MySky->IndicesData.push_back(15);

	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(1.0, 0.0, 0.0));

	// up    (16,17,18,19)
	MySky->VertexData.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	MySky->VertexData.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	MySky->VertexData.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	MySky->UVData.push_back(glm::vec2(0.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 0.0f));
	MySky->UVData.push_back(glm::vec2(0.0f, 1.0f));
	MySky->UVData.push_back(glm::vec2(1.0f, 1.0f));

	
	MySky->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));
	MySky->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));

	//first triangle.
	MySky->IndicesData.push_back(16);
	MySky->IndicesData.push_back(17);
	MySky->IndicesData.push_back(19);

	//second triangle.
	MySky->IndicesData.push_back(16);
	MySky->IndicesData.push_back(18);
	MySky->IndicesData.push_back(19);

	MySky->Initialize();
}

void Renderer::Gen_Floor(std::unique_ptr<Model>& MyFloor)
{
	//Create Square Floor
	MyFloor = std::unique_ptr<Model>(new Model());
	
	MyFloor->VertexData.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	MyFloor->VertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	MyFloor->VertexData.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	MyFloor->VertexData.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	
	MyFloor->UVData.push_back(glm::vec2(0.0f, 0.0f));
	MyFloor->UVData.push_back(glm::vec2(1.0f, 0.0f));
	MyFloor->UVData.push_back(glm::vec2(0.0f, 1.0f));
	MyFloor->UVData.push_back(glm::vec2(1.0f, 1.0f));
	
	
	MyFloor->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));
	MyFloor->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));
	MyFloor->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));
	MyFloor->NormalsData.push_back(glm::vec3(0.0, -1.0, 0.0));

	//first triangle.
	MyFloor->IndicesData.push_back(0);
	MyFloor->IndicesData.push_back(1);
	MyFloor->IndicesData.push_back(3);

	//second triangle.
	MyFloor->IndicesData.push_back(0);
	MyFloor->IndicesData.push_back(2);
	MyFloor->IndicesData.push_back(3);
	MyFloor->Initialize();
}

void Renderer::Initialize()
{
	//Initalize our camera
	myCamera = std::unique_ptr<FirstPersonCamera>(new FirstPersonCamera());
	// initialize our floor
	Gen_Floor(MyFloor);
	FloorM = glm::translate(-5.0f, -1.0f, -5.0f)*glm::scale(30.0f, 1.0f, 40.0f);
	//initialize our sky box
	Gen_Sky(MySkyBox);
	MySkyBoxMatrix = glm::translate(-3.0f, -1.0f, -3.0f)*glm::scale(25.0f, 50.0f, 35.0f);
	// check if this is the final state  (winning)
	if (!finall)
	{
		if (no_hearts == 3)
		{
         Play();
		 total_score = 0;
		}
		
	Gen_Sky(MyWall);
	Gen_Sky(MyGold);
	// hero
	shader.LoadProgram();
	MyHero = new Model3D();
	MyHero->LoadFromFile("data/models/sphere.3DS", true);
	MyHero->Initialize();
	MyHeroM = glm::translate(-1.5f, 0.0f, -3.2f);
	//enemy1
	Enemy_Model = new Model3D();
	Enemy_Model->LoadFromFile("data/models/obj/spider/spider.obj", true);
	Enemy_Model->Initialize();

	Enemy1 = std::unique_ptr<Enemy>(new Enemy(0, 6, 23, 0.1f, .05f, .05f, .05f));
	Enemy1->set_mat(translate(+3.5f, 0.0f, +20.0f));
	//enemy2
	Enemy2 = std::unique_ptr<Enemy>(new Enemy(1, 6, 8, 0.05f,.05f, .05f, .1f));
	Enemy2->set_mat(translate(+3.5f, 0.0f, +5.0f));
	//enemy3
	Enemy3 = std::unique_ptr<Enemy>(new Enemy(2, 12, 8, 0.05f, .05f, .05f, .1f));
	Enemy3->set_mat(translate(+10.0f, 0.0f, +5.0f));

	pressed = 1;
	Hero_Pos_x = 1;
	Hero_Pos_z = 0;
	hero_direction=1;
	//wall
	Text1 = std::unique_ptr<Texture>(new Texture("crate.jpg", 0));
    //ground
	if (no_hearts==3)
	Text2 = std::unique_ptr<Texture>(new Texture("g3.jpg", 1));
	else if (no_hearts==2)
		Text2 = std::unique_ptr<Texture>(new Texture("g2.jpg", 1));
	else if (no_hearts==1)
		Text2 = std::unique_ptr<Texture>(new Texture("g1.jpg", 1));
	else // if the hearts == 0 initialize the text for ground and the sky then skip
	{
		//ground
		Text1 = std::unique_ptr<Texture>(new Texture("over.jpg", 0));
		//skybox
		Text2 = std::unique_ptr<Texture>(new Texture("2.jpg", 1));
		goto label1;
	}
	//skybox
	Text3 = std::unique_ptr<Texture>(new Texture("2.jpg", 2));
	// gold
	Text4 = std::unique_ptr<Texture>(new Texture("sona.jpg”, 3));
	//hero
	Text5 = std::unique_ptr<Texture>(new Texture("t2.jpg", 4));
	}
	else
	{
		//ground
		Text1 = std::unique_ptr<Texture>(new Texture("Finall.jpg", 0));
		//skybox
		Text2 = std::unique_ptr<Texture>(new Texture("2.jpg", 1));
	}
   label1:
	//////////////////////////////////////////////////////////////////////////
	// Create and compile our GLSL program from the shaders
	programID = LoadShaders("SimpleTransformWithColor.vertexshader", "TextureLighting.fragmentshader");

	// Use our shader
	glUseProgram(programID);

	LightPositionID = glGetUniformLocation(programID, "LightPosition_worldspace");
	AmbientLightID = glGetUniformLocation(programID, "ambientLight");
	DissfuseLightID = glGetUniformLocation(programID, "diffuseLight");
	SpecularLightID = glGetUniformLocation(programID, "specularLight");
    EyePositionID = glGetUniformLocation(programID, "EyePosition_worldspace");

	//Step 2 => Initilization
	lightPosition = glm::vec3(10.0f, 10.0f, 10.0f);
	ambientLight = glm::vec3(1, 1, 1);
	Diffuselight = glm::vec3(0, 1, 0);
	specularlight = glm::vec3(1, 1, 1);
	//Step 3 => send values to shader
	glUseProgram(programID);
	glUniform3fv(LightPositionID, 1, &lightPosition[0]);
	glUniform3fv(AmbientLightID, 1, &ambientLight[0]);
	glUniform3fv(DissfuseLightID, 1, &Diffuselight[0]);
	glUniform3fv(SpecularLightID, 1, &specularlight[0]);

	//////////////////////////////////////////////////////////////////////////

	//glUniform3fv(EyePositionID, 1, &myCamera->GetEyePosition()[0]);

	//projection matrix.
	myCamera->SetPerspectiveProjection(50.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	// View matrix : 
	myCamera->Reset
		(0.0, 40.0, 15.0,
		8, 1, 100,
		0, 5, 0
		);
	

}

void Renderer::Draw()
{
	// Use our shader
	glUseProgram(programID);

	MatrixID = glGetUniformLocation(programID, "MVP");
	ModelMatrixID = glGetUniformLocation(programID, "ModelMatrix");

	glm::mat4 VP = myCamera->GetProjectionMatrix() * myCamera->GetViewMatrix();
	if (!finall)
	{
		if (no_hearts == 0)
		{
			//the floor
			Text1->Bind();
			glm::mat4 floorMVP = VP * FloorM;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &floorMVP[0][0]);
			MyFloor->Draw();
			// the sky
			Text2->Bind();
			glm::mat4 sqMVP = VP *MySkyBoxMatrix;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &sqMVP[0][0]);
			MySkyBox->Draw();
		}
		else
		{
          //the floor
		Text2->Bind();
		glm::mat4 floorMVP = VP * FloorM;
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &floorMVP[0][0]);
		MyFloor->Draw();

		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 40; j++)
			{
				if (Grid[i][j] == 'W')
				{
					//wall
					WallM = glm::translate(i + -3.0f, 0.0f, j - 3.0f) *glm::scale(1.0f, 1.0f, 1.0f);
					Text1->Bind();
					glm::mat4 cubeMVP = VP * WallM;
					glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubeMVP[0][0]);
					MyWall->Draw();

				}
				else if (Grid[i][j] == 'G')
				{
					//gold
					GoldM = glm::translate(i - 2.5f, 0.0f, j - 2.5f) *glm::scale(0.55f, 0.55f, 0.55f)*glm::rotate(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
					Text4->Bind();
					glm::mat4 cubeMVP = VP * GoldM;
					glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubeMVP[0][0]);
					MyGold->Draw();
				}
			}
		}
		//skybox
		Text3->Bind();
		glm::mat4 sqMVP = VP *MySkyBoxMatrix;
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &sqMVP[0][0]);
		MySkyBox->Draw();
		// shader for hero and enemys
		Text5->Bind();
        shader.UseProgram();
		glm::mat4 VP = myCamera->GetProjectionMatrix()*myCamera->GetViewMatrix();
		shader.BindVPMatrix(&VP[0][0]);

		//hero
		MyHero->Render(&shader, MyHeroM*translate(0.7f, 0.0f, 0.0f)*scale(0.15f, 0.15f, 0.15f));
        //enemy1
		if (Enemy1->direction == 3)
			Enemy_Model->Render(&shader, Enemy1->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f)*rotate(-90.0f, vec3(0.0f, 1.0f, 0.0f)));
		else if (Enemy1->direction == 0)
			Enemy_Model->Render(&shader, Enemy1->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f)*rotate(-180.0f, vec3(0.0f, 1.0f, 0.0f)));
		else if (Enemy1->direction == 1)
			Enemy_Model->Render(&shader, Enemy1->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f)*rotate(90.0f, vec3(0.0f, 1.0f, 0.0f)));
		else
			Enemy_Model->Render(&shader, Enemy1->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f));

		//enemy2
		if (Enemy2->direction == 3)
			Enemy_Model->Render(&shader, Enemy2->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f)*rotate(-90.0f, vec3(0.0f, 1.0f, 0.0f)));
		else if (Enemy2->direction == 0)
			Enemy_Model->Render(&shader, Enemy2->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f)*rotate(-180.0f, vec3(0.0f, 1.0f, 0.0f)));
		else if (Enemy2->direction == 1)
			Enemy_Model->Render(&shader, Enemy2->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f)*rotate(90.0f, vec3(0.0f, 1.0f, 0.0f)));
		else
			Enemy_Model->Render(&shader, Enemy2->ModelMatrix *translate(.5f, 0.0f, 0.5f)*scale(0.01f, 0.01f, 0.01f));

		//enemy3
		if (Enemy3->direction==3)
		Enemy_Model->Render(&shader, Enemy3->ModelMatrix *translate(.5f, 0.0f, 0.6f)*scale(0.01f, 0.01f, 0.01f)*rotate(-90.0f, vec3(0.0f, 1.0f, 0.0f)));
		else if (Enemy3->direction == 0)
			Enemy_Model->Render(&shader, Enemy3->ModelMatrix *translate(.5f, 0.0f, 0.6f)*scale(0.01f, 0.01f, 0.01f)*rotate(-180.0f, vec3(0.0f, 1.0f, 0.0f)));
		else if (Enemy3->direction == 1)
			Enemy_Model->Render(&shader, Enemy3->ModelMatrix *translate(.5f, 0.0f, 0.6f)*scale(0.01f, 0.01f, 0.01f)*rotate(90.0f, vec3(0.0f, 1.0f, 0.0f)));
		else 
			Enemy_Model->Render(&shader, Enemy3->ModelMatrix *translate(.5f, 0.0f, 0.6f)*scale(0.01f, 0.01f, 0.01f));

		glUseProgram(programID);

		}
		
	}
	else
	{
		//the floor
		Text1->Bind();
		glm::mat4 floorMVP = VP * FloorM;
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &floorMVP[0][0]);
		MyFloor->Draw();
		// the sky
		Text2->Bind();
		glm::mat4 sqMVP = VP *MySkyBoxMatrix;
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &sqMVP[0][0]);
		MySkyBox->Draw();

	}
	

}

void Renderer::Cleanup()
{
	glDeleteProgram(programID);
}

void Renderer::Update(double deltaTime)
{
	move_enemy(Enemy1);
	move_enemy(Enemy2);
	move_enemy(Enemy3);
	detect_collisions();
	
	if (cam == 1)
	{
    if (hero_direction == 0)
	{
        myCamera->Reset(Hero_Pos_x + 0.5, 2, Hero_Pos_z + 0.5,
		Hero_Pos_x+4, 0.5, Hero_Pos_z,
		0, 1, 0);
	}
	else if (hero_direction == 1)
	{
		myCamera->Reset(Hero_Pos_x + 0.5, 2, Hero_Pos_z + 0.5,
			Hero_Pos_x , 0.5, Hero_Pos_z + 4,
			0, 1, 0);
	}
	else if (hero_direction == 2)
	{
		myCamera->Reset(Hero_Pos_x + 0.5, 2, Hero_Pos_z + 0.5,
			Hero_Pos_x-4, 0.5, Hero_Pos_z ,
			0, 1, 0);
	}
	else if (hero_direction == 3)
	{
		myCamera->Reset(Hero_Pos_x + 0.5, 2, Hero_Pos_z + 0.5,
			Hero_Pos_x-4, 0.5, Hero_Pos_z,
			0, 1, 0);
	}
	}
	else
	{
		myCamera->Reset
			(0.0, 35.0, 15.0,
			9, 1, 15,
			0, 10, 0
			);
	}
	
}

void Renderer::Move_Hero(char direction, char sign)
{
	// take only one pressed key
	if (pressed == 0)
	{
		pressed = !pressed;
       return;
	}	
	pressed = !pressed;
	glm::mat4 walkMat;
	if (direction == 'x'&&sign == '+')
	{
		if (Hero_Pos_x < 24 && Grid[Hero_Pos_x + 1][Hero_Pos_z] != 'W'&&Grid[Hero_Pos_x + 2][Hero_Pos_z] != 'W')
		{
			walkMat = glm::translate(1.0f, 0.0f, 0.0f);
			Hero_Pos_x += 1;
			if (Grid[Hero_Pos_x][Hero_Pos_z] == 'G')
				total_score++;
			Grid[Hero_Pos_x ][Hero_Pos_z] = 'F';	
		}
		hero_direction = 0;
	}
	if (direction == 'x'&&sign == '-')
	{
		if (Hero_Pos_x > 0 && Grid[Hero_Pos_x-1][Hero_Pos_z] != 'W')
		{
			walkMat = glm::translate(-1.0f, 0.0f, 0.0f);
	               Hero_Pos_x -= 1;
				   if (Grid[Hero_Pos_x][Hero_Pos_z] == 'G')
					   total_score++;
				   Grid[Hero_Pos_x][Hero_Pos_z] = 'F';
		
		}
		hero_direction = 2;
	}
	if (direction == 'z'&&sign == '+')
	{
		if (Hero_Pos_z < 34 && Grid[Hero_Pos_x+1][Hero_Pos_z + 1] != 'W' && Grid[Hero_Pos_x][Hero_Pos_z + 1] != 'W')
		{
			walkMat = glm::translate(0.0f, 0.0f, 1.0f);
			Hero_Pos_z += 1;
			if (Grid[Hero_Pos_x][Hero_Pos_z] == 'G')
				total_score++;
			Grid[Hero_Pos_x][Hero_Pos_z] = 'F';
		}
		hero_direction = 1;
	}
	if (direction == 'z'&&sign == '-')
	{
		if (Hero_Pos_z >0 && Grid[Hero_Pos_x + 1][Hero_Pos_z - 1] != 'W' &&  Grid[Hero_Pos_x][Hero_Pos_z - 1] != 'W')
		{
			walkMat = glm::translate(0.0f, 0.0f, -1.0f);
			Hero_Pos_z -= 1;
			if (Grid[Hero_Pos_x][Hero_Pos_z] == 'G')
				total_score++;
			Grid[Hero_Pos_x][Hero_Pos_z] = 'F';
		}
		hero_direction = 3;
	}
	MyHeroM *= walkMat;
	if (Hero_Pos_x == 22 && Hero_Pos_z == 34 &&total_score==total_golds)
	{
		finall = 1;
		Initialize();
	}
}

void Renderer::HandleKeyboardInput(int key, int action)
{
	switch (key)
	{
	case GLFW_KEY_UP :
		Move_Hero('x', '+');
		break;
	case GLFW_KEY_DOWN:
		Move_Hero('x', '-');
		break;
	case GLFW_KEY_LEFT:
		Move_Hero('z', '-');
		break;
	case GLFW_KEY_RIGHT:
		Move_Hero('z', '+');
		break;
	case GLFW_KEY_I:
		ambientLight += 0.1;
		glUniform3fv(AmbientLightID, 1, &ambientLight[0]);
		break;
	case GLFW_KEY_D:
		ambientLight -= 0.1;
		glUniform3fv(AmbientLightID, 1, &ambientLight[0]);
		break;
	case GLFW_KEY_C:
		cam = 1;
		break;
	case GLFW_KEY_V:
		cam = 0;
		break;

	default:
		break;
	}
}

void Renderer::HandleMouse(double deltaX, double deltaY)
{
	myCamera->Yaw(deltaX);
	myCamera->Pitch(deltaY);
	myCamera->UpdateViewMatrix();
}

void Renderer::move_enemy(std::unique_ptr<Enemy> &Enemys)
{
	    
	if (Enemys->count == 100)
		{
		    Enemys->count = 0;
			Enemys->direction = rand() % 4;
		}
	//up
	else if (Enemys->direction == 0 && Enemys->pos_x < 24 && (Grid[Enemys->pos_x + 2][Enemys->pos_z] != 'W') && (Grid[Enemys->pos_x + 1][Enemys->pos_z] != 'W'))
		{
			Enemys->ModelMatrix *= translate(vec3(Enemys->speed_up, 0.0f, 0.0f));
			Enemys->count++;
			if (Enemys->count % (int)(1 / Enemys->speed_up) == 0)
			{
				Enemys->pos_x++;
			}
		}
		//right
	else if (Enemys->direction == 1 && Enemys->pos_z < 34 && Grid[Enemys->pos_x][Enemys->pos_z + 1] != 'W')
		{
		      Enemys->ModelMatrix *= translate(vec3(0.0f, 0.0f, Enemys->speed_right));
			  Enemys->count++;
			if (Enemys->count % (int)(1 / Enemys->speed_right) == 0)
			{
				Enemys->pos_z++;
			}
		}
		//down
	else if (Enemys->direction == 2 && Enemys->pos_x > 0 && Grid[Enemys->pos_x - 1][Enemys->pos_z] != 'W')
		{
			Enemys->ModelMatrix *=translate(vec3(-(Enemys->speed_left), 0.0f, 0.0f));
			Enemys->count++;
			if (Enemys->count % (int)(1 / Enemys->speed_left) == 0)
			{
				Enemys->pos_x--;
			}
		}
		//left
	else if (Enemys->direction == 3 && Enemys->pos_z > 2 && Grid[Enemys->pos_x][Enemys->pos_z - 1] != 'W' && Grid[Enemys->pos_x][Enemys->pos_z - 2] != 'W'&& Grid[Enemys->pos_x+1][Enemys->pos_z - 2] != 'W' && Grid[Enemys->pos_x+1][Enemys->pos_z - 1] != 'W')
		{
		Enemys->ModelMatrix *= translate(vec3(0.0f, 0.0f, -(Enemys->speed_left)));
		Enemys->count++;
		if (Enemys->count % (int)(1 / Enemys->speed_left) == 0)
			{
				Enemys->pos_z--;
			}
		}
		else
		{
			Enemys->count = 0;
			Enemys->direction = rand() % 4;
		}
}

void Renderer::detect_collisions()
{

	int x1 = (Enemy1->direction == 0 ? 1 : (Enemy1->direction == 2 ? -1 : 0));
	int z1 = (Enemy1->direction == 1 ? 1 : (Enemy1->direction == 3 ? -1 : 0));
	int x2 = (Enemy2->direction == 0 ? 1 : (Enemy2->direction == 2 ? -1 : 0));
	int z2 = (Enemy2->direction == 1 ? 1 : (Enemy2->direction == 3 ? -1 : 0));
	int x3 = (Enemy3->direction == 0 ? 1 : (Enemy3->direction == 2 ? -1 : 0));
	int z3 = (Enemy3->direction == 1 ? 1 : (Enemy3->direction == 3 ? -1 : 0));
	if (
		(Hero_Pos_x == Enemy1->pos_x + x1 && Hero_Pos_z == Enemy1->pos_z + z1) ||
		(Hero_Pos_x == Enemy2->pos_x + x2 && Hero_Pos_z == Enemy2->pos_z + z2) ||
		(Hero_Pos_x == Enemy3->pos_x + x3 && Hero_Pos_z == Enemy3->pos_z + z3) ||
		(Hero_Pos_x == Enemy2->pos_x  && Hero_Pos_z == Enemy2->pos_z) ||
		(Hero_Pos_x == Enemy1->pos_x && Hero_Pos_z == Enemy1->pos_z) ||
		(Hero_Pos_x == Enemy3->pos_x  && Hero_Pos_z == Enemy3->pos_z)
		)
	{
		no_hearts--;
		Initialize();
	}
}

void Renderer::Play()
{
	// initialize the grid with 'f' denotes to free cells
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++)
		{
			Grid[i][j] = 'F';
		}
	}
	//right most wall
	for (int i = 0; i < 22; i++)
		Grid[i][34] = 'W';
	
	//left most wall
	for (int i = 3; i < 40; i++)
		Grid[i][0] = 'W';
	
	//Up And Down Wall.
	for (int j = 0; j < 40; j++) {
		Grid[0][j] = 'W';
		Grid[24][j] = 'W';
	}
	

	//in grid walls
	for (int i = 25; i < 35; i++)
		Grid[21][i] = 'W';

	for (int i = 0; i < 15; i++)
		Grid[5][i] = 'W';

	for (int i = 6; i < 10; i++)
		Grid[i][14] = 'W';

	for (int i = 4; i < 10; i++)
		Grid[11][i] = 'W';
	
	for (int i = 20; i < 30; i++)
		Grid[15][i] = 'W';

	for (int i = 0; i < 19; i++)
		Grid[0][i] = 'W';

	for (int i = 0; i < 14; i++)
		Grid[15][i] = 'W';


	for (int i = 20; i < 30; i++)
		Grid[5][i] = 'W';

	for (int i = 5; i < 15; i++)
		Grid[i][20] = 'W';
	//golds
	total_golds = 0;
		 for (int i = 1; i < 22; i += 2) {
			 for (int j = 3; j < 35; j += 5) {
				 if (Grid[i][j] != 'W')
				 {
					 Grid[i][j] = 'G';
					 total_golds++;
				 }
			 } 
		 }

}