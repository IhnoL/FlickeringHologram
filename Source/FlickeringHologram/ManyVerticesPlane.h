#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"

#include "ManyVerticesPlane.generated.h"

UCLASS()
class FLICKERINGHOLOGRAM_API AManyVerticesPlane : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "MyProceduralMesh")
	UProceduralMeshComponent* pm;

	public:	
	AManyVerticesPlane();

	UPROPERTY()
	TArray<FVector> vertices;
	UPROPERTY()
	TArray<FVector> normals;
	UPROPERTY()
	TArray<int32> triangles;
	UPROPERTY()
	TArray<FVector2D> uvs;
	UPROPERTY()
	TArray<FLinearColor> vertexColors;
	UPROPERTY()
	TArray<FProcMeshTangent> tangents;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuProceduralMesh")
	int32 height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuProceduralMesh")
	int32 width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuProceduralMesh")
	float spacing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuProceduralMesh")
	bool generateMesh;

	virtual void OnConstruction(const FTransform& Transform) override;
	
	void GenerateVertices();
	void GenerateTriangles();
	void ClearMeshData();
};