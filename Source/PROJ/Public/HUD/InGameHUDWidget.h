#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameHUDWidget.generated.h"

UCLASS()
class PROJ_API UInGameHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateScore(int32 Score);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateLives(int32 Lives);

protected:
    // �������� ����������, ����������� � Blueprint
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    // ������ �� ����������� �������� (����������� ����� Blueprint)
    UPROPERTY(meta = (BindWidgetOptional))
    class UImage* Heart1;

    UPROPERTY(meta = (BindWidgetOptional))
    class UImage* Heart2;

    UPROPERTY(meta = (BindWidgetOptional))
    class UImage* Heart3;

};