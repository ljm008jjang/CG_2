#pragma once
#include "Surface.h"
#include "Ray.h"
#include "Light.h"
#include "Scene.h"

using namespace glm;

vec3 Surface::shade(Ray* ray, vec3 point, vec3 normal, vector<Light*> lights, Scene* scene) {
	Ray shadRay = Ray(point, lights[0]->pos - point);

	//if not shadowed
	if (!scene->isShadowed(&shadRay, glm::length(lights[0]->pos - point))) {
		vec3 v = -normalize(ray->direction);
		vec3 l = normalize(lights[0]->pos - point);

		vec3 Ld = kd * (lights[0]->illumination * glm::max(0.0f, dot(normal, l)));
		return Ld;
	}

	return vec3(0.0f, 0.0f, 0.0f);
}