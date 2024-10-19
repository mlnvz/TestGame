// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenuWidget::Initialize()
{
    Super::Initialize();

    // Привязка функций к кнопкам
    if (NewGameButton)
    {
        NewGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnNewGameClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClicked);
    }

    return true;
}

void UMainMenuWidget::OnNewGameClicked()
{
    StartNewGame();
}

void UMainMenuWidget::OnQuitClicked()
{
    QuitGame();
}

void UMainMenuWidget::StartNewGame()
{
    // Переход на уровень игры
    UGameplayStatics::OpenLevel(this, FName("GameLevel"));
}

void UMainMenuWidget::QuitGame()
{
    // Завершение игры
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
