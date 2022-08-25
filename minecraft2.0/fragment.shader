#version 330 core

out vec4 FragColor;

in vec2 texCoord;
uniform sampler2D texture1;

void main()
{
	//FragColor = vec4(0.7f, 1.0f, 0.7f, 1.0f);
	FragColor = texture(texture1, texCoord);
}