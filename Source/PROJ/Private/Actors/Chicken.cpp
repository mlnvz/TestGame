
#include "Actors/Chicken.h"
#include "Actors/Egg.h"
#include "Kismet/GameplayStatics.h"

AChicken::AChicken()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AChicken::BeginPlay()
{
    Super::BeginPlay();

}


void AChicken::SpawnEgg()
{
    if (EggClass && !bHasEgg)
    {
        FVector SpawnLocation = GetActorLocation();
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        // ������� ����
        AEgg* SpawnedEgg = GetWorld()->SpawnActor<AEgg>(EggClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

        if (SpawnedEgg)
        {
            bHasEgg = true; // ������������� ���� ����� ������ ����
            SpawnedEgg->OnDestroyed.AddDynamic(this, &AChicken::OnEggDestroyed); // ������������� �� ����������� ����
        }
    }
}

void AChicken::OnEggDestroyed(AActor* DestroyedActor)
{
    bHasEgg = false; // ���������� ���� ����� ����������� ����
}
