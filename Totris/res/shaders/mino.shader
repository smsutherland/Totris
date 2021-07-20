#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec4 color;

out vec2 v_texCoord;
out vec4 v_color;

uniform mat4 u_MVP;

void main() {
	gl_Position = u_MVP * position;
	v_texCoord = texCoord;
	v_color = color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_texCoord;
in vec4 v_color;

uniform sampler2D u_Texture;

void main() {
	vec4 texColor = texture(u_Texture, v_texCoord);
	float a = v_color.w;
	color = v_color*a + texColor*(1-a);
}