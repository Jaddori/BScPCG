#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>

#ifdef WIN32

#include "GL\glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#else

#include <OpenGL\gl3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#endif