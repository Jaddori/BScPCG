#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <assert.h>
#include <cstdlib>

#ifdef WIN32

#include "GL\glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#else

#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#endif