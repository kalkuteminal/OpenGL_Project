#pragma once
#include <Primitives\ShapeData.h>
typedef unsigned int uint;

class __declspec(dllexport) ShapeGenerator
{
public:
	// Makes a line from (-1, 0, 0) to (1, 0, 0)
	// Must render with GL_LINES
	// Render GL_TRIANGLES
	static ShapeData makePlane(uint dimensions = 1);
	// Render GL_LINES
	static ShapeData makeWireframePlane(uint dimensions = 1);
	static ShapeData makeCube();
private:
	//static ShapeData copyToShapeData(
	//	VertexPCNUT* verts, size_t numVerts,
	//	ushort* indices, uint numIndices);
//	static void makeTeapot(
//		unsigned int grid, const glm::mat4& lidTransform,
//		unsigned int& numVerts,
//		float*& verts,
//		float*& normals,
//		float*& textureCoordinates,
//		unsigned short*& indices,
//		unsigned int& numIndices);

	static ShapeData makePlaneVerts(uint tesselation);
	static ShapeData makePlaneIndices(uint tesselation);
	static ShapeData makePlaneUnseamedIndices(uint tesselation);
};

