#include "Vertex.h"
#include "VertexShader.h"
#include "FragShader.h"
#include "Variables.h"

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


void checkOpenGLerror(const char* str)
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
        std::cout << "GLerror Log: " <<str<<" = "<< err << std::endl;
}


void initVBOProgram0()
{
    glGenBuffers(1, &VBO_0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Field_mesh.size(), Field_mesh.data(), GL_STATIC_DRAW);
    checkOpenGLerror("initVBOProgram0");
}

void initVBOProgram1()
{
    glGenBuffers(1, &VBO_1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_1);

    std::vector<Vertex> V = {};

    for (Vertex var : ChristmasTree_mesh)
    {
        Vertex ver;
        ver.normal = var.normal;
        ver.position = var.position;
        ver.texcoord = var.texcoord;
        ver.normal.x += 5;
        ver.position.x += 5;
        V.push_back(ver);
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * V.size(), V.data(), GL_STATIC_DRAW);
    checkOpenGLerror("initVBOProgram1");
}

void initVBOProgram2(double x, double r)
{
    glGenBuffers(1, &VBO_2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_2);

    std::vector<Vertex> V = {};

    for (Vertex var : Tank)
    {
        Vertex ver;
        ver.normal = var.normal;
        ver.position = var.position;
        ver.texcoord = var.texcoord;
        ver.normal.x += x;
        ver.position.x += x;
        ver.normal.z += r;
        ver.position.z += r;
        V.push_back(ver);
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * V.size(), V.data(), GL_STATIC_DRAW);
    checkOpenGLerror("initVBOProgram2");
}

void initVBOProgram3()
{

    glGenBuffers(1, &VBO_3);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_3);

    std::vector<Vertex> V = {};

    for (Vertex var : Tank)
    {
        Vertex ver;
        ver.normal = var.normal;
        ver.position = var.position;
        ver.texcoord = var.texcoord;
        ver.normal.x += xx;
        ver.position.x += xx;
        ver.normal.z += rr;
        ver.position.z += rr;
        V.push_back(ver);
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * V.size(), V.data(), GL_STATIC_DRAW);
    checkOpenGLerror("initVBOProgram3");
}

void initVBOProgram4()
{

    glGenBuffers(1, &VBO_4);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_4);

    std::vector<Vertex> V = {};

    for (Vertex var : Stone)
    {
        Vertex ver;
        ver.normal = var.normal;
        ver.position = var.position;
        ver.texcoord = var.texcoord;
        ver.normal.x += xx4;
        ver.position.x += xx4;
        ver.normal.z += rr4;
        ver.position.z += rr4;
        V.push_back(ver);
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * V.size(), V.data(), GL_STATIC_DRAW);
    checkOpenGLerror("initVBOProgram4");
}

void initVBOProgram5()
{

    glGenBuffers(1, &VBO_5);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_5);

    std::vector<Vertex> V = {};

    for (Vertex var : Stone)
    {
        Vertex ver;
        ver.normal = var.normal;
        ver.position = var.position;
        ver.texcoord = var.texcoord;
        ver.normal.x += xx5;
        ver.position.x += xx5;
        ver.normal.z += rr5;
        ver.position.z += rr5;
        V.push_back(ver);
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * V.size(), V.data(), GL_STATIC_DRAW);
    checkOpenGLerror("initVBOProgram5");
}

void InitVBOs(double x, double r)
{
    initVBOProgram0();
    initVBOProgram1();
    initVBOProgram2(x,r);
    initVBOProgram3();
    initVBOProgram4();
    initVBOProgram5();
}

void ShaderLog(unsigned int shader)
{
    int infologLen = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infologLen);
    if (infologLen > 1)
    {
        int charsWritten = 0;
        std::vector<char> infoLog(infologLen);
        glGetShaderInfoLog(shader, infologLen, &charsWritten, infoLog.data());
        std::cout << "InfoLog: " << infoLog.data() << std::endl;
    }
}

void initShaderProgram0()
{
    GLuint vShader0 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader0, 1, &VertexShaderSource, NULL);
    glCompileShader(vShader0);
    std::cout << "vertex shader \n";
    ShaderLog(vShader0);

    GLuint fShader0 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader0, 1, &FragShaderSource, NULL);
    glCompileShader(fShader0);
    std::cout << "fragment shader \n";
    ShaderLog(fShader0);

    Program0 = glCreateProgram();

    glAttachShader(Program0, vShader0);
    glAttachShader(Program0, fShader0);

    glLinkProgram(Program0);
    int link_ok0;
    glGetProgramiv(Program0, GL_LINK_STATUS, &link_ok0);
    if (!link_ok0)
    {
        std::cout << "error attach shaders \n";
        return;
    }

    const char* attr_name_position0 = "position";
    Attrib_vertex_position0 = glGetAttribLocation(Program0, attr_name_position0);
    if (Attrib_vertex_position0 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_position0 << std::endl;
        return;
    }

    const char* attr_name_texture_coordinate0 = "texcoord";
    Attrib_vertex_texture_coordinate0 = glGetAttribLocation(Program0, attr_name_texture_coordinate0);
    if (Attrib_vertex_texture_coordinate0 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_texture_coordinate0 << std::endl;
        return;
    }

    const char* attr_name_normal = "normal";
    Attrib_vertex_normal0 = glGetAttribLocation(Program0, attr_name_normal);
    if (Attrib_vertex_position0 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_normal << std::endl;
        return;
    }

    checkOpenGLerror("initShaderProgram0");
}

void initShaderProgram1()
{
    GLuint vShader1 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader1, 1, &VertexShaderSource, NULL);
    glCompileShader(vShader1);
    std::cout << "vertex shader \n";
    ShaderLog(vShader1);

    GLuint fShader1 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader1, 1, &FragShaderSource, NULL);
    glCompileShader(fShader1);
    std::cout << "fragment shader \n";
    ShaderLog(fShader1);

    Program1 = glCreateProgram();

    glAttachShader(Program1, vShader1);
    glAttachShader(Program1, fShader1);

    glLinkProgram(Program1);
    int link_ok1;
    glGetProgramiv(Program1, GL_LINK_STATUS, &link_ok1);
    if (!link_ok1)
    {
        std::cout << "error attach shaders \n";
        return;
    }

    const char* attr_name_position1 = "position";
    Attrib_vertex_position1 = glGetAttribLocation(Program1, attr_name_position1);
    if (Attrib_vertex_position1 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_position1 << std::endl;
        return;
    }

    const char* attr_name_texture_coordinate1 = "texcoord";
    Attrib_vertex_texture_coordinate1 = glGetAttribLocation(Program0, attr_name_texture_coordinate1);
    if (Attrib_vertex_texture_coordinate1 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_texture_coordinate1 << std::endl;
        return;
    }

    const char* attr_name_normal = "normal";
    Attrib_vertex_normal1 = glGetAttribLocation(Program1, attr_name_normal);
    if (Attrib_vertex_position1 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_normal << std::endl;
        return;
    }

    checkOpenGLerror("initShaderProgram1");
}

void initShaderProgram2()
{
    GLuint vShader2 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader2, 1, &VertexShaderSource2, NULL);
    glCompileShader(vShader2);
    std::cout << "vertex shader \n";
    ShaderLog(vShader2);

    GLuint fShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader2, 1, &FragShaderSource, NULL);
    glCompileShader(fShader2);
    std::cout << "fragment shader \n";
    ShaderLog(fShader2);

    Program2 = glCreateProgram();

    glAttachShader(Program2, vShader2);
    glAttachShader(Program2, fShader2);

    glLinkProgram(Program2);
    int link_ok2;
    glGetProgramiv(Program2, GL_LINK_STATUS, &link_ok2);
    if (!link_ok2)
    {
        std::cout << "error attach shaders \n";
        return;
    }

    const char* attr_name_position2 = "position";
    Attrib_vertex_position2 = glGetAttribLocation(Program2, attr_name_position2);
    if (Attrib_vertex_position2 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_position2 << std::endl;
        return;
    }

    const char* attr_name_texture_coordinate2 = "texcoord";
    Attrib_vertex_texture_coordinate2 = glGetAttribLocation(Program0, attr_name_texture_coordinate2);
    if (Attrib_vertex_texture_coordinate2 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_texture_coordinate2 << std::endl;
        return;
    }

    const char* attr_name_normal = "normal";
    Attrib_vertex_normal2 = glGetAttribLocation(Program2, attr_name_normal);
    if (Attrib_vertex_position2 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_normal << std::endl;
        return;
    }

    checkOpenGLerror("initShaderProgram2");
}

void initShaderProgram3()
{
    GLuint vShader3 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader3, 1, &VertexShaderSource, NULL);
    glCompileShader(vShader3);
    std::cout << "vertex shader \n";
    ShaderLog(vShader3);

    GLuint fShader3 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader3, 1, &FragShaderSource, NULL);
    glCompileShader(fShader3);
    std::cout << "fragment shader \n";
    ShaderLog(fShader3);

    Program3 = glCreateProgram();

    glAttachShader(Program3, vShader3);
    glAttachShader(Program3, fShader3);

    glLinkProgram(Program3);
    int link_ok;
    glGetProgramiv(Program3, GL_LINK_STATUS, &link_ok);
    if (!link_ok)
    {
        std::cout << "error attach shaders \n";
        return;
    }

    const char* attr_name_position3 = "position";
    Attrib_vertex_position3 = glGetAttribLocation(Program3, attr_name_position3);
    if (Attrib_vertex_position3 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_position3 << std::endl;
        return;
    }

    const char* attr_name_texture_coordinate3 = "texcoord";
    Attrib_vertex_texture_coordinate3 = glGetAttribLocation(Program0, attr_name_texture_coordinate3);
    if (Attrib_vertex_texture_coordinate3 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_texture_coordinate3 << std::endl;
        return;
    }

    const char* attr_name_normal = "normal";
    Attrib_vertex_normal3 = glGetAttribLocation(Program3, attr_name_normal);
    if (Attrib_vertex_position3 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_normal << std::endl;
        return;
    }

    checkOpenGLerror("initShaderProgram3");
}

void initShaderProgram4()
{
    GLuint vShader4 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader4, 1, &VertexShaderSource, NULL);
    glCompileShader(vShader4);
    std::cout << "vertex shader \n";
    ShaderLog(vShader4);

    GLuint fShader4 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader4, 1, &FragShaderSource, NULL);
    glCompileShader(fShader4);
    std::cout << "fragment shader \n";
    ShaderLog(fShader4);

    Program4 = glCreateProgram();

    glAttachShader(Program4, vShader4);
    glAttachShader(Program4, fShader4);

    glLinkProgram(Program4);
    int link_ok;
    glGetProgramiv(Program4, GL_LINK_STATUS, &link_ok);
    if (!link_ok)
    {
        std::cout << "error attach shaders \n";
        return;
    }

    const char* attr_name_position4 = "position";
    Attrib_vertex_position4 = glGetAttribLocation(Program4, attr_name_position4);
    if (Attrib_vertex_position4 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_position4 << std::endl;
        return;
    }

    const char* attr_name_texture_coordinate4 = "texcoord";
    Attrib_vertex_texture_coordinate4 = glGetAttribLocation(Program0, attr_name_texture_coordinate4);
    if (Attrib_vertex_texture_coordinate4 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_texture_coordinate4 << std::endl;
        return;
    }

    const char* attr_name_normal = "normal";
    Attrib_vertex_normal4 = glGetAttribLocation(Program4, attr_name_normal);
    if (Attrib_vertex_position4 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_normal << std::endl;
        return;
    }

    checkOpenGLerror("initShaderProgram4");
}

void initShaderProgram5()
{
    GLuint vShader5 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader5, 1, &VertexShaderSource, NULL);
    glCompileShader(vShader5);
    std::cout << "vertex shader \n";
    ShaderLog(vShader5);

    GLuint fShader5 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader5, 1, &FragShaderSource, NULL);
    glCompileShader(fShader5);
    std::cout << "fragment shader \n";
    ShaderLog(fShader5);

    Program5 = glCreateProgram();

    glAttachShader(Program5, vShader5);
    glAttachShader(Program5, fShader5);

    glLinkProgram(Program5);
    int link_ok;
    glGetProgramiv(Program5, GL_LINK_STATUS, &link_ok);
    if (!link_ok)
    {
        std::cout << "error attach shaders \n";
        return;
    }

    const char* attr_name_position5 = "position";
    Attrib_vertex_position5 = glGetAttribLocation(Program5, attr_name_position5);
    if (Attrib_vertex_position5 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_position5 << std::endl;
        return;
    }

    const char* attr_name_texture_coordinate5 = "texcoord";
    Attrib_vertex_texture_coordinate5 = glGetAttribLocation(Program0, attr_name_texture_coordinate5);
    if (Attrib_vertex_texture_coordinate5 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_texture_coordinate5 << std::endl;
        return;
    }

    const char* attr_name_normal = "normal";
    Attrib_vertex_normal5 = glGetAttribLocation(Program5, attr_name_normal);
    if (Attrib_vertex_position5 == -1)
    {
        std::cout << "could not bind attrib " << attr_name_normal << std::endl;
        return;
    }

    checkOpenGLerror("initShaderProgram5");
}

void InitShaders()
{
    initShaderProgram0();
    initShaderProgram1();
    initShaderProgram2();
    initShaderProgram3();
    initShaderProgram4();
    initShaderProgram5();
}

void initTextureProgram0()
{
    int image_width_Field, image_height_Field;
    const char* filename_Field = "Textures/Field.png";
    image_Field = SOIL_load_image(filename_Field, &image_width_Field, &image_height_Field, NULL, SOIL_LOAD_RGBA);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texture0);
    glBindTexture(GL_TEXTURE_2D, texture0);

    if (image_Field)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width_Field, image_height_Field, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_Field);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "could not load texture " << filename_Field << std::endl;
        return;
    }
}

void initTextureProgram1()
{
    int image_width_ChristmasTree, image_height_ChristmasTree;
    const char* filename_ChristmasTree = "Textures/ChristmasTree.png";
    image_ChristmasTree = SOIL_load_image(filename_ChristmasTree, &image_width_ChristmasTree, &image_height_ChristmasTree, NULL, SOIL_LOAD_RGBA);
    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    if (image_ChristmasTree)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width_ChristmasTree, image_height_ChristmasTree, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_ChristmasTree);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "could not load texture " << filename_ChristmasTree << std::endl;
        return;
    }
}

void initTextureProgram2()
{
    int image_width_Tank, image_height_Tank;
    const char* filename_Tank = "Textures/Tank.png";
    image_Tank = SOIL_load_image(filename_Tank, &image_width_Tank, &image_height_Tank, NULL, SOIL_LOAD_RGBA);
    glActiveTexture(GL_TEXTURE2);
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    if (image_Tank)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width_Tank, image_height_Tank, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_Tank);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "could not load texture " << filename_Tank << std::endl;
        return;
    }
}

void initTextureProgram3()
{
    int image_width_Tank, image_height_Tank;
    const char* filename_Tank = "Textures/Tank.png";
    image_Tank3 = SOIL_load_image(filename_Tank, &image_width_Tank, &image_height_Tank, NULL, SOIL_LOAD_RGBA);
    glActiveTexture(GL_TEXTURE3);
    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);

    if (image_Tank3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width_Tank, image_height_Tank, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_Tank3);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "could not load texture " << filename_Tank << std::endl;
        return;
    }
}

void initTextureProgram4()
{
    int image_width_Stone, image_height_Stone;
    const char* filename_Stone = "Textures/Stone.png";
    image_Stone = SOIL_load_image(filename_Stone, &image_width_Stone, &image_height_Stone, NULL, SOIL_LOAD_RGBA);
    glActiveTexture(GL_TEXTURE4);
    glGenTextures(1, &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);

    if (image_Stone)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width_Stone, image_height_Stone, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_Stone);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "could not load texture " << filename_Stone << std::endl;
        return;
    }
}

void initTextureProgram5()
{
    int image_width_Stone, image_height_Stone;
    const char* filename_Stone = "Textures/Stone.png";
    image_Stone2 = SOIL_load_image(filename_Stone, &image_width_Stone, &image_height_Stone, NULL, SOIL_LOAD_RGBA);
    glActiveTexture(GL_TEXTURE5);
    glGenTextures(1, &texture5);
    glBindTexture(GL_TEXTURE_2D, texture5);

    if (image_Stone2)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width_Stone, image_height_Stone, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_Stone2);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "could not load texture " << filename_Stone << std::endl;
        return;
    }
}

void InitTextures()
{
    initTextureProgram0();
    initTextureProgram1();
    initTextureProgram2();
    initTextureProgram3();
    initTextureProgram4();
    initTextureProgram5();
}


void drawProgram0()
{
    glUseProgram(Program0);
    glEnableVertexAttribArray(Attrib_vertex_normal0);
    glEnableVertexAttribArray(Attrib_vertex_position0);
    glEnableVertexAttribArray(Attrib_vertex_texture_coordinate0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_0);

    glVertexAttribPointer(Attrib_vertex_position0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glVertexAttribPointer(Attrib_vertex_texture_coordinate0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glVertexAttribPointer(Attrib_vertex_normal0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
    model = glm::scale(model, glm::vec3(2.0f));

    glm::vec3 camera_position(cameraX, cameraY, cameraZ);
    glm::vec3 camera_up(0.0f, 0.0f, 1.0f);
    glm::vec3 camera_front = glm::normalize(
        glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        )
    );

    glm::mat4 view(1.0f);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);

    GLfloat field_of_view = 120.0f;
    GLfloat near_plane = 0.01f;
    GLfloat far_plane = 10000.0f;
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(field_of_view), static_cast<GLfloat>(windowWidth) / windowHeight, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(Program0, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(Program0, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(Program0, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(glGetUniformLocation(Program0, "view_position"), cameraX, cameraY, cameraZ);
    glUniform1i(glGetUniformLocation(Program0, "texture"), 0);
    glDrawArrays(GL_TRIANGLES, 0, Field_mesh.size());

    glDisableVertexAttribArray(Attrib_vertex_position0);
    glDisableVertexAttribArray(Attrib_vertex_texture_coordinate0);
    glDisableVertexAttribArray(Attrib_vertex_normal0);
    glUseProgram(0);

    checkOpenGLerror("drawProgram0");
}

void drawProgram1()
{
    glUseProgram(Program1);
    glEnableVertexAttribArray(Attrib_vertex_normal1);
    glEnableVertexAttribArray(Attrib_vertex_position1);
    glEnableVertexAttribArray(Attrib_vertex_texture_coordinate1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_1);

    glVertexAttribPointer(Attrib_vertex_position1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glVertexAttribPointer(Attrib_vertex_texture_coordinate1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glVertexAttribPointer(Attrib_vertex_normal1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
    model = glm::scale(model, glm::vec3(2.5f));

    glm::vec3 camera_position(cameraX, cameraY, cameraZ);
    glm::vec3 camera_up(0.0f, 0.0f, 1.0f);
    glm::vec3 camera_front = glm::normalize(
        glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        )
    );

    glm::mat4 view(1.0f);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);

    GLfloat field_of_view = 120.0f;
    GLfloat near_plane = 0.01f;
    GLfloat far_plane = 10000.0f;
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(field_of_view), static_cast<GLfloat>(windowWidth) / windowHeight, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(Program1, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(Program1, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(Program1, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(glGetUniformLocation(Program1, "view_position"), cameraX, cameraY, cameraZ);
    glUniform1i(glGetUniformLocation(Program1, "texture"), 1);
    glDrawArrays(GL_TRIANGLES, 0, ChristmasTree_mesh.size());

    glDisableVertexAttribArray(Attrib_vertex_position1);
    glDisableVertexAttribArray(Attrib_vertex_texture_coordinate1);
    glDisableVertexAttribArray(Attrib_vertex_normal1);
    glUseProgram(0);

    checkOpenGLerror("drawProgram1");
}

void drawProgram2()
{
    glUseProgram(Program2);
    glEnableVertexAttribArray(Attrib_vertex_normal2);
    glEnableVertexAttribArray(Attrib_vertex_position2);
    glEnableVertexAttribArray(Attrib_vertex_texture_coordinate2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_2);

    glVertexAttribPointer(Attrib_vertex_position2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glVertexAttribPointer(Attrib_vertex_texture_coordinate2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glVertexAttribPointer(Attrib_vertex_normal2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
    model = glm::scale(model, glm::vec3(2.5f));

    glm::vec3 camera_position(cameraX, cameraY, cameraZ);
    glm::vec3 camera_up(0.0f, 0.0f, 1.0f);
    glm::vec3 camera_front = glm::normalize(
        glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        )
    );

    glm::mat4 view(1.0f);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);

    GLfloat field_of_view = 120.0f;
    GLfloat near_plane = 0.01f;
    GLfloat far_plane = 10000.0f;
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(field_of_view), static_cast<GLfloat>(windowWidth) / windowHeight, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(Program2, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(Program2, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(Program2, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(glGetUniformLocation(Program2, "view_position"), cameraX, cameraY, cameraZ);
    glUniform1i(glGetUniformLocation(Program2, "texture"), 2);
    glDrawArrays(GL_TRIANGLES, 0, Tank.size());

    glDisableVertexAttribArray(Attrib_vertex_position2);
    glDisableVertexAttribArray(Attrib_vertex_texture_coordinate2);
    glDisableVertexAttribArray(Attrib_vertex_normal2);
    glUseProgram(0);

    checkOpenGLerror("drawProgram2");
}

void drawProgram3()
{
    glUseProgram(Program3);
    glEnableVertexAttribArray(Attrib_vertex_normal3);
    glEnableVertexAttribArray(Attrib_vertex_position3);
    glEnableVertexAttribArray(Attrib_vertex_texture_coordinate3);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_3);

    glVertexAttribPointer(Attrib_vertex_position3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glVertexAttribPointer(Attrib_vertex_texture_coordinate3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glVertexAttribPointer(Attrib_vertex_normal3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
    model = glm::scale(model, glm::vec3(2.5f));

    glm::vec3 camera_position(cameraX, cameraY, cameraZ);
    glm::vec3 camera_up(0.0f, 0.0f, 1.0f);
    glm::vec3 camera_front = glm::normalize(
        glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        )
    );

    glm::mat4 view(1.0f);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);

    GLfloat field_of_view = 120.0f;
    GLfloat near_plane = 0.01f;
    GLfloat far_plane = 10000.0f;
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(field_of_view), static_cast<GLfloat>(windowWidth) / windowHeight, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(Program3, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(Program3, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(Program3, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(glGetUniformLocation(Program3, "view_position"), cameraX, cameraY, cameraZ);
    glUniform1i(glGetUniformLocation(Program3, "texture"), 3);
    glDrawArrays(GL_TRIANGLES, 0, Tank.size());

    glDisableVertexAttribArray(Attrib_vertex_position3);
    glDisableVertexAttribArray(Attrib_vertex_texture_coordinate3);
    glDisableVertexAttribArray(Attrib_vertex_normal3);
    glUseProgram(0);

    checkOpenGLerror("drawProgram3");
}

void drawProgram4()
{
    glUseProgram(Program4);
    glEnableVertexAttribArray(Attrib_vertex_normal4);
    glEnableVertexAttribArray(Attrib_vertex_position4);
    glEnableVertexAttribArray(Attrib_vertex_texture_coordinate4);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_4);

    glVertexAttribPointer(Attrib_vertex_position4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glVertexAttribPointer(Attrib_vertex_texture_coordinate4, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glVertexAttribPointer(Attrib_vertex_normal4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
    model = glm::scale(model, glm::vec3(2.5f));

    glm::vec3 camera_position(cameraX, cameraY, cameraZ);
    glm::vec3 camera_up(0.0f, 0.0f, 1.0f);
    glm::vec3 camera_front = glm::normalize(
        glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        )
    );

    glm::mat4 view(1.0f);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);

    GLfloat field_of_view = 120.0f;
    GLfloat near_plane = 0.01f;
    GLfloat far_plane = 10000.0f;
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(field_of_view), static_cast<GLfloat>(windowWidth) / windowHeight, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(Program4, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(Program4, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(Program4, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(glGetUniformLocation(Program4, "view_position"), cameraX, cameraY, cameraZ);
    glUniform1i(glGetUniformLocation(Program4, "texture"), 4);
    glDrawArrays(GL_TRIANGLES, 0, Tank.size());

    glDisableVertexAttribArray(Attrib_vertex_position4);
    glDisableVertexAttribArray(Attrib_vertex_texture_coordinate4);
    glDisableVertexAttribArray(Attrib_vertex_normal4);
    glUseProgram(0);

    checkOpenGLerror("drawProgram4");
}

void drawProgram5()
{
    glUseProgram(Program5);

    glEnableVertexAttribArray(Attrib_vertex_position5);
    glEnableVertexAttribArray(Attrib_vertex_texture_coordinate5);
    glEnableVertexAttribArray(Attrib_vertex_normal5);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_5);

    glVertexAttribPointer(Attrib_vertex_position5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glVertexAttribPointer(Attrib_vertex_texture_coordinate5, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glVertexAttribPointer(Attrib_vertex_normal5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
    model = glm::scale(model, glm::vec3(2.5f));

    glm::vec3 camera_position(cameraX, cameraY, cameraZ);
    glm::vec3 camera_up(0.0f, 0.0f, 1.0f);
    glm::vec3 camera_front = glm::normalize(
        glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        )
    );

    glm::mat4 view(1.0f);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);

    GLfloat field_of_view = 120.0f;
    GLfloat near_plane = 0.01f;
    GLfloat far_plane = 10000.0f;
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(field_of_view), static_cast<GLfloat>(windowWidth) / windowHeight, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(Program5, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(Program5, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(Program5, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3f(glGetUniformLocation(Program5, "view_position"), cameraX, cameraY, cameraZ);
    glUniform1i(glGetUniformLocation(Program5, "texture"), 5);
    glDrawArrays(GL_TRIANGLES, 0, Tank.size());

    glDisableVertexAttribArray(Attrib_vertex_position5);
    glDisableVertexAttribArray(Attrib_vertex_texture_coordinate5);
    glDisableVertexAttribArray(Attrib_vertex_normal5);

    glUseProgram(0);

    checkOpenGLerror("drawProgram4");
}

void Draw()
{
    drawProgram0();
    drawProgram1();
    drawProgram2();
    drawProgram3();
    drawProgram4();
    drawProgram5();
}

void InitOptions()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Init(double x , double r = 0)
{
    InitOptions();
    InitShaders();
    InitTextures();
    InitVBOs(x,r);
}

void ReleaseVBOs()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBO_0);
    glDeleteBuffers(1, &VBO_1);
    glDeleteBuffers(1, &VBO_2);
    glDeleteBuffers(1, &VBO_3);
    glDeleteBuffers(1, &VBO_4);
    glDeleteBuffers(1, &VBO_5);
}

void ReleaseShaders()
{
    glUseProgram(0);
    glDeleteProgram(Program0);
    glDeleteProgram(Program1);
    glDeleteProgram(Program2);
    glDeleteProgram(Program3);
    glDeleteProgram(Program4);
    glDeleteProgram(Program5);
}

void ReleaseTextures()
{
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    SOIL_free_image_data(image_Field);
    SOIL_free_image_data(image_ChristmasTree);
    SOIL_free_image_data(image_Tank);
    SOIL_free_image_data(image_Tank3);
    SOIL_free_image_data(image_Stone);
    SOIL_free_image_data(image_Stone2);
}

void Release()
{
    ReleaseShaders();
    ReleaseVBOs();
    ReleaseTextures();
}

void MakeRandCoord() 
{
    srand(time(0));
    xx = ((rand() % 100) - 50) / 5.0;
    rr = ((rand() % 100) - 50) / 5.0;
    xx4 = ((rand() % 100) - 50) / 5.0;
    rr4 = ((rand() % 100) - 50) / 5.0;
    xx5 = ((rand() % 100) - 50) / 5.0;
    rr5 = ((rand() % 100) - 50) / 5.0;
}

int main()
{
    MakeRandCoord();

    sf::Window window(sf::VideoMode(windowWidth, windowHeight), "Tank", sf::Style::Default, sf::ContextSettings(24));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);

    glewInit();
    Init(0);
    double x = 0;
    double r = 0;
    double t = 0.5f;
    double a = 0.2f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                glViewport(0, 0, event.size.width, event.size.height);
                windowWidth = event.size.width;
                windowHeight = event.size.height;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    x -= t;
                    Init(x,r);
                    cameraZ -= t*2.5;
                    break;
                case sf::Keyboard::Down:
                    x += t;
                    cameraZ += t * 2.5;
                    Init(x,r);
                    break;
                case sf::Keyboard::Right:
                    x -= a;
                    r -= a;
                    cameraX += t;
                    cameraZ -= t;
                    Init(x,r);
                    break;
                case sf::Keyboard::Left:
                    x -= a;
                    r += a;
                    cameraX -= t;
                    cameraZ -= t;
                    Init(x, r);
                    break;
                }

            }
        }
        glClearColor(0.1f, 0.6f, 0.2f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Draw();
        window.display();
    }
    Release();
    return 0;
}
