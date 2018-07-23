#version 430

out vec4 daColor;
in vec3 normalWorld;
in vec3 vertexPositionWorld;
in vec2 finalUV;
in mat4 btn;
in vec3 ReflectDir;

uniform vec3 lightPositionWorld;
uniform vec3 eyePositionWorld;
uniform vec4 ambientLight;
uniform sampler2D meTexture;
uniform sampler2D meNormal;
uniform samplerCube CubeMapTex;

void main()
{
    //Normal
	vec4 normalMap = texture(meNormal, finalUV);
	normalMap = normalize(normalMap * 2.0f - 1.0f);
	vec4 normalMapping = btn * normalize(normalMap);

	// Diffuse
	vec3 lightVectorWorld = normalize(lightPositionWorld - vertexPositionWorld);
	float brightness = dot(lightVectorWorld, normalize(vec3(normalMapping)));
	vec4 diffuseLight = vec4(brightness, brightness, brightness, 1.0);

	// Specular
	vec3 reflectedLightVectorWorld = reflect(-lightVectorWorld, vec3(normalMapping));
	vec3 eyeVectorWorld = normalize(eyePositionWorld - vertexPositionWorld);
	float s = clamp(dot(reflectedLightVectorWorld, eyeVectorWorld), 0, 1);
	s = pow(s, 50);
	vec4 specularLight = vec4(s, 0, 0, 1);

	//Attenuation
	float dist = distance(eyeVectorWorld, vertexPositionWorld);
	float attenuation = 1/(2 + 1 * pow(dist, 2));

	//Texture
	vec4 texColor = texture(meTexture, finalUV);

	daColor = (ambientLight + (clamp(diffuseLight, 0, 1)* texColor + clamp(specularLight, 0, 1)) * attenuation) ;
	
	//CubeMap
	//vec4 cubeMapColor = texture(CubeMapTex, ReflectDir);
	//vec4 FragColor = cubeMapColor;
}