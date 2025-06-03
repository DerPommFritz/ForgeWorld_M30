// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceNode.h"
#include "Components/StaticMeshComponent.h"

// Constructor: Called when the node is conjured into being
AResourceNode::AResourceNode()
{
 	// Enable ticking (optional unless you want dynamic depletion or interaction)
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Mesh Component and attach it as the Root
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ResourceMesh"));
	RootComponent = Mesh;

	// Set default values
	ResourceType	= EResourceType::Ferramite_Ore;
	TotalAmount		= 1000.0f;
	CurrentAmount	= TotalAmount;
	ExtractionRate	= 5.0f; // Units per second
}

// Called when the game starts or when spawned
void AResourceNode::BeginPlay()
{
	Super::BeginPlay();
	// Optional: log startup message
	UE_LOG(LogTemp, Log, TEXT("ResourceNode [%s] initialized with %.0f units"),
		*UEnum::GetValueAsString(ResourceType), TotalAmount)
	
}

// Tick: Called every frame (if enabled)
void AResourceNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Placeholder for passive depletion or logic
	// For now, extraction is handled externally

}

