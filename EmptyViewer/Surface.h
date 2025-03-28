#pragma once
#include <glm/glm.hpp>
#include <vector>

class Ray;
class Light;
class Scene;

using namespace std;
using namespace glm;


class Surface {
public:
	Surface(vec3 Ka, vec3 Kd, vec3 Ks) : ka(Ka), kd(Kd), ks(Ks) {}

	virtual bool intersect(Ray* ray, float tMin, float* tMax, vec3* pixelColor) = 0;

	virtual vec3 getNormal(vec3 point) = 0;

	vec3 shade(Ray* ray, vec3 point, vec3 normal, vector<Light*> light, Scene* scene);

protected:
	vec3 color = vec3(1.0f, 1.0f, 1.0f);

	vec3 ka, kd, ks;
};