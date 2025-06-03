// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceNode.generated.h"

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	Ferramite_Ore   UMETA(DisplayName = "Ferramite Ore"),
	Bauxite		    UMETA(DisplayName = "Bauxite"),
	Silica_Dust     UMETA(DisplayName = "Silica Dust"),
	SacredSlurry    UMETA(DisplayName = "Sacred Slurry"),
	Promethium_Gas  UMETA(DisplayName = "Promethium Gas"),
	Crude_Oil	    UMETA(DisplayName = "Crude Oil"),
	Organic_Matter  UMETA(DisplayName = "Organic Matter")
};

UCLASS()
class FORGEWORLD_M30_API AResourceNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResourceNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 🔷 Resource Type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	EResourceType ResourceType;

	// 🔷 Total amount originally in node
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	float TotalAmount;

	// 🔷 Current remaining amount
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	float CurrentAmount;

	// 🔷 Extraction rate per second (baseline)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	float ExtractionRate;

	// 🔷 Mesh for visual representation (optional but recommended)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
	UStaticMeshComponent* Mesh;
};
