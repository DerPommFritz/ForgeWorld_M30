#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceNode.h" // Needet to access the node
#include "Extractor.generated.h"

// connects to ResourceNode
class AResourceNode;

UCLASS()
class FORGEWORLD_M30_API AExtractor : public AActor
{
    GENERATED_BODY()

public:
    AExtractor();

    virtual void Tick(float DeltaTime) override;

    // The resource node this extractor is connected to
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Connection")
    AResourceNode* ConnectedNode;

    // How often (in seconds) the extractor pulls resources 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction")
    float ExtractionInterval;

    // Extraction rate in unit per second
    UPROPERTY(EditAnywhere)
    float ExtractionRate;

    // Internal Storage
    UPROPERTY(VisibleAnywhere)
    TMap<EResourceType, int32> StoredResources;

    // Internal timer to keep track of extraction time
    float TimeSinceLastExtraction;

    // How much to extract each cycle
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction")
    int32 ExtractionAmount;

    // Performs the actual resource extraction
    void PerformExtraction();

    // Connect this Extractor to a Resource Node
    UFUNCTION(BlueprintCallable, Category = "Extractor")
    void ConnectToNode(AResourceNode* Node);


protected:
    virtual void BeginPlay() override;

private:
    float ExtractionAccumulator;
};