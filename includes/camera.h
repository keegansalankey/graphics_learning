#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement {
  FORWARD, 
  BACKWARD,
  LEFT,
  RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 250.0f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera 
{
  public:
    // Camera Attributes
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right_vector;
    glm::vec3 world_up;

    // euler angles
    float yaw;
    float pitch;

    // camera options
    float movement_speed;
    float mouse_sensitivity;
    float zoom;

    // Default constructor with optional parameters for vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : 
      front(glm::vec3(0.0f, 0.0f, -1.0f)), movement_speed(SPEED), mouse_sensitivity(SENSITIVITY), zoom(ZOOM) 
    {
      this->position = position;
      world_up = up;
      this->yaw = yaw;
      this->pitch = pitch;
      updateCameraVectors();
    }

    glm::mat4 getViewMatrix();

    void processKeyboard(Camera_Movement direction, float delta_time);

    void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    void processMouseScroll(float yoffset);

  private:

    void updateCameraVectors();

};


#endif
