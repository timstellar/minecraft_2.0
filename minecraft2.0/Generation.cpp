#include "Generation.h"

#define IS_IN(X,Y,Z)((X) >= 0 && (X) < CHUNK_W && (Y) >= 0 && (Y) < CHUNK_H && (Z) >= 0 && (Z) < CHUNK_D)
#define VOXEL(X,Y,Z)(this->voxel[((Y) * CHUNK_W + (X)) * CHUNK_D + (Z)])
#define IS_BLOCKED(X,Y,Z)((IS_IN(X, Y, Z)) && VOXEL(X, Y, Z).id)
#define VERTEX(INDEX, X, Y, Z, TX, TY) this->vertArr[INDEX] = (X); this->vertArr[INDEX + 1] = (Y); this->vertArr[INDEX + 2] = (Z); this->vertArr[INDEX + 3] = (TX); this->vertArr[INDEX + 4] = (TY); INDEX += 5;

Generation::Generation()
{
	vertArr = new float[1024 * 1024 * 180]{};
	index = 0;
}

void Generation::render()
{
	

	for (int z{}; z < CHUNK_D; z++)
		for (int x{}; x < CHUNK_W; x++)
		{
			float height = glm::perlin(glm::vec3(x * 0.05, z * 0.05, 0.0f));
			for (int y{}; y < CHUNK_H; y++)
			{
				if (y <= height * 10 + 6)
				{
					if (y == 1)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 13;
					if (y == 2)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 12;
					if (y == 3)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 11;
					if (y == 4)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 9;
					if (y == 5)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 8;
					if (y == 6)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 7;
					if (y == 7)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 6;
					if (y == 8)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 4;
					if (y == 9)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 3;
					if (y == 10)
						voxel[(y * CHUNK_W + x) * CHUNK_D + z].id = 2;
				}
			}
		}
	for (int y{}; y < CHUNK_H; y++)
		for (int x{}; x < CHUNK_W; x++)
			for (int z{}; z < CHUNK_D; z++)
			{
				unsigned int id = this->voxel[((y)*CHUNK_W + (x)) * CHUNK_D + (z)].id;


				if (!id)
					continue;

				id--;
				if ((id >= 1 && id <= 3) || (id >= 5 && id <= 8) || (id >= 10 && id <= 15 ) || id == 17 || id == 18)
				{
					unsigned int pos{};
					float uvsizeX = 1.0f / 16.0f;
					float uvsizeY = 1.0f / 57.0f;
					switch (id)
					{
						case 1:
							pos = 1;
							break;
						case 2:
							pos = 4;
							break;
						case 3:
							pos = 7;
							break;
						case 5:
							pos = 16;
							break;
						case 6:
							pos = 17;
							break;
						case 7:
							pos = 18;
							break;
						case 8:
							pos = 19;
							break;
						case 10:
							pos = 22;
							break;
						case 11:
							pos = 23;
							break;
						case 12:
							pos = 24;
							break;
						case 13:
							pos = 32;
							break;
						case 14:
							pos = 33;
							break;
						case 15:
							pos = 34;
							break;
						case 17:
							pos = 36;
							break;
						case 18:
							pos = 37;
							break;
					}
					float u = (pos % 16) * uvsizeX;
					float v = (pos / 16) * uvsizeY;
					drawBlock(x, y, z, u, v, uvsizeX, uvsizeY, u, v, u, v, u, v, u, v, u, v);
				}
			}
	index /= 5;
}

void Generation::drawBlock(int x, int y, int z, float u1, float v1, float uvsizeX, float uvsizeY, float u2, float v2, float u3, float v3, float u4, float v4, float u5, float v5, float u6, float v6)
{
	float size = 0.5f;

	if (!IS_BLOCKED(x, y + 1, z)) //t
	{
		VERTEX(this->index, x - size, y + size, z - size, u1 + uvsizeX, v1 + uvsizeY);
		VERTEX(this->index, x - size, y + size, z + size, u1 + uvsizeX, v1);
		VERTEX(this->index, x + size, y + size, z + size, u1, v1);

		VERTEX(this->index, x - size, y + size, z - size, u1 + uvsizeX, v1 + uvsizeY);
		VERTEX(this->index, x + size, y + size, z - size, u1, v1 + uvsizeY);
		VERTEX(this->index, x + size, y + size, z + size, u1, v1);
	}
	if (!IS_BLOCKED(x, y - 1, z)) //b
	{
		VERTEX(this->index, x - size, y - size, z - size, u2 + uvsizeX, v2 + uvsizeY);
		VERTEX(this->index, x - size, y - size, z + size, u2 + uvsizeX, v2);
		VERTEX(this->index, x + size, y - size, z + size, u2, v2);

		VERTEX(this->index, x - size, y - size, z - size, u2 + uvsizeX, v2 + uvsizeY);
		VERTEX(this->index, x + size, y - size, z - size, u2, v2 + uvsizeY);
		VERTEX(this->index, x + size, y - size, z + size, u2, v2);
	}
	if (!IS_BLOCKED(x + 1, y, z)) //r
	{
		VERTEX(this->index, x + size, y - size, z - size, u3 + uvsizeX, v3 + uvsizeY);
		VERTEX(this->index, x + size, y + size, z - size, u3 + uvsizeX, v3);
		VERTEX(this->index, x + size, y + size, z + size, u3, v3);

		VERTEX(this->index, x + size, y - size, z - size, u3 + uvsizeX, v3 + uvsizeY);
		VERTEX(this->index, x + size, y - size, z + size, u3, v3 + uvsizeY);
		VERTEX(this->index, x + size, y + size, z + size, u3, v3);
	}
	if (!IS_BLOCKED(x - 1, y, z)) //l
	{
		VERTEX(this->index, x - size, y - size, z - size, u4, v4 + uvsizeY);
		VERTEX(this->index, x - size, y + size, z - size, u4, v4);
		VERTEX(this->index, x - size, y + size, z + size, u4 + uvsizeX, v4);

		VERTEX(this->index, x - size, y - size, z - size, u4, v4 + uvsizeY);
		VERTEX(this->index, x - size, y - size, z + size, u4 + uvsizeX, v4 + uvsizeY);
		VERTEX(this->index, x - size, y + size, z + size, u4 + uvsizeX, v4);
	}
	if (!IS_BLOCKED(x, y, z + 1)) //f
	{
		VERTEX(this->index, x + size, y + size, z + size, u5 + uvsizeX, v5);
		VERTEX(this->index, x - size, y + size, z + size, u5, v5);
		VERTEX(this->index, x - size, y - size, z + size, u5, v5 + uvsizeY);

		VERTEX(this->index, x + size, y + size, z + size, u5 + uvsizeX, v5);
		VERTEX(this->index, x + size, y - size, z + size, u5 + uvsizeX, v5 + uvsizeY);
		VERTEX(this->index, x - size, y - size, z + size, u5, v5 + uvsizeY);
	}
	if (!IS_BLOCKED(x, y, z - 1)) //b
	{
		VERTEX(this->index, x - size, y - size, z - size, u6 + uvsizeX, v6 + uvsizeY);
		VERTEX(this->index, x - size, y + size, z - size, u6 + uvsizeX, v6);
		VERTEX(this->index, x + size, y + size, z - size, u6, v6);

		VERTEX(this->index, x - size, y - size, z - size, u6 + uvsizeX, v6 + uvsizeY);
		VERTEX(this->index, x + size, y - size, z - size, u6, v6 + uvsizeY);
		VERTEX(this->index, x + size, y + size, z - size, u6, v6);
	}
}
