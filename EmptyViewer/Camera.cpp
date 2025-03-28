#pragma once
#include "Camera.h"
#include "Ray.h"

using namespace glm;
using namespace std;


//Create Ray
Ray* Camera::getRay(int ix, int iy) {
    //coords of a pixel
    float u = l + (r - l) * (ix + 0.5f) / 512;
    float v = b + (t - b) * (iy + 0.5f) / 512;

    vec3 p = e;
    vec3 s = p + u * this->u + v * this->v - d * w;

    Ray* ray = new Ray(p, s - p);

    return ray;
}