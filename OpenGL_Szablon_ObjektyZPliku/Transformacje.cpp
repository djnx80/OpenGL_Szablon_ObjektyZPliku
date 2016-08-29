#include "stdafx.h"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/glm.hpp>

#include "Transformacje.h"
using namespace glm;

void Transformacje::funkcja_Po_Okregu(float t_promien, float t_angle, float &dx, float &dy) {
	dx = t_promien * cos(t_angle * 3.14 / 180.0);
	dy = t_promien * sin(t_angle * 3.14 / 180.0);
}

void Transformacje::funkcja_Jakas_tam(float t_promien, float t_angle, float &dx, float &dy) {
	dx = t_promien * cos(t_angle * 3.14 / 180.0) * sin(t_angle/2 * 3.14 / 160.0);
	dy = t_promien * sin(t_angle * 3.14 / 280.0) + cos(t_angle * 3.14 / 180.0);
}

mat4 Transformacje::przesun(float dx, float dy, float dz)
{
	mat4 temp;
	temp = translate(mat4(1.0), vec3(dx, dy, dz));

	return temp;
}

mat4 Transformacje::obroc(mat4 przesuniecie, float angle, bool oX, bool oY, bool oZ)	{

return rotate(przesuniecie, angle, vec3(oX, oY, oZ));
}