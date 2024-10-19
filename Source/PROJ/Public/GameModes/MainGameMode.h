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

    // Функция для увеличения очков
    void AddScore();

    // Функция для уменьшения жизней
    void LoseLife();

    // Текущие очки
    int32 Score;

    // Жизни игрока
    int32 Lives;

    // Время игры
    float GameTime;

    bool bIsGameActive;

    // Максимальное количество жизней
    UPROPERTY(EditAnywhere, Category = "Game")
    int32 MaxLives;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // Добавим ссылку на HUD
    UPROPERTY()
    AGameHUD* GameHUD;
  
};