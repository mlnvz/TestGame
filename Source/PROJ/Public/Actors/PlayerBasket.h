
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

    // Скорость перемещения корзинки
    UPROPERTY(EditAnywhere, Category = "Movement")
    float MoveSpeed;

    // Корневой компонент, не влияющий на BasketMesh
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* RootSceneComponent;

    // Компонент StaticMesh для корзинки
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* BasketMesh;

public:
    // Функции для перемещения корзинки
    void MoveRight(float Value);
    void MoveLeft(float Value);
    void MoveBasket(const FVector& Direction, float Value);

    // Обработка нажатия левой кнопки мыши
    void OnLeftMouseClick();
};
