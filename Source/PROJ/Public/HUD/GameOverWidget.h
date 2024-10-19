// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

UCLASS()
class PROJ_API UGameOverWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Функции для отображения результата
    UFUNCTION(BlueprintCallable)
    void SetGameOverData(float GameTime, int32 Score);

    // Функция для перезапуска игры
    UFUNCTION(BlueprintCallable)
    void RestartGame();

    // Функция для выхода из игры
    UFUNCTION(BlueprintCallable)
    void QuitGame();

protected:
    virtual bool Initialize() override;

private:
    // Элементы виджета
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* GameTimeText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    UPROPERTY(meta = (BindWidget))
    class UButton* RestartButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;

    // Функции-обработчики для кнопок
    UFUNCTION()
    void OnRestartClicked();

    UFUNCTION()
    void OnQuitClicked();
};