#include "Cube.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <Primitives\Vertex.h>
#define PI 3.14159265359
using glm::vec3;
using glm::vec2;
using glm::mat4;
using glm::mat3;
#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

glm::vec4 randomColor()
{
	glm::vec4 ret;
	ret.r = rand() / (float)RAND_MAX;
	ret.g = rand() / (float)RAND_MAX;
	ret.b = rand() / (float)RAND_MAX;
	ret.a = 1.0f;
	return ret;
}

//ShapeData Cube::makeCube() {
//	ShapeData ret;
//	Vertex stackVerts[] =
//	{
//		vec3(-0.500000f, -0.500000f, 0.500000f),  // 0
//		vec2(0.375000f, 0.000000f),	// Color
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
//		vec3(0.500000f,  -0.500000f,  0.500000f),  // 1
//		vec2(0.625000f, 0.000000f),	// Color
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
//		vec3(-0.500000f, 0.500000f,  0.500000f),  // 2
//		vec2(0.375000f, 0.250000f),  // Color
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
//		vec3(0.5f, +0.5f, 0.5f),  // 3
//		vec2(0.625000f, 0.250000f),  // Color
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
//
//		vec3(-0.500000f, 0.500000f,  0.500000f),  // 4
//		vec2(0.375000f, 0.250000f),  // Color
//		vec3(+0.0f, +1.0f, +0.0f),  // Normal
//		vec3(0.5f, +0.5f, 0.5f),    // 5
//		vec2(0.625000f, 0.250000f), // Color
//		vec3(+0.0f, +1.0f, 0.0f),  // Normal
//
//		vec3(-0.500000f, 0.500000f, -0.500000f),  // 6
//		vec2(0.375000f,  0.500000f),  // Color
//		vec3(+0.0f, +1.0f, 0.0f),  // Normal
//		vec3(0.500000f, 0.500000f, -0.500000f),  // 7
//		vec2(0.625000f, 0.500000f),  // Color
//		vec3(+0.0f, +1.0f, 0.0f),  // Normal
//
//		vec3(-0.500000f, 0.500000f, -0.500000f),  // 8
//		vec2(+0.375000f, 0.500000f),  // Color
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
//		vec3(0.500000f, 0.500000f, -0.500000f),  // 9
//		vec2(+0.625000f, 0.500000f),  // Color
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
//
//		vec3(-0.500000f, -0.500000f, -0.500000f),  // 10
//		vec2(+0.375000f, 0.750000f),  // Color
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
//		vec3(0.500000f, -0.500000f, -0.500000f),  // 11
//		vec2(+0.625000f, 0.750000f),  // Color
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
//
//		vec3(-0.500000f, -0.500000f, -0.500000f),  // 12
//		vec2(+0.375000f, 0.750000f),  // Color
//		vec3(0.0f, -1.0f, +0.0f),  // Normal
//		vec3(0.500000f, -0.500000f, -0.500000f),  // 13
//		vec2(+0.625000f, 0.750000f),  // Color
//		vec3(0.0f, -1.0f, +0.0f),  // Normal
//		vec3(-0.500000f, -0.500000f, 0.500000f),  // 14
//		vec2(+0.375000f, 1.000000f),  // Color
//		vec3(0.0f, -1.0f, +0.0f),  // Normal
//		vec3(0.500000f, -0.500000f, 0.500000f),  // 15
//		vec2(+0.625000f, 1.000000f),  // Color
//		vec3(0.0f, -1.0f, +0.0f),  // Normal
//
//		vec3(0.500000f,  -0.500000f,  0.500000f),  // 16
//		vec2(0.625000f, 0.000000f),  // Color
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
//		vec3(0.500000f, -0.500000f, -0.500000f),  // 17
//		vec2(+0.875000f, 0.000000f),  // Color
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
//		vec3(0.5f, +0.5f, 0.5f),   // 18
//		vec2(0.625000f, 0.250000f),  // Color
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
//		vec3(0.500000f, 0.500000f, -0.500000f),  // 19
//		vec2(0.875000f, 0.250000f),  // Color
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
//
//		vec3(-0.500000f, -0.500000f, -0.500000f),  // 20
//		vec2(+0.125000f, 0.000000f),  // Color
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
//		vec3(-0.5f, -0.5f, 0.5f),  // 21
//		vec2(+0.375f, +0.0f),  // Color
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
//		vec3(-0.500000f, 0.500000f, -0.500000f),  // 22
//		vec2(+0.125000f, 0.250000f),  // Color
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
//		vec3(-0.5f, +0.5f, +0.5f),  // 23
//		vec2(+0.375f, +0.25f),  // Color
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
//	};
//
//	ret.numVertices = NUM_ARRAY_ELEMENTS(stackVerts);
//	ret.vertices = new Vertex[ret.numVertices];
//	memcpy(ret.vertices, stackVerts, sizeof(stackVerts));
//
//	unsigned short stackIndices[] = {
//		0,   1,  2,  2,  1,  3, // Top
//		4,   5,  6,  6,  5,  7, // Front
//		8,   9, 10,  10, 9, 11, // Back
//		12, 13, 14, 14, 13, 15, // Bottom
//		16, 17, 18, 18, 17, 19, // Right
//		20, 21, 22, 22, 21, 23 // Left
//	};
//	ret.numIndices = NUM_ARRAY_ELEMENTS(stackIndices);
//	ret.indices = new GLushort[ret.numIndices];
//	memcpy(ret.indices, stackIndices, sizeof(stackIndices));
//
//	return ret;
//}

ShapeData ShapeGenerator::makeCube()
{
	using glm::vec2;
	using glm::vec3;
	using glm::vec4;
	ShapeData ret;
	VertexPCNUT stackVerts[] =
	{
		// Top
		vec3(-1.0f, +1.0f, +1.0f),        // 0
		vec4(+1.0f, +0.0f, +0.0f, +1.0f), // Color
		vec3(+0.0f, +1.0f, +0.0f),        // Normal
		vec2(+0.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(+1.0f, +1.0f, +1.0f),        // 1
		vec4(+0.0f, +1.0f, +0.0f, +1.0f), // Color
		vec3(+0.0f, +1.0f, +0.0f),        // Normal
		vec2(+1.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(+1.0f, +1.0f, -1.0f),        // 2
		vec4(+0.0f, +0.0f, +1.0f, +1.0f), // Color
		vec3(+0.0f, +1.0f, +0.0f),        // Normal
		vec2(+1.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(-1.0f, +1.0f, -1.0f),        // 3
		vec4(+1.0f, +1.0f, +1.0f, +1.0f), // Color
		vec3(+0.0f, +1.0f, +0.0f),        // Normal
		vec2(+0.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent

		// Front
		vec3(-1.0f, +1.0f, -1.0f),        // 4
		vec4(+1.0f, +0.0f, +1.0f, +1.0f), // Color
		vec3(+0.0f, +0.0f, -1.0f),        // Normal
		vec2(+0.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(+1.0f, +1.0f, -1.0f),        // 5
		vec4(+0.0f, +0.5f, +0.2f, +1.0f), // Color
		vec3(+0.0f, +0.0f, -1.0f),        // Normal
		vec2(+1.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(+1.0f, -1.0f, -1.0f),        // 6
		vec4(+0.8f, +0.6f, +0.4f, +1.0f), // Color
		vec3(+0.0f, +0.0f, -1.0f),        // Normal
		vec2(+1.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(-1.0f, -1.0f, -1.0f),        // 7
		vec4(+0.3f, +1.0f, +0.5f, +1.0f), // Color
		vec3(+0.0f, +0.0f, -1.0f),        // Normal
		vec2(+0.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent

		// Right
		vec3(+1.0f, +1.0f, -1.0f),        // 8
		vec4(+0.2f, +0.5f, +0.2f, +1.0f), // Color
		vec3(+1.0f, +0.0f, +0.0f),        // Normal
		vec2(+1.0f, +0.0f),               // UV
		vec3(+0.0f, +0.0f, -1.0f),		  // Tangent
		vec3(+1.0f, +1.0f, +1.0f),        // 9
		vec4(+0.9f, +0.3f, +0.7f, +1.0f), // Color
		vec3(+1.0f, +0.0f, +0.0f),        // Normal
		vec2(+0.0f, +0.0f),               // UV
		vec3(+0.0f, +0.0f, -1.0f),		  // Tangent
		vec3(+1.0f, -1.0f, +1.0f),        // 10
		vec4(+0.3f, +0.7f, +0.5f, +1.0f), // Color
		vec3(+1.0f, +0.0f, +0.0f),        // Normal
		vec2(+0.0f, +1.0f),               // UV
		vec3(+0.0f, +0.0f, -1.0f),		  // Tangent
		vec3(+1.0f, -1.0f, -1.0f),        // 11
		vec4(+0.5f, +0.7f, +0.5f, +1.0f), // Color
		vec3(+1.0f, +0.0f, +0.0f),        // Normal
		vec2(+1.0f, +1.0f),               // UV
		vec3(+0.0f, +0.0f, -1.0f),		  // Tangent

		// Left
		vec3(-1.0f, +1.0f, +1.0f),        // 12
		vec4(+0.7f, +0.8f, +0.2f, +1.0f), // Color
		vec3(-1.0f, +0.0f, +0.0f),        // Normal
		vec2(+1.0f, +0.0f),               // UV
		vec3(+0.0f, +0.0f, +1.0f),		  // Tangent
		vec3(-1.0f, +1.0f, -1.0f),        // 13
		vec4(+0.5f, +0.7f, +0.3f, +1.0f), // Color
		vec3(-1.0f, +0.0f, +0.0f),        // Normal
		vec2(+0.0f, +0.0f),               // UV
		vec3(+0.0f, +0.0f, +1.0f),		  // Tangent
		vec3(-1.0f, -1.0f, -1.0f),        // 14
		vec4(+0.4f, +0.7f, +0.7f, +1.0f), // Color
		vec3(-1.0f, +0.0f, +0.0f),        // Normal
		vec2(+0.0f, +1.0f),               // UV
		vec3(+0.0f, +0.0f, +1.0f),		  // Tangent
		vec3(-1.0f, -1.0f, +1.0f),        // 15
		vec4(+0.2f, +0.5f, +1.0f, +1.0f), // Color
		vec3(-1.0f, +0.0f, +0.0f),        // Normal
		vec2(+1.0f, +1.0f),               // UV
		vec3(+0.0f, +0.0f, +1.0f),		  // Tangent

		// Back
		vec3(+1.0f, +1.0f, +1.0f),        // 16
		vec4(+0.6f, +1.0f, +0.7f, +1.0f), // Color
		vec3(+0.0f, +0.0f, +1.0f),        // Normal
		vec2(+1.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(-1.0f, +1.0f, +1.0f),        // 17
		vec4(+0.6f, +0.4f, +0.8f, +1.0f), // Color
		vec3(+0.0f, +0.0f, +1.0f),        // Normal
		vec2(+0.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(-1.0f, -1.0f, +1.0f),        // 18
		vec4(+0.2f, +0.8f, +0.7f, +1.0f), // Color
		vec3(+0.0f, +0.0f, +1.0f),        // Normal
		vec2(+0.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(+1.0f, -1.0f, +1.0f),        // 19
		vec4(+0.2f, +0.7f, +1.0f, +1.0f), // Color
		vec3(+0.0f, +0.0f, +1.0f),        // Normal
		vec2(+1.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent

		// Bottom
		vec3(+1.0f, -1.0f, -1.0f),        // 20
		vec4(+0.8f, +0.3f, +0.7f, +1.0f), // Color
		vec3(+0.0f, -1.0f, +0.0f),        // Normal
		vec2(+1.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(-1.0f, -1.0f, -1.0f),        // 21
		vec4(+0.8f, +0.9f, +0.5f, +1.0f), // Color
		vec3(+0.0f, -1.0f, +0.0f),        // Normal
		vec2(+0.0f, +1.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(-1.0f, -1.0f, +1.0f),        // 22
		vec4(+0.5f, +0.8f, +0.5f, +1.0f), // Color
		vec3(+0.0f, -1.0f, +0.0f),        // Normal
		vec2(+0.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
		vec3(+1.0f, -1.0f, +1.0f),        // 23
		vec4(+0.9f, +1.0f, +0.2f, +1.0f), // Color
		vec3(+0.0f, -1.0f, +0.0f),        // Normal
		vec2(+1.0f, +0.0f),               // UV
		vec3(+1.0f, +0.0f, +0.0f),		  // Tangent
	};

	ret.numVertices = NUM_ARRAY_ELEMENTS(stackVerts);
	ret.vertices = new VertexPCNUT[ret.numVertices];
	memcpy(ret.vertices, stackVerts, sizeof(stackVerts));

	unsigned short stackIndices[] = {
		0,   1,  2,  0,  2,  3, // Top
		4,   5,  6,  4,  6,  7, // Front
		8,   9, 10,  8, 10, 11, // Right 
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};

	ret.numIndices = NUM_ARRAY_ELEMENTS(stackIndices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, stackIndices, sizeof(stackIndices));

	return ret;
}


ShapeData ShapeGenerator::makePlaneVerts(uint dimensions)
{
	ShapeData ret;
	uint vertsPerDimension = dimensions + 1; // + 1 for last row/col of verts
	ret.numVertices = vertsPerDimension * vertsPerDimension;
	ret.vertices = new VertexPCNUT[ret.numVertices];
	float half = dimensions / 2.0f;
	glm::vec3 runner(-half, 0.0f, -half);
	for (int i = 0; i < vertsPerDimension; i++)
	{
		for (int j = 0; j < vertsPerDimension; j++)
		{
			VertexPCNUT& thisVert = ret.vertices[i * vertsPerDimension + j];
			thisVert.position = runner;
			thisVert.color = randomColor();
			thisVert.normal = glm::vec3(0, 1, 0);
			thisVert.tangent = glm::vec3(1, 0, 0);
			thisVert.uv.x = j / (float)dimensions;
			thisVert.uv.y = i / (float)dimensions;
			runner.x++;
		}
		runner.x = -half;
		runner.z++;
	}
	return ret;
}

ShapeData ShapeGenerator::makePlaneIndices(uint dimensions)
{
	ShapeData ret;
	uint vertsPerDimension = dimensions + 1;
	ret.numIndices = dimensions * dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < dimensions; row++)
	{
		for (int col = 0; col < dimensions; col++)
		{
			ret.indices[runner++] = vertsPerDimension * row + col;
			ret.indices[runner++] = vertsPerDimension * row + col + vertsPerDimension;
			ret.indices[runner++] = vertsPerDimension * row + col + vertsPerDimension + 1;

			ret.indices[runner++] = vertsPerDimension * row + col;
			ret.indices[runner++] = vertsPerDimension * row + col + vertsPerDimension + 1;
			ret.indices[runner++] = vertsPerDimension * row + col + 1;
		}
	}
	assert(runner = ret.numIndices);
	return ret;
}

ShapeData ShapeGenerator::makePlaneUnseamedIndices(uint tesselation)
{
	ShapeData ret;
	uint dimensions = tesselation * tesselation;
	ret.numIndices = dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < tesselation; row++)
	{
		// This code is crap but works, and I'm not in the mood right now to clean it up
		for (int col = 0; col < tesselation; col++)
		{
			// Bottom left triangle
			ret.indices[runner++] = tesselation * row + col;
			// One row down unless it's the bottom row, 
			ret.indices[runner++] = (row + 1 == tesselation ? 0 : tesselation * row + tesselation) + col;
			// Move to vert right of this one unless it's the last vert,
			// which we connect to the first vert in the row
			// the % dimensions at the end accounts for the last row hooking to the first row
			ret.indices[runner++] = (tesselation * row + col + tesselation + (col + 1 == tesselation ? -tesselation + 1 : 1)) % dimensions;

			// Upper right triangle
			ret.indices[runner++] = tesselation * row + col;
			if (col + 1 == tesselation && row + 1 == tesselation)
			{
				// Very last vert
				ret.indices[runner++] = 0;
			}
			else if (col + 1 == tesselation)
			{
				// Last vert on this row
				// Check if we need to connect it to zeroeth row or the next row
				if (row + 1 == tesselation)
				{
					// Tie to zeroeth row
					ret.indices[runner++] = col + 1;
				}
				else
				{
					// Tie to next row
					ret.indices[runner++] = tesselation * row + col + 1;
				}
			}
			else
			{
				// Regular interior vert
				// the % dimensions at the end accounts for the last row hooking to the first row
				ret.indices[runner++] = (tesselation * row + col + tesselation + 1) % dimensions;
			}
			ret.indices[runner++] = tesselation * row + col + (col + 1 == tesselation ? -col : 1);
		}
	}
	return ret;
}

ShapeData ShapeGenerator::makePlane(uint dimensions)
{
	ShapeData ret = makePlaneVerts(dimensions);
	ShapeData ret2 = makePlaneIndices(dimensions);
	ret.numIndices = ret2.numIndices;
	ret.indices = ret2.indices;
	return ret;
}

ShapeData ShapeGenerator::makeWireframePlane(uint dimensions)
{
	ShapeData ret;
	if (dimensions % 2 == 0)
		dimensions++;
	ret.numVertices = dimensions * 2 * 2; // 2 verts per line, 2 dimensions
	const int HALF = dimensions / 2;
	ret.vertices = new VertexPCNUT[ret.numVertices];
	int runner = 0;
	glm::vec4 white(1.0f, 1.0f, 1.0f, 1.0f);
	for (int i = 0; i < ret.numVertices; i += 4, runner++)
	{
		// Set up criss cross line endpoints
		VertexPCNUT& v1 = ret.vertices[i + 0];
		v1.position.x = -HALF;
		v1.position.y = 0;
		v1.position.z = HALF + -runner;
		v1.color = white;

		VertexPCNUT& v2 = ret.vertices[i + 1];
		v2.position.x = HALF;
		v2.position.y = 0;
		v2.position.z = HALF + -runner;
		v2.color = white;

		VertexPCNUT& v3 = ret.vertices[i + 2];
		v3.position.x = -HALF + runner;
		v3.position.y = 0;
		v3.position.z = HALF;
		v3.color = white;

		VertexPCNUT& v4 = ret.vertices[i + 3];
		v4.position.x = -HALF + runner;
		v4.position.y = 0;
		v4.position.z = -HALF;
		v4.color = white;
	}
	ret.numIndices = (dimensions + dimensions) * 2;
	ret.indices = new GLushort[ret.numIndices];
	for (uint i = 0; i < ret.numIndices; i++)
		ret.indices[i] = i;
	return ret;
}
