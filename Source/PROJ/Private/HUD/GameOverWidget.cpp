// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/GameOverWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

bool UGameOverWidget::Initialize()
{
    Super::Initialize();

    // Привязка функций к кнопкам
    if (RestartButton)
    {
        RestartButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnRestartClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnQuitClicked);
    }

    return true;
}

void UGameOverWidget::SetGameOverData(float GameTime, int32 Score)
{
    // Обновляем текстовые поля результатами
    if (GameTimeText)
    {
        GameTimeText->SetText(FText::AsNumber(GameTime));
    }

    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(Score));
    }
}

void UGameOverWidget::OnRestartClicked()
{
    RestartGame();
}

void UGameOverWidget::OnQuitClicked()
{
    QuitGame();
}

void UGameOverWidget::RestartGame()
{
    // Перезагружаем текущий уровень
    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UGameOverWidget::QuitGame()
{
    // Завершение игры
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}