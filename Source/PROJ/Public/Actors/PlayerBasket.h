
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBasket.generated.h"


UCLASS()
class PROJ_API APlayerBasket : public APawn
{
    GENERATED_BODY()

public:
    APlayerBasket();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // �������� ����������� ��������
    UPROPERTY(EditAnywhere, Category = "Movement")
    float MoveSpeed;

    // �������� ���������, �� �������� �� BasketMesh
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* RootSceneComponent;

    // ��������� StaticMesh ��� ��������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* BasketMesh;

public:
    // ������� ��� ����������� ��������
    void MoveRight(float Value);
    void MoveLeft(float Value);
    void MoveBasket(const FVector& Direction, float Value);

    // ��������� ������� ����� ������ ����
    void OnLeftMouseClick();
};
