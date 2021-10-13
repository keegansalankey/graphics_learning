// Includes from standard library
#include <iostream>
#include <stdlib.h>

// Include external libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Include user made libraries
#include <shader.h>
#include <camera.h>

void processInput( GLFWwindow* window );
void framebuffer_size_callback( GLFWwindow* window, int width, int height );
void mouse_callback( GLFWwindow* window, double xpos, double ypos );
void scroll_callback( GLFWwindow* window, double xoffset, double yoffset );

// Defining screen dimenstions as constant
const float SCR_WIDTH = 800.0f;
const float SCR_HEIGHT = 600.0f;

// Global variables relating to camera position/movement
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
bool firstMouse = true;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

// Timing variables to adjust for different framerates
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// basic light position
glm::vec3 lightPos(0.0f, 1.0f, 2.0f);

int main( void ) 
{
  // Initialising GLFW 
  glewExperimental = true;
  if ( !glfwInit() )
  {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  // setting GLFW profile
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Creating window
  GLFWwindow* window = glfwCreateWindow( SCR_WIDTH, SCR_HEIGHT, "Lighting Example", NULL, NULL );
  if ( window == NULL) 
  {
    std::cerr << "Failed to open GLFW window." << std::endl;
    glfwTerminate();
    return -1;
  }



  // Ensure window is current and apply callback function
  glfwMakeContextCurrent( window );
  glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );
  glfwSetCursorPosCallback( window, mouse_callback );
  glfwSetScrollCallback( window, scroll_callback );
  // lock cursor into screen
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // Initialize glew ** find out why this must go here **
  if( glewInit() != GLEW_OK )
  {
    std::cerr << "Failed to intialize GLEW" << std::endl;
    glfwTerminate();
    return -1;
  }

  // configure opengl states
  glEnable( GL_DEPTH_TEST );

  // Initialize shader
  Shader lightingShader = Shader( "lighting/shaders/colors.vs", "lighting/shaders/colors.fs" );
  Shader lightCubeShader = Shader( "lighting/shaders/lightCubeShader.vs", "lighting/shaders/lightCubeShader.fs");

  float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
    0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
    0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
    0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
    0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
    0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
    0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
  };

  // Create buffer objects
  unsigned int cubeVAO, VBO;
  glGenVertexArrays( 1, &cubeVAO ); // ********** NEVER FORGET THE LESSON LEARNED HERE *****************
  glGenBuffers( 1, &VBO );
  // Bind vbo buffer and send vertex information
  glBindBuffer( GL_ARRAY_BUFFER, VBO );
  glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );

  // Bind VAO first
  glBindVertexArray( cubeVAO );
  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // normal attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);


  // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
  unsigned int lightCubeVAO;
  glGenVertexArrays(1, &lightCubeVAO);
  glBindVertexArray(lightCubeVAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  while ( !glfwWindowShouldClose( window ) )
  {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    lightPos = glm::vec3(2*cos(glfwGetTime()), 1.0f, 2*sin(glfwGetTime()));
    
    // Check for input on keys
    processInput( window );

    // Clear buffers before rendering
    glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    lightingShader.use();
    lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);
    lightingShader.setVec3("lightPos", lightPos);

    glm::mat4 projection = glm::perspective(glm::radians(camera.zoom), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 100.0f);
    lightingShader.setMat4("projection", projection);
    glm::mat4 view = camera.getViewMatrix();
    lightingShader.setMat4("view", view);
    glm::mat4 model(1.0f);
    lightingShader.setMat4("model", model);

    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    lightCubeShader.use();
    lightCubeShader.setMat4("projection", projection);
    lightCubeShader.setMat4("view", view);
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
    lightCubeShader.setMat4("model", model);

    glBindVertexArray(lightCubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);


    // Swap buffers and poll events after rendering
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  return 0;
}

void processInput( GLFWwindow* window )
{
  // Close context and exit program
  if ( glfwGetKey (window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
    glfwSetWindowShouldClose( window, true );

  // Camera functionalities
  if ( glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS )
    camera.processKeyboard( FORWARD, deltaTime );

  if ( glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS )
    camera.processKeyboard( BACKWARD, deltaTime );

  if ( glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS )
    camera.processKeyboard( LEFT, deltaTime );

  if ( glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS )
    camera.processKeyboard( RIGHT, deltaTime );
}

void framebuffer_size_callback( GLFWwindow* window, int width, int height )
{
  // Adjust viewport to be size of window
  glViewport( 0, 0, width, height );
}


void mouse_callback( GLFWwindow* window, double xpos, double ypos ) 
{
  if ( firstMouse ) // see if mouse has interacted with program previously
  {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  // calculate change in position of cursor
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top (REFACTOR for inverted camera)
  lastX = xpos;
  lastY = ypos;

  camera.processMouseMovement( xoffset, yoffset );
}

void scroll_callback( GLFWwindow* window, double xoffset, double yoffset ) 
{
  camera.processMouseScroll( yoffset );
}
