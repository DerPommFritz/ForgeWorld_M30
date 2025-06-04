#include "Extractor.h"
#include "ResourceNode.h" // Required to talk to the node

AExtractor::AExtractor()
{
    PrimaryActorTick.bCanEverTick = true;

    ExtractionRate = 5.0f; // 5 units per second
    ExtractionAccumulator = 0.0f;
}

void AExtractor::BeginPlay()
{
    Super::BeginPlay();
}

void AExtractor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!ConnectedNode)
        return
    ExtractionAccumulator += DeltaTime * ExtractionRate;

    // Only extract whole Unit
    int32 UnitsToExtract = FMath::FloorToInt(ExtractionAccumulator);
    if (UnitsToExtract > 0)
    {
        ExtractionAccumulator -= UnitsToExtract;

        // Get resource type from node
        EResourceType ResourceType = ConnectedNode->GetResourceType();

        // Add to internal storage
        if (StoredResources.Contains(ResourceType))
        {
            StoredResources[ResourceType] += UnitsToExtract;
        }
        else
        {
            StoredResources.Add(ResourceType, UnitsToExtract);
        }

        // No depletion logic here
    }
}

void AExtractor::PerformExtraction()
{
    if (ConnectedNode)
    {
        // This assumes your ResourceNode has a ConsumeResource function
        ConnectedNode->ConsumeResource(ExtractionAmount);
        UE_LOG(LogTemp, Log, TEXT("Extracted %d units from node."), ExtractionAmount);
    }
}