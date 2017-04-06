#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <map>

#ifdef WIN32

#include "GL\glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#elif

#include <OpenGL\gl3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#endif