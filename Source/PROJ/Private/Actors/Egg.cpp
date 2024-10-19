
#include "Actors/Egg.h"
#include "Actors/PlayerBasket.h"
#include "Kismet/GameplayStatics.h"
#include "GameModes/MainGameMode.h"
#include "Components/StaticMeshComponent.h"

AEgg::AEgg()
{
    PrimaryActorTick.bCanEverTick = true;
    FallSpeed = 300.0f; // �������� ������� ����

    // ������� ��������� ������������ ����
    EggMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EggMesh"));
    RootComponent = EggMesh;  // ����������� ��� � ����� ������
}

void AEgg::BeginPlay()
{
    Super::BeginPlay();

    // �������� GameMode � �������� � AMainGameMode
    AGameModeBase* GameModeBase = UGameplayStatics::GetGameMode(GetWorld());
    CachedGameMode = Cast<AMainGameMode>(GameModeBase);  // Cast � ������ AMainGameMode

    // ������������� �� ������� �����������
    EggMesh->OnComponentBeginOverlap.AddDynamic(this, &AEgg::OnOverlap);

    // ��������� ������ �� PlayerBasket
    PlayerBasket = Cast<APlayerBasket>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

}


void AEgg::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ������ ����
    FVector NewLocation = GetActorLocation();
    NewLocation.Z -= FallSpeed * DeltaTime;
    SetActorLocation(NewLocation);

    // ���������, �� ����� �� ���� ���� ������ ����� (��������, Z < 0)
    if (NewLocation.Z < 0.0f)  
    {
        if (CachedGameMode)
        {
            CachedGameMode->LoseLife();  // ������ �����
        }

        Destroy();  // ���������� ����
    }

}

void AEgg::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->IsA(APlayerBasket::StaticClass()))
    {
        CachedGameMode->AddScore();

        Destroy();  // ���������� ���� ��� ����������� � ���������
    }
}