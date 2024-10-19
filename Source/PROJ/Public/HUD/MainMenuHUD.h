// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

UCLASS()
class PROJ_API AMainMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:
    // Переменная для хранения ссылки на класс виджета
    UPROPERTY(EditAnywhere, Category = "Widgets")
    TSubclassOf<class UMainMenuWidget> MainMenuWidgetClass;

    // Указатель на сам виджет
    UMainMenuWidget* MainMenuWidget;
};