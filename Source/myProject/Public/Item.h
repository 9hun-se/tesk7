// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"




UCLASS()
class MYPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure,Category="Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUP();
};


//생성자 - 메모리에 생김. 딱한번 호출.
//PostinitializeComponents()-컴포넌트가 완성된 직후 호출. 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPlay()-배치 spawn직후
//Tick(float DeltaTime)-매프레임마다 호출됨
//Destroyedd()- 삭제되기 직전에 호출된다.
//EndPlay()-게임종료,

//D를 부르면 E도 호출됨 반대는 일어나지 않음
//헤더 "Item.generated.h" 항상 마지막에 와야됨
//UCLASS의 기본 인자(Blureprintable,BlueprintType)