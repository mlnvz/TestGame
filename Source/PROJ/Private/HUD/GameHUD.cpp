// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/GameHUD.h"
#include "HUD/InGameHUDWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "TimerManager.h"

void AGameHUD::BeginPlay()
{
    Super::BeginPlay();

    // Проверка и создание игрового HUD
    if (InGameHUDWidgetClass)
    {
        // Создаем и отображаем виджет меню проигрыша
        InGameHUDWidget = CreateWidget<UInGameHUDWidget>(GetWorld(), InGameHUDWidgetClass);
        if (InGameHUDWidget)
        {
            InGameHUDWidget->AddToViewport();
            InGameHUDWidget->UpdateScore(0);
        }
    }
   
}

void AGameHUD::UpdateScore(int32 Score)
{
    if (InGameHUDWidget)
    {
        InGameHUDWidget->UpdateScore(Score);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("InGameHUDWidget is not initialized"));
    }
}

void AGameHUD::UpdateLives(int32 Lives)
{
    if (InGameHUDWidget)
    {
        InGameHUDWidget->UpdateLives(Lives);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("InGameHUDWidget is not initialized"));
    }
}


void AGameHUD::ShowGameOverMenu(float GameTime, int32 Score)
{
    if (GameOverWidgetClass)
    {
        // Создаем и отображаем виджет меню проигрыша
        UGameOverWidget* GameOverWidget = CreateWidget<UGameOverWidget>(GetWorld(), GameOverWidgetClass);
        if (GameOverWidget)
        {
            GameOverWidget->AddToViewport();
            GameOverWidget->SetGameOverData(GameTime, Score);
        }
    }
}
