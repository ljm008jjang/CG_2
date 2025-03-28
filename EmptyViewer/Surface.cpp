#pragma once
#include "Surface.h"
#include "Ray.h"
#include "Light.h"
#include "Scene.h"

using namespace glm;

vec3 Surface::shade(Ray* ray, vec3 point, vec3 normal, vector<Light*> lights, Scene* scene) {
	//no ambient light?
	vec3 result = vec3(0.0f, 0.0f, 0.0f);

	// Ambient Light
	vec3 La = ka * (lights[0]->illumination);
	result += La;

	for (Light* light : lights) {
		Ray shadRay = Ray(point, light->pos - point);

		//if not shadowed
		if (!scene->isShadowed(&shadRay, glm::length(light->pos - point))) {

			vec3 v = -normalize(ray->direction);
			vec3 l = normalize(light->pos - point);

			vec3 Ld = kd * (light->illumination) * glm::max(0.0f, dot(normal, l));

			vec3 h = normalize(v + l);

			float tmp = glm::max(0.0f, dot(normal, h));
			
			vec3 Ls = ks * (light->illumination) * pow(tmp, specularPower);

			vec3 L = Ld + Ls;
			result += L;
		}
	}

	return result;
}