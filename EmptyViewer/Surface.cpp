#pragma once
#include "Ray.cpp"
#include "Light.cpp"


class Surface {
public:
	Surface(vec3 Ka, vec3 Kd, vec3 Ks) : ka(Ka), kd(Kd), ks(Ks){}

	virtual bool intersect(Ray* ray, float tMin, float* tMax, vec3* pixelColor) = 0;

	virtual vec3 getNormal(vec3 point) = 0;

	vec3 shade(Ray* ray, vec3 point, vec3 normal, Light* light) {
		vec3 v = -normalize(ray->direction);
		vec3 l = normalize(light->pos - point);

		vec3 Ld = kd * (light->illumination * glm::max(0.0f, dot(normal, l)));
		return Ld;
	}

protected:
	vec3 color = vec3(1.0f, 1.0f, 1.0f);

	vec3 ka, kd, ks;
};