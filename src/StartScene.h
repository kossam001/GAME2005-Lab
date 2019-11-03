#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include "Mine.h"
#include "Planet.h"
#include <cmath>

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	/*Label* m_pStartLabel;
	Label* m_pInstructionsLabel;*/

	Ship* m_pThermalDetonator;
	Mine* m_pWookie;
	Planet* m_pStormtrooper;

	glm::vec2 m_mousePosition;

	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;

	// Physics Variables
	float m_fScale = 10.0f;
	const float Deg2Rad = 0.0174532925f;
	const float Rad2Deg = 57.2957795130f; 
	bool m_isGravityEnabled = false;
	float m_gravity = 9.8f;
	glm::vec2 m_position = glm::vec2(0.0f, 0.0f);
	float m_velocity = 100.0f;
	float m_velocityX = 0.0f;
	float m_velocityY = 0.0f;
	glm::vec2 m_acceleration = glm::vec2(0.0f, 0.0f);
	float m_PPM = 5.0f; // pixels per meter
	float m_time = 0.01666f * m_fScale; // Time step
	float m_Atime = 0.016667f * m_fScale; // Accumulated time	

	float m_angle = 14.67f; // Kicking angle

	// Assignment 2 Variables
	float m_fSTDistance = 500.0f;
	float m_fTDWeight = 3.2f;
	float m_fWind = 0.4f;

	// Physics Functions
	void m_move();
};

#endif /* defined (__START_SCENE__) */