#ifndef V_H
#define V_H

#include <GL/glew.h>
#include "obj-parser.h"

GLuint Program0, Program1, Program2, Program3, Program4, Program5;
GLint Attrib_vertex_position0, Attrib_vertex_texture_coordinate0, Attrib_vertex_normal0;
GLint Attrib_vertex_position1, Attrib_vertex_texture_coordinate1, Attrib_vertex_normal1;
GLint Attrib_vertex_position2, Attrib_vertex_texture_coordinate2, Attrib_vertex_normal2;
GLint Attrib_vertex_position3, Attrib_vertex_texture_coordinate3, Attrib_vertex_normal3;
GLint Attrib_vertex_position4, Attrib_vertex_texture_coordinate4, Attrib_vertex_normal4;
GLint Attrib_vertex_position5, Attrib_vertex_texture_coordinate5, Attrib_vertex_normal5;


GLuint VBO_0, VBO_1, VBO_2, VBO_3, VBO_4, VBO_5;
GLuint texture0, texture1, texture2, texture3, texture4, texture5;

unsigned char* image_Field;
unsigned char* image_ChristmasTree;
unsigned char* image_Tank;
unsigned char* image_Tank3;
unsigned char* image_Stone;
unsigned char* image_Stone2;

auto Field_mesh = parse_obj("Models/Field.obj");
auto ChristmasTree_mesh = parse_obj("Models/ChristmasTree.obj");
auto Tank = parse_obj("Models/Tanks.obj");
auto Stone = parse_obj("Models/Stone.obj");

//Случайные числа, которые определяют местоположения объектов
double xx;
double rr;
double xx4;
double rr4;
double xx5;
double rr5;

GLuint windowWidth = 1200, windowHeight = 1200;

GLfloat cameraX = 0.f, cameraY = 10.f, cameraZ = 20.f;
GLfloat pitch = 5.0f, yaw = -90.0f, roll = 0.0f;  // Тангаж, рысканье и крен

#endif 