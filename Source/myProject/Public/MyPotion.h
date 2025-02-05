// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPotion.generated.h"

UCLASS()
class MYPROJECT_API AMyPotion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPotion();

	UPROPERTY(VisibleAnywhere, Category = MyValue)
	FVector currentLocation;
	UPROPERTY(VisibleAnywhere, Category = MyValue)
	FVector MaxLocation;
	UPROPERTY(EditAnywhere, Category = MyValue)
	FVector moveSpeed;

	void Move(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyPotion|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyPotion|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyPotion|Properties")
	float RotationSpeed;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "MyPotion|Actions")
	void ResetActorPosition();

	// 블루프린트에서 값만 반환하도록 설정
	UFUNCTION(BlueprintPure, Category = "MyPotion|Properties")
	float GetRotationSpeed() const;

	// C++에서 호출되지만 구현은 블루프린트에서 수행
	UFUNCTION(BlueprintImplementableEvent, Category = "MyPotion|Event")
	void OnItemPickedUp();

};
