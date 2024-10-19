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
    // ������� ��� ����������� ����������
    UFUNCTION(BlueprintCallable)
    void SetGameOverData(float GameTime, int32 Score);

    // ������� ��� ����������� ����
    UFUNCTION(BlueprintCallable)
    void RestartGame();

    // ������� ��� ������ �� ����
    UFUNCTION(BlueprintCallable)
    void QuitGame();

protected:
    virtual bool Initialize() override;

private:
    // �������� �������
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* GameTimeText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    UPROPERTY(meta = (BindWidget))
    class UButton* RestartButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;

    // �������-����������� ��� ������
    UFUNCTION()
    void OnRestartClicked();

    UFUNCTION()
    void OnQuitClicked();
};