#include "Extractor.h"
#include "ResourceNode.h" // Required to talk to the node

AExtractor::AExtractor()
{
    PrimaryActorTick.bCanEverTick = true;

    ExtractionInterval = 5.0f; // Every 5 seconds
    ExtractionAmount = 10;
    TimeSinceLastExtraction = 0.0f;
}

void AExtractor::BeginPlay()
{
    Super::BeginPlay();
}

void AExtractor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (ConnectedNode)
    {
        TimeSinceLastExtraction += DeltaTime;

        if (TimeSinceLastExtraction >= ExtractionInterval)
        {
            PerformExtraction();
            TimeSinceLastExtraction = 0.0f;
        }
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