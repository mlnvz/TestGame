// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/PlayerBasket.h" 
#include "Egg.generated.h"


class AMainGameMode;

UCLASS()
class PROJ_API AEgg : public AActor
{
    GENERATED_BODY()

public:
    AEgg();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    AMainGameMode* CachedGameMode;
    void AddScore();
    void LoseLife();

    // Обработчик коллизии
    UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // Компонент статического меша для яйца
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* EggMesh;

    // Скорость падения яйца
    UPROPERTY(EditAnywhere, Category = "Movement")
    float FallSpeed;

public:


private:
    // Функция для проверки столкновения с корзинкой
    void CheckCollision();
    APlayerBasket* PlayerBasket; // Добавлено для хранения ссылки на корзинку
};