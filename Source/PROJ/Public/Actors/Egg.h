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

    // ���������� ��������
    UFUNCTION()
    void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // ��������� ������������ ���� ��� ����
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* EggMesh;

    // �������� ������� ����
    UPROPERTY(EditAnywhere, Category = "Movement")
    float FallSpeed;

public:


private:
    // ������� ��� �������� ������������ � ���������
    void CheckCollision();
    APlayerBasket* PlayerBasket; // ��������� ��� �������� ������ �� ��������
};