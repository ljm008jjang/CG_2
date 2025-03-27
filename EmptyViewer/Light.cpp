#pragma once
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

class Light {
public:
	Light(vec3 position) : pos(position) {};

	vec3 pos;

	int illumination;
};