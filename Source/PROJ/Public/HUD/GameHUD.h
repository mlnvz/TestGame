#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD/GameOverWidget.h"
#include "HUD/InGameHUDWidget.h"
#include "GameHUD.generated.h"

UCLASS()
class PROJ_API AGameHUD : public AHUD
{
    GENERATED_BODY()

public:

    // ��������� ���� � ����� ����� ���� HUD
    void UpdateScore(int32 Score);
    void UpdateLives(int32 Lives);

    // ����������� ���� ���������
    void ShowGameOverMenu(float GameTime, int32 Score);

protected:
    virtual void BeginPlay() override;

private:
    // ����� ������� ���� ���������
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UGameOverWidget> GameOverWidgetClass;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UInGameHUDWidget> InGameHUDWidgetClass;

    // ������ �� ��������� InGameHUDWidget
    UPROPERTY()
    UInGameHUDWidget* InGameHUDWidget;

};