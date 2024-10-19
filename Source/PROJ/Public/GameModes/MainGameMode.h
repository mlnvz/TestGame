// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

class AGameHUD;

UCLASS()
class PROJ_API AMainGameMode : public AGameMode
{
    GENERATED_BODY()

public:
    AMainGameMode();

    // ������� ��� ���������� �����
    void AddScore();

    // ������� ��� ���������� ������
    void LoseLife();

    // ������� ����
    int32 Score;

    // ����� ������
    int32 Lives;

    // ����� ����
    float GameTime;

    bool bIsGameActive;

    // ������������ ���������� ������
    UPROPERTY(EditAnywhere, Category = "Game")
    int32 MaxLives;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // ������� ������ �� HUD
    UPROPERTY()
    AGameHUD* GameHUD;
  
};