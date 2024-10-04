#include "Camera.h"

Camera::Camera()
{

}

void Camera::SetPosition(Vector3 _position)
{
	position = _position;
}

Vector3 Camera::GetPosition()
{
	return position;
}

void Camera::SetDirection(Vector3 _direction)
{
	direction = _direction;
}

Vector3 Camera::GetDirection()
{
	return direction;
}

void Camera::Init()
{
    position = Vector3(2, 0.5f, 2);
	glMatrixMode(GL_MODELVIEW);
}

void Camera::Update()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(position.x, position.y, position.z, direction.x, direction.y, direction.z, 0, 1, 0);
}