#pragma once

#include <stdint.h>
#include <string>
#include <map>
#include <assert.h>
#include <cstdlib>
#include <math.h>
#include <sstream>
#include "Array.h"
#include "Array2D.h"

#ifdef WIN32

#include "GL\glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\ext.hpp"
#include "glm\gtx\rotate_vector.hpp"

#else

#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/rotate_vector.hpp>

#endif

const int MAX_DISTRICTS = 3;
