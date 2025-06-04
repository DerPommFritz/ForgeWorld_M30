#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Extractor.generated.h"

// connects to ResourceNode
class AResourceNode;

UCLASS()
class FORGEWORLD_M30_API AExtractor : public AActor
{
    GENERATED_BODY()

public:
    AExtractor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    /** The resource node this extractor is connected to */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Extraction")
    AResourceNode* ConnectedNode;

    /** How often (in seconds) the extractor pulls resources */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Extraction")
    float ExtractionInterval;

    /** Internal timer to keep track of extraction time */
    float TimeSinceLastExtraction;

    /** How much to extract each cycle */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Extraction")
    int32 ExtractionAmount;

    /** Performs the actual resource extraction */
    void PerformExtraction();
};
