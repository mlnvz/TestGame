
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chicken.generated.h"

class AEgg; // ��������������� ���������� ������


UCLASS()
class PROJ_API AChicken : public AActor
{
    GENERATED_BODY()

public:
    AChicken();

protected:
    virtual void BeginPlay() override;

public:

    // ������� ��� �������� ����
    void SpawnEgg();

    UFUNCTION()
    void OnEggDestroyed(AActor* DestroyedActor);


private:

    // ����� ����
    UPROPERTY(EditAnywhere, Category = "Egg")
    TSubclassOf<class AEgg> EggClass;

    bool bHasEgg; // ����, ����������� �� ������� ��������� ����

    APlayerController* PlayerController; // �������� ��������� �� PlayerController

};