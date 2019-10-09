#pragma once

#include "Rsm.h"


class Rsm2 : public IRsm
{
public:
	class Mesh : public IMesh
	{
	public:
		std::vector<int> textures;
	};
	class Face : public IRsm::Face
	{
	public:
	};

	Rsm2(const std::string& fileName);

	void load0202(blib::util::StreamInFile* rsmFile);
	void load0203(blib::util::StreamInFile* rsmFile);

	std::string readString(blib::util::StreamInFile* file);
	int animationLength;
	int shadeType;
	unsigned char alpha;
	float unknown;
};