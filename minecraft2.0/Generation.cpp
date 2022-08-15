#include "Generation.h"

#define IS_IN(X,Y,Z)((X) >= 0 && (X) < CHUNK_W && (Y) >= 0 && (Y) < CHUNK_H && (Z) >= 0 && (Z) < CHUNK_D)
#define VOXEL(X,Y,Z)(this->voxel[((Y) * CHUNK_W + (X)) * CHUNK_D + (Z)])
#define IS_BLOCKED(X,Y,Z)((IS_IN(X, Y, Z)) && VOXEL(X, Y, Z).id)
#define VERTEX(INDEX, X, Y, Z, TX, TY) this->vertArr[INDEX] = (X); this->vertArr[INDEX + 1] = (Y); this->vertArr[INDEX + 2] = (Z); this->vertArr[INDEX + 3] = (TX); this->vertArr[INDEX + 4] = (TY); INDEX += 5;

Generation::Generation()
{
	vertArr = new float[1024 * 1024 * 180]{};
	size_t index{};
}

void Generation::render()
{
	float size = 0.5f;

	for (int z{}; z < CHUNK_D; z++)
		for (int x{}; x < CHUNK_W; x++)
		{
			float height = glm::perlin(glm::vec3(x * 0.05, z * 0.05, 0.0f));
			for (int y{}; y < CHUNK_H; y++)
			{
				voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = y <= height * 10 + 5;
			}
		}
	for (int y{}; y < CHUNK_H; y++)
		for (int x{}; x < CHUNK_W; x++)
			for (int z{}; z < CHUNK_D; z++)
			{

				if (!VOXEL(x, y, z).id)
					continue;

				if (!IS_BLOCKED(x, y + 1, z)) //t
				{
					VERTEX(this->index, x - size, y + size, z - size,		0.0f, 1.0f);
					VERTEX(this->index, x - size, y + size, z + size,		0.0f, 0.0f);
					VERTEX(this->index, x + size, y + size, z + size,		1.0f, 0.0f);

					VERTEX(this->index, x - size, y + size, z - size,		0.0f, 1.0f);
					VERTEX(this->index, x + size, y + size, z - size,		1.0f, 1.0f);
					VERTEX(this->index, x + size, y + size, z + size,		1.0f, 0.0f);
				}
				if (!IS_BLOCKED(x, y - 1, z)) //b
				{
					VERTEX(this->index, x - size, y - size, z - size,		0.0f, 1.0f);
					VERTEX(this->index, x + size, y - size, z + size,		1.0f, 0.0f);
					VERTEX(this->index, x - size, y - size, z + size,		0.0f, 0.0f);

					VERTEX(this->index, x - size, y - size, z - size,		0.0f, 1.0f);
					VERTEX(this->index, x + size, y - size, z - size,		1.0f, 1.0f);
					VERTEX(this->index, x + size, y - size, z + size,		1.0f, 0.0f);
				}
				if (!IS_BLOCKED(x + 1, y, z)) //r
				{
					VERTEX(this->index, x + size, y - size, z - size,		1.0f, 0.0f);
					VERTEX(this->index, x + size, y + size, z - size,		1.0f, 1.0f);
					VERTEX(this->index, x + size, y + size, z + size,		0.0f, 1.0f);

					VERTEX(this->index, x + size, y - size, z - size,		1.0f, 0.0f);
					VERTEX(this->index, x + size, y - size, z + size,		0.0f, 0.0f);
					VERTEX(this->index, x + size, y + size, z + size,		0.0f, 1.0f);
				}
				if (!IS_BLOCKED(x - 1, y, z)) //l
				{
					VERTEX(this->index, x - size, y - size, z - size,		0.0f, 0.0f);
					VERTEX(this->index, x - size, y + size, z + size,		1.0f, 1.0f);
					VERTEX(this->index, x - size, y + size, z - size,		0.0f, 1.0f);

					VERTEX(this->index, x - size, y - size, z - size,		0.0f, 0.0f);
					VERTEX(this->index, x - size, y - size, z + size,		1.0f, 0.0f);
					VERTEX(this->index, x - size, y + size, z + size,		1.0f, 1.0f);
				}
				if (!IS_BLOCKED(x, y, z + 1)) //f
				{
					VERTEX(this->index, x + size, y + size, z + size,		1.0f, 1.0f);
					VERTEX(this->index, x - size, y + size, z + size,		0.0f, 1.0f);
					VERTEX(this->index, x - size, y - size, z + size,		0.0f, 0.0f);

					VERTEX(this->index, x + size, y + size, z + size,		1.0f, 1.0f);
					VERTEX(this->index, x + size, y - size, z + size,		1.0f, 0.0f);
					VERTEX(this->index, x - size, y - size, z + size,		0.0f, 0.0f);
				}
				if (!IS_BLOCKED(x, y, z - 1)) //b
				{
					VERTEX(this->index, x - size, y - size, z - size,		1.0f, 0.0f);
					VERTEX(this->index, x - size, y + size, z - size,		1.0f, 1.0f);
					VERTEX(this->index, x + size, y + size, z - size,		0.0f, 1.0f);

					VERTEX(this->index, x - size, y - size, z - size,		1.0f, 0.0f);
					VERTEX(this->index, x + size, y - size, z - size,		0.0f, 0.0f);
					VERTEX(this->index, x + size, y + size, z - size,		0.0f, 1.0f);
				}
				
			}
	index /= 5;
}
