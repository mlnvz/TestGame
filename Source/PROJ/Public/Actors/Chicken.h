
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chicken.generated.h"

class AEgg; // ѕредварительное объ€вление класса


UCLASS()
class PROJ_API AChicken : public AActor
{
    GENERATED_BODY()

public:
    AChicken();

protected:
    virtual void BeginPlay() override;

public:

    // ‘ункци€ дл€ создани€ €йца
    void SpawnEgg();

    UFUNCTION()
    void OnEggDestroyed(AActor* DestroyedActor);


private:

    //  ласс €йца
    UPROPERTY(EditAnywhere, Category = "Egg")
    TSubclassOf<class AEgg> EggClass;

    bool bHasEgg; // ‘лаг, указывающий на наличие активного €йца

    APlayerController* PlayerController; // ’ранение указател€ на PlayerController

};