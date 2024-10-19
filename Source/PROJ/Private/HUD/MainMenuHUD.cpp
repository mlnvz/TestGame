// Fill out your copyright notice in the Description page of Project Settings.
#include "HUD/MainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "HUD/MainMenuWidget.h"


void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    // Убедимся, что класс виджета назначен
    if (MainMenuWidgetClass)
    {
        // Создаем виджет на основе BP_MainMenuWidget
        MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    }

}