
#include "Actors/Egg.h"
#include "Actors/PlayerBasket.h"
#include "Kismet/GameplayStatics.h"
#include "GameModes/MainGameMode.h"
#include "Components/StaticMeshComponent.h"

AEgg::AEgg()
{
    PrimaryActorTick.bCanEverTick = true;
    FallSpeed = 300.0f; // Скорость падения яйца

    // Создаем компонент статического меша
    EggMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EggMesh"));
    RootComponent = EggMesh;  // Привязываем меш к корню актора
}

void AEgg::BeginPlay()
{
    Super::BeginPlay();

    // Получаем GameMode и приводим к AMainGameMode
    AGameModeBase* GameModeBase = UGameplayStatics::GetGameMode(GetWorld());
    CachedGameMode = Cast<AMainGameMode>(GameModeBase);  // Cast к вашему AMainGameMode

    // Подписываемся на событие пересечения
    EggMesh->OnComponentBeginOverlap.AddDynamic(this, &AEgg::OnOverlap);

    // Сохраняем ссылку на PlayerBasket
    PlayerBasket = Cast<APlayerBasket>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

}


void AEgg::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Падаем вниз
    FVector NewLocation = GetActorLocation();
    NewLocation.Z -= FallSpeed * DeltaTime;
    SetActorLocation(NewLocation);

    // Проверяем, не упало ли яйцо ниже уровня земли (например, Z < 0)
    if (NewLocation.Z < 0.0f)  
    {
        if (CachedGameMode)
        {
            CachedGameMode->LoseLife();  // Потеря жизни
        }

        Destroy();  // Уничтожаем яйцо
    }

}

void AEgg::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->IsA(APlayerBasket::StaticClass()))
    {
        CachedGameMode->AddScore();

        Destroy();  // Уничтожаем яйцо при пересечении с корзинкой
    }
}