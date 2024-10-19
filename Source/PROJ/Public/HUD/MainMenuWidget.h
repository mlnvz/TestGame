// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

UCLASS()
class PROJ_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Функция для начала новой игры
    UFUNCTION(BlueprintCallable)
    void StartNewGame();

    // Функция для выхода из игры
    UFUNCTION(BlueprintCallable)
    void QuitGame();

protected:
    virtual bool Initialize() override;

private:
    // Указатели на кнопки
    UPROPERTY(meta = (BindWidget))
    class UButton* NewGameButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;

    // Функции-обработчики нажатия кнопок
    UFUNCTION()
    void OnNewGameClicked();

    UFUNCTION()
    void OnQuitClicked();
};
