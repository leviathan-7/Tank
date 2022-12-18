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

    vec3 direction_light_position = vec3(0.0f,10.0f,20.0f);

    vec4 calculate_direction_light()
    {
	    float ambient = 0.30f;

	    vec3 normal = normalize(vs_normal);
	    vec3 light_direction = normalize(direction_light_position);
	    float diffuse = max(dot(normal, light_direction), 0.0f);

	    float specular_light = 0.50f;
	    vec3 view_direction = normalize(view_position - vs_position);
	    vec3 reflection_direction = reflect(-light_direction, normal);
	    float spec_amount = pow(max(dot(view_direction, reflection_direction), 0.0f), 8);
	    float specular = spec_amount * specular_light;

	    return texture(texture, vs_texcoord) * (diffuse + ambient) + texture(texture, vs_texcoord).r * specular;
    }

    void main() {
        color = texture(texture, vs_texcoord) + calculate_direction_light();
    }
)";


#endif
