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


    vec4 shadePhong(vec3 light_direction, vec3 view_direction, float intensivity)
    {
        vec4 textureColor = texture(texture, vs_texcoord);
        vec3 normal = normalize(vs_normal);
        vec3 lightDir = normalize(light_direction);
        vec3 viewDir = normalize(view_direction);
        vec3 reflectedViewDir = reflect(-viewDir, normal);
        vec4 diff = textureColor * max(dot(normal, lightDir), 0.0f);
        vec4 spec = textureColor * pow(max(dot(lightDir, reflectedViewDir), 0.0f), 8.0f);
        return (diff + spec) * intensivity;
    }
    vec4 shadeMinnaert(vec3 light_direction, vec3 view_direction, float intensivity)
    {
        vec4 diffColor = texture(texture, vs_texcoord);
        float k = 0.8f;
        vec3 normal = normalize(vs_normal);
        vec3 lightDir = normalize(light_direction);
        vec3 viewDir = normalize(view_direction);
        float d1 = pow(max(dot(normal, lightDir), 0.0f), 1.0f + k);
        float d2 = pow(1.0f - dot(normal, viewDir), 1.0f - k);
        return diffColor * d1 * d2 * intensivity;
    }
    void main() {

        vec3 dir_light_direction = vec3(10.0f,30.0f,0.0f);
        
        float dir_light_intensivity = 0.7f;
        vec3 view_direction = view_position - vs_position;
        color = texture(texture, vs_texcoord) + shadeMinnaert(dir_light_direction, view_direction, dir_light_intensivity);
    }
)";


#endif
