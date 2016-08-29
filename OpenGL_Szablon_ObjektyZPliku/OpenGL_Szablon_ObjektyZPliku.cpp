#include "stdafx.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <iostream> 
#include <vector>
#include "Ekran.h"
#include "Transformacje.h"

using namespace std;
using namespace glm;

// zmienne globalne
GLFWwindow *mojeOkno = NULL;
GLuint position_vbo = 0;
GLuint wsp_tekstury_vbo = 0;
GLuint vao = 0;
GLuint vao1 = 0;

vector<GLfloat> vertices_count;
vector<GLfloat> starting_vertex;
vector<GLfloat> vertices_count1;
vector<GLfloat> starting_vertex1; 
GLuint tekstury[5];

int main(void) {

	Ekran ekran;
	Transformacje trans;
	ekran.Inicjacja(mojeOkno);
	ekran.Wyswietl_info();
	vao = ekran.WczytajObjekt("tekstury/Rabbit.obj", vertices_count, starting_vertex);
	GLuint shaders = ekran.WczytajShadery("vertex_shader.glsl", "fragment_shader.glsl");
	GLint transformacja = ekran.Znajdz_Zmienna(shaders, "macierz_przesuniecia");

	vao1 = ekran.WczytajObjekt("tekstury/Hulk.obj", vertices_count1, starting_vertex1);
	GLuint shaders1 = ekran.WczytajShadery("vertex_shader1.glsl", "fragment_shader1.glsl");
	GLint transformacja1 = ekran.Znajdz_Zmienna(shaders1, "macierz_przesuniecia1");

	tekstury[0] = ekran.Wczytaj_Teksture("tekstury/moja_tekstura2.bmp");
	glUniform1i(tekstury[0], 0);
	tekstury[1] = ekran.Wczytaj_Teksture("tekstury/Rock-Texture-Surface.bmp");
	glUniform1i(tekstury[1], 0);

	float dx, dy, promien = 0.8, angle = 0;
	float dx1, dy1, promien1 = 0.5, angle1 = 0;
	mat4 wynik_trans(1.0);
	mat4 wynik_trans1(1.0);

	while (!glfwWindowShouldClose(mojeOkno))
	{
		angle += 1;
		trans.funkcja_Po_Okregu(promien, angle, dx, dy);
		trans.funkcja_Po_Okregu(promien1, angle1, dx1, dy1);
		dx1 = 0; dy1 = 0;
		wynik_trans = trans.przesun(dx, dy, 0.0);
		wynik_trans = trans.obroc(wynik_trans, angle / 15, false, true, false);
		wynik_trans1 = trans.przesun(dx1, dy1, 0.0);
		wynik_trans1 = trans.obroc(wynik_trans1, angle1 / 30, true, false, false);
		glUniformMatrix4fv(transformacja, 1, GL_FALSE, value_ptr(wynik_trans));

		glUniformMatrix4fv(transformacja1, 1, GL_FALSE, value_ptr(wynik_trans1));

		ekran.cls(0.0f, 0.0f, 0.3f);

		glUseProgram(shaders);
		glBindTexture(GL_TEXTURE_2D, tekstury[0]);
		for (int i = 0; i < starting_vertex.size(); i++) {
			glBindVertexArray(vao);
			glDrawArrays(GL_TRIANGLES, starting_vertex[i], vertices_count[i]);
		}

		glUseProgram(shaders1);
		glBindTexture(GL_TEXTURE_2D, tekstury[1]);
		for (int i = 0; i < starting_vertex1.size(); i++) {
			glBindVertexArray(vao1);
			glDrawArrays(GL_TRIANGLES, starting_vertex1[i], vertices_count1[i]);
		}

//		ekran.rysuj(shaders, vao, 1);
		ekran.LicznikFPS();
		ekran.swapBuffers();
	}

	// destruktor zamyka okno itp.
	return 0;
}

