#ifndef VS_H
#define VS_H

#include <glm/glm.hpp>

const char* VertexShaderSource = R"(
    #version 330 core

    in vec3 position;
    in vec2 texcoord;
    in vec3 normal;

    out vec3 vs_position;
    out vec2 vs_texcoord;
    out vec3 vs_normal;

    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main() {
        vs_position = vec4(model * vec4(position, 1.0f)).xyz;
        vs_texcoord = vec2(texcoord.x, texcoord.y);

        gl_Position = projection * view * model * vec4(position, 1.0f);

        vs_normal = normal;
    }
)";

const char* VertexShaderSource2 = R"(
    #version 330 core

    in vec3 position;
    in vec2 texcoord;
    in vec3 normal;

    out vec3 vs_position;
    out vec2 vs_texcoord;
    out vec3 vs_normal;

    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main() {
        vs_position = vec4(model * vec4(position, 1.0f)).xyz;
        vs_texcoord = vec2(texcoord.x, texcoord.y);
        mat3 Rotate = mat3(0,0,-1,0,1,0,1,0,0);
        gl_Position = projection * view * model * vec4((position * Rotate), 1.0f);

        vs_normal = normal;
    }
)";


#endif
