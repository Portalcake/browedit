#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <string>
#include <vector>
#include <string>
#include <map>

namespace blib
{
	class Texture;
	namespace util { class StreamInFile; }
}

class Rsm
{
private:
	class Mesh
	{
	public:
		class Face
		{
		public:
			int							vertices[3];
			int							texvertices[3];
			glm::vec3					normal;
			int							texIndex;
			int							twoSide;
			int							smoothGroup;
		};

		class Frame
		{
		public:
			int							time;
			glm::quat					quaternion;
		};


		Mesh(Rsm* model, blib::util::StreamInFile* rsmFile);

		std::string						name;
		std::string						parentName;
		int								unknown1;
		float							unknown2;

		glm::mat4						offset;
		glm::vec3						pos_;
		glm::vec3						pos;
		float							rotangle;
		glm::vec3						rotaxis;
		glm::vec3						scale;

		std::vector<blib::Texture*>			textures;
		std::vector<glm::vec3>			vertices;
		std::vector<glm::vec2>			texCoords;
		std::vector<Face*>				faces;
		std::vector<Frame*>				frames;

		Mesh* parent;
		Rsm* model;
		std::vector<Mesh*> children;
		glm::vec3 bbmin;
		glm::vec3 bbmax;
		glm::vec3 bbrange;

		glm::mat4 matrix1;
		glm::mat4 matrix2;
		void calcMatrix1();
		void calcMatrix2();

		void setBoundingBox( glm::vec3& bbmin, glm::vec3& bbmax );
		void setBoundingBox2( glm::mat4& mat, glm::vec3& realbbmin, glm::vec3& realbbmax );
		void fetchChildren( std::map<std::string, Mesh* > meshes );
	};

public:
	Rsm(std::string fileName);
	~Rsm();

	bool loaded;

	short version;
	int animLen;
	std::string fileName;
	std::vector<std::string> textures;

	glm::vec3 realbbmin;
	glm::vec3 realbbmax;
	glm::vec3 realbbrange;

	glm::vec3 bbmin;
	glm::vec3 bbmax;
	glm::vec3 bbrange;

	float maxRange;

	Mesh* rootMesh;

	enum eShadeType
	{
		SHADE_NO,
		SHADE_FLAT,
		SHADE_SMOOTH,
		SHADE_BLACK,
	}								shadeType;

	char							unknown[16];
	char							alpha;
};
