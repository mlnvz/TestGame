
#include "Actors/PlayerBasket.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/Chicken.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

APlayerBasket::APlayerBasket()
{
    PrimaryActorTick.bCanEverTick = false;

    MoveSpeed = 500.0f; // Скорость перемещения корзинки

    // Создаем корневой компонент сцены
    RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
    RootComponent = RootSceneComponent;  // Назначаем его корневым компонентом


    // Создаем StaticMesh компонент для корзинки
    BasketMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BasketMesh"));
    BasketMesh->SetupAttachment(RootComponent);  // Делаем BasketMesh дочерним компонентом RootSceneComponent

}

void APlayerBasket::BeginPlay()
{
    Super::BeginPlay();

    // Получаем ссылку на PlayerController
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    
}


void APlayerBasket::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Привязываем оси
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerBasket::MoveRight);
    PlayerInputComponent->BindAxis("MoveLeft", this, &APlayerBasket::MoveLeft);
    // Привязка нажатия левой кнопки мыши
    PlayerInputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &APlayerBasket::OnLeftMouseClick);

}


void APlayerBasket::MoveRight(float Value)
{
    MoveBasket(FVector(1.0f, 0.0f, 0.0f), Value);
}

void APlayerBasket::MoveLeft(float Value)
{
    MoveBasket(FVector(-1.0f, 0.0f, 0.0f), Value);
}


void APlayerBasket::MoveBasket(const FVector& Direction, float Value)
{
    if (InputEnabled() && Value != 0.0f)
    {
        FHitResult HitResult;

        // Перемещаем компонент с проверкой коллизий
        BasketMesh->MoveComponent(Direction * Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), GetActorRotation(), true, &HitResult);
    }
}


void APlayerBasket::OnLeftMouseClick()
{
    FHitResult HitResult;
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    if (PlayerController)
    {
        bool bHit = PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
        if (bHit && HitResult.GetActor())
        {

            if (HitResult.GetActor()->IsA(AChicken::StaticClass()))
            {
                AChicken* Chicken = Cast<AChicken>(HitResult.GetActor());
                if (Chicken)
                {
                    Chicken->SpawnEgg(); // Спавн яйца
                }
            }
        }
    }
}