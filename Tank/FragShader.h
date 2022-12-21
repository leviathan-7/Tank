#ifndef FS_H
#define FS_H

#include <glm/glm.hpp>

const char* FragShaderSource = R"(
    #version 330 core
    
    in vec3 vs_position;
    in vec2 vs_texcoord;
    in vec3 vs_normal;    

    out vec4 color;

    uniform sampler2D texture;

    uniform vec3 view_position;


    vec4 shadeToon(vec3 light_direction, float intensivity)
    {
        vec4 diffColor = texture(texture, vs_texcoord);
        vec3 normal = normalize(vs_normal);
        vec3 lightDir = normalize(light_direction);
        float diff = 0.2f + max(dot(normal, lightDir), 0.0f);
        if (diff < 0.4f)
        {
            diffColor *= 0.3f;
        }
        else if (diff > 0.7f)    
        {
            diffColor *= 1.3f;
        }
        return diffColor * intensivity;
    }   

    void main() {

        vec3 dir_light_direction = vec3(0.0f,10.0f,50.0f);
        
        float dir_light_intensivity = 0.5f;

        color = texture(texture, vs_texcoord) + shadeToon(dir_light_direction, dir_light_intensivity);
        
    }
)";


#endif
