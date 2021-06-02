#include "ManyVerticesPlane.h"

AManyVerticesPlane::AManyVerticesPlane()
{
	PrimaryActorTick.bCanEverTick = true;

	pm = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	pm->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	
	width = 4;
	height = 4;
	spacing = 50.0f;

	generateMesh = false;
}

void AManyVerticesPlane::OnConstruction(const FTransform& Transform)
{
	if (generateMesh)
	{
		generateMesh = false;

		ClearMeshData();

		GenerateVertices();
		GenerateTriangles();
	
		//Function that creates mesh section
		pm->CreateMeshSection_LinearColor(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
	}
}

void AManyVerticesPlane::GenerateVertices()
{
	float uvSpacing = 1.0f / FMath::Max(height, width);

	for (int32 y = 0; y < height; y++)
	{
		for (int32 x = 0; x < width; x++)
		{
			vertices.Add(FVector(x * spacing, y * spacing, 0.0f));
			normals.Add(FVector(0.0f, 0.0f, 1.0f));
			uvs.Add(FVector2D(x * uvSpacing, y * uvSpacing));
			vertexColors.Add(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));
			tangents.Add(FProcMeshTangent(1.0f, 0.0f, 0.0f));
		}
	}
}

void AManyVerticesPlane::GenerateTriangles()
{
	for (int32 y = 0; y < height - 1; y++)
	{
		for (int32 x = 0; x < width - 1; x++)
		{
			triangles.Add(x + (y * width));					//current vertex
			triangles.Add(x + (y * width) + width);			//current vertex + row
			triangles.Add(x + (y * width) + width + 1);		//current vertex + row + one right

			triangles.Add(x + (y * width));					//current vertex
			triangles.Add(x + (y * width) + width + 1);		//current vertex + row + one right
			triangles.Add(x + (y * width) + 1);				//current vertex + one right
		}
	}
}

void AManyVerticesPlane::ClearMeshData()
{
	vertices.Empty();
	triangles.Empty();
	uvs.Empty();
	normals.Empty();
	vertexColors.Empty();
	tangents.Empty();
}