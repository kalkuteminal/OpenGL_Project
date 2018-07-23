#version 430

in layout(location=0) vec3 vertexPositionModel;
in layout(location=1) vec4 color;
in layout(location=2) vec3 normalModel;
in layout(location=3) vec2 uv;
in layout(location=4) vec3 tangentModel;


uniform mat4 modelToProjectionMatrix;
uniform mat4 modelToWorldMatrix;
uniform bool DrawSkyBox;

out vec3 normalWorld;
out vec3 vertexPositionWorld;
out vec2 finalUV;
out mat4 btn;
out vec3 ReflectDir;

void main()
{
	gl_Position = modelToProjectionMatrix * vec4(vertexPositionModel, 1.0);
	vec3 bitangentModel = cross(normalModel, tangentModel);
	btn = mat4(vec4(normalModel, 1.0),vec4(tangentModel, 1.0), vec4(bitangentModel, 1.0), vec4(0,0,0,1));
	normalWorld = vec3(modelToWorldMatrix * vec4(normalModel, 0));
	vertexPositionWorld = vec3(modelToWorldMatrix * vec4(vertexPositionModel, 1.0));
	finalUV = uv;
	/*if(DrawSkyBox)
	{
		ReflectDir = vec3(vertexPositionModel.x, -vertexPositionModel.yz);
	}
	else
	{
		ReflectDir = reflect(-vertexPositionWorld, normalWorld);	
	}*/
	
}