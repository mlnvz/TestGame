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
    // ������� ��� ������ ����� ����
    UFUNCTION(BlueprintCallable)
    void StartNewGame();

    // ������� ��� ������ �� ����
    UFUNCTION(BlueprintCallable)
    void QuitGame();

protected:
    virtual bool Initialize() override;

private:
    // ��������� �� ������
    UPROPERTY(meta = (BindWidget))
    class UButton* NewGameButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;

    // �������-����������� ������� ������
    UFUNCTION()
    void OnNewGameClicked();

    UFUNCTION()
    void OnQuitClicked();
};
