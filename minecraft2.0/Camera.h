#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



const float PITCH{};
const float YAW			= -90;
const float SENSITIVITY = 0.1f;
const float ZOOM		= 45.0f;

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	RIGHT,
	LEFT
};


class Camera
{
public:

	glm::vec3 cameraFront;
	glm::vec3 cameraPos;
	glm::vec3 cameraUp;
	glm::vec3 cameraDir;
	glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, glm::vec3(0.0f, 1.0f, 0.0f)));
	glm::vec3 up;

	float pitch;
	float yaw;
	float sensitivity;
	float zoom;

	Camera(glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3 Gup = glm::vec3(0.0f, 1.0f, 0.0f)) : cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)), cameraDir(glm::vec3(0.0f, 0.0f, -1.0f)),  yaw(YAW), pitch(PITCH), sensitivity(SENSITIVITY), zoom(ZOOM)
	{
		cameraPos = cameraPosition;
		up = Gup;
		updateCamera();
	}

	Camera(float xpos, float ypos, float zpos, float upX, float upY, float upZ) : cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)), cameraDir(glm::vec3(0.0f, 0.0f, -1.0f)), yaw(YAW), pitch(PITCH), sensitivity(SENSITIVITY), zoom(ZOOM)
	{
		cameraPos = glm::vec3(xpos, ypos, zpos);
		up = glm::vec3(upX, upY, upZ);
		updateCamera();
	}

	glm::mat4 getViewMatrix()
	{
		return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void cameraMovement(Camera_Movement dir, float deltaTime)
	{
		float cameraSpeed = deltaTime * 2.5f;
		if (dir == FORWARD)
			cameraPos += cameraSpeed * cameraFront;
		if (dir == BACKWARD)
			cameraPos -= cameraSpeed * cameraFront;
		if (dir == RIGHT)
			cameraPos += cameraSpeed * cameraRight;
		if (dir == LEFT)
			cameraPos -= cameraSpeed * cameraRight;
	}

	void mouseMovement(float xoffset, float yoffset)
	{
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		updateCamera();
	}

private:
	void updateCamera()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(front);
		cameraDir = glm::normalize(glm::vec3(front.x, 0.0f, front.z));
		cameraRight = glm::normalize(glm::cross(cameraDir, glm::vec3(0.0f, 1.0f, 0.0f)));
		cameraUp = glm::normalize(glm::cross(cameraRight, cameraDir));
	}
};